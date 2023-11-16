#include "apartamento.hpp"
#include "evento.hpp"
#include "encomendas.hpp"

#include <iostream>
#include <string>

using namespace std;

int main() {

// CONSTRUTORES =======================================================================================================================

    int max_Moradores, max_Visitantes, max_Pets, max_Veiculos;

    cout << "Informe o número máximo de moradores: ";
    cin >> max_Moradores;

    cout << "Informe o número máximo de visitantes: ";
    cin >> max_Visitantes;

    cout << "Informe o número máximo de pets: ";
    cin >> max_Pets;

    cout << "Informe o número máximo de veículos: ";
    cin >> max_Veiculos;

    // Map que armazena os apartamentos com o número de cada
    map<int, Apartamento> aps; 
    int num_ap = 0;

// PAINEL INICIAL ====================================================================================================================

    while (true){
        cout << "Escolha uma opção:\n";
        cout << "1. Modificar Apartamentos\n";
        cout << "2. Modificar Eventos\n";
        cout << "3. Modificar Encomendas\n";
        cout << "4. Encerrar programa\n";
        int opcao;
        cin >> opcao;


        // Permite o gerenciamento dos Apartamentos
        if (opcao == 1){
            Apartamento apartamento(max_Moradores, max_Visitantes, max_Pets, max_Veiculos);
            cout << "Informe o número do apartamento: \n";
            cin >> num_ap;
            if (!aps.contains(num_ap)){
                Apartamento novoApartamento(max_Moradores, max_Visitantes, max_Pets, max_Veiculos);
                aps[num_ap] = novoApartamento;
            }
            if (num_ap <= 0){
                cout << "Digite um numero de apartamento válido\n";
            }
        
    // MENU DE OPÇÕES APARTAMENTOS ====================================================================================================
            while (true){
                cout << "Escolha uma execução\n";
                cout << "1. Inserir\n";
                cout << "2. Editar\n";
                cout << "3. Excluir\n";
                cout << "4. Exibir Estatísiticas\n";
                cout << "5. Voltar\n";

                int execucao;
                cin >> execucao;

                if (execucao == 1){
                while (true) {
                    cout << "Escolha uma ação:\n";
                    cout << "1. Inserir Pessoa\n";
                    cout << "2. Inserir Pet\n";
                    cout << "3. Inserir Veículo\n";
                    cout << "4. Voltar\n";

                    int escolha;
                    cin >> escolha;

                    // Inserir pessoa
                    if (escolha == 1) {
                        string nome, data_nascimento, tipo_pessoa;
                        cout << "Nome: ";
                        cin.ignore(); 
                        getline(cin, nome);
                        cout << "Data de Nascimento: ";
                        cin >> data_nascimento;
                        cout << "Tipo de Pessoa (moradora ou visitante): ";
                        cin.ignore();
                        cin >> tipo_pessoa;
                        aps[num_ap].inserir_pessoa(nome, data_nascimento, tipo_pessoa);

                    // Inserir pet
                    } else if (escolha == 2) {
                        string nome, raca, tipo;
                        cout << "Nome do Pet: ";
                        cin.ignore(); 
                        getline(cin, nome);
                        cout << "Raça do Pet: ";
                        cin >> raca;
                        cout << "Tipo de Pet (cachorro, gato, passaro ou outro): ";
                        cin >> tipo;
                        aps[num_ap].inserir_pet(nome, raca, tipo);

                    // Inserir veículo
                    } else if (escolha == 3) {
                        string modelo, placa, tipo_veiculo;
                        cout << "Modelo do Veículo: ";
                        cin.ignore(); 
                        getline(cin, modelo);
                        cout << "Placa do Veículo: ";
                        cin >> placa;
                        cout << "Tipo de Veículo: ";
                        cin.ignore(); 
                        getline(cin, tipo_veiculo);
                        aps[num_ap].inserir_veiculo(modelo, placa, tipo_veiculo);
                    
                    // Encerra essa parte do programa
                    } else if (escolha == 4) {
                        break; 
                    }
                }
                }
                if (execucao == 2){
                while (true) {
                    cout << "Escolha uma ação:\n";
                    cout << "1. Editar Pessoa\n";
                    cout << "2. Editar Pet\n";
                    cout << "3. Editar Veículo\n";
                    cout << "4. Voltar\n";

                    int escolha;
                    cin >> escolha;
                    if (escolha == 1){
                        string nome_antigo, data_nascimento_antiga, tipo_pessoa_antigo, nome_novo, data_nascimento_nova, tipo_pessoa_novo;
                        cout << "Informe os dados antigos\n";
                        cout << "Nome: \n";
                        cin >> nome_antigo;
                        cout << "Data de Nascimento: \n";
                        cin >> data_nascimento_antiga;
                        cout << "Tipo: \n";
                        cin >> tipo_pessoa_antigo;
                        cout << "Informe os dados novos\n";
                        cout << "Nome: \n";
                        cin >> nome_novo;
                        cout << "Data de Nascimento: \n";
                        cin >> data_nascimento_nova;
                        cout << "Tipo: \n";
                        cin >> tipo_pessoa_novo;
                        aps[num_ap].editar_pessoa (nome_antigo, data_nascimento_antiga, tipo_pessoa_antigo, nome_novo, data_nascimento_nova, tipo_pessoa_novo);
                    } else if (escolha == 2){
                    
                    } else if (escolha == 3){
                        
                    } else if (escolha == 4){
                        break;
                    }
                }
                }
                if (execucao == 3){

                    while (true) {
                    cout << "Escolha uma ação:\n";
                    cout << "1. Excluir Pessoa\n";
                    cout << "2. Excluir Pet\n";
                    cout << "3. Excluir Veículo\n";
                    cout << "4. Voltar\n";

                    int escolha;
                    cin >> escolha;

                    // Excluir pessoa
                    if (escolha == 1) {
                        string nome, data_nascimento, tipo_pessoa;
                        cout << "Nome: ";
                        cin.ignore(); 
                        getline(cin, nome);
                        cout << "Data de Nascimento: ";
                        cin >> data_nascimento;
                        cout << "Tipo de Pessoa (moradora ou visitante): ";
                        cin.ignore();
                        cin >> tipo_pessoa;
                        aps[num_ap].excluir_pessoa(nome, data_nascimento, tipo_pessoa);

                    // Excluir pet
                    } else if (escolha == 2) {
                        string nome, raca, tipo;
                        cout << "Nome do Pet: ";
                        cin.ignore(); 
                        getline(cin, nome);
                        cout << "Raça do Pet: ";
                        cin >> raca;
                        cout << "Tipo de Pet (cachorro, gato, passaro ou outro): ";
                        cin >> tipo;
                        aps[num_ap].excluir_pet(nome, raca, tipo);

                    // Excluir veículo
                    } else if (escolha == 3) {
                        string placa;
                        cout << "Placa do Veículo: ";
                        cin >> placa;
                        aps[num_ap].excluir_veiculo(placa);
                    
                    // Encerra essa parte do programa
                    } else if (escolha == 4) {
                        break; 
                    }
                
                }
                }
                if (execucao == 4){
                    aps[num_ap].exibir_estatisticas();
                }
                if (execucao == 5){
                    break;
                }
            }

        }

    // MENU DE OPÇÕES DOS EVENTOS =====================================================================================================
        if (opcao == 2){

        Evento eventoManager;
        int choice;

        while (true) {
            cout << "Escolha uma ação:\n";
            cout << "1. Criar Evento\n";
            cout << "2. Adicionar Convidado\n";
            cout << "3. Exibir Evento\n";
            cout << "4. Excluir Evento\n";
            cout << "5. Voltar\n";

            cin >> choice;

            // Criar Evento
            if (choice == 1) {
                string responsavel, nome_evento, data_evento;
                cout << "Responsável: ";
                cin.ignore(); 
                getline(cin, responsavel);
                cout << "Nome do Evento: ";
                cin.ignore(); 
                getline(cin, nome_evento);
                cout << "Data do Evento: ";
                cin >> data_evento;
                eventoManager.criar_evento(responsavel, nome_evento, data_evento);
            
            // Adicionar Convidado
            } else if (choice == 2) {
                string responsavel, nome_evento;
                cout << "Responsável do Evento: ";
                cin.ignore(); 
                getline(cin, responsavel);
                cout << "Nome do Evento: ";
                cin.ignore(); 
                getline(cin, nome_evento);
                eventoManager.adicionar_convidado(responsavel, nome_evento);
            
            // Exibir Evento
            } else if (choice == 3) {
                string responsavel, nome_evento;
                cout << "Responsável do Evento: ";
                cin.ignore(); 
                getline(cin, responsavel);
                cout << "Nome do Evento: ";
                cin.ignore(); 
                getline(cin, nome_evento);
                eventoManager.exibir_evento(responsavel, nome_evento);
            
            // Excluir Evento
            } else if (choice == 4) {
                string responsavel, nome_evento;
                cout << "Responsável do Evento: ";
                cin.ignore(); 
                getline(cin, responsavel);
                cout << "Nome do Evento: ";
                cin.ignore(); 
                getline(cin, nome_evento);
                eventoManager.excluir_evento(responsavel, nome_evento);
            
            } else if (choice == 5) {
                break; // Encerra o programa
            }
        }
        }

    // MENU OPÇÕES ENCOMENDAS =========================================================================================================
        if (opcao == 3){

        Encomendas encomendasManager;

        while (true) {
            cout << "Escolha uma ação:\n";
            cout << "1. Registrar Encomenda\n";
            cout << "2. Apagar Encomenda\n";
            cout << "3. Exibir Encomendas\n";
            cout << "4. Verificar Encomenda\n";
            cout << "5. Voltar\n";
            int choice;
            cin >> choice;

            // Registrar Encomenda
            if (choice == 1) {
                string id, destinatario, data_entrega;
                cout << "ID da Encomenda: ";
                cin >> id;
                cout << "Destinatário: ";
                cin.ignore(); 
                getline(cin, destinatario);
                cout << "Data de Entrega: ";
                cin >> data_entrega;

                if (encomendasManager.registrar_encomenda(id, destinatario, data_entrega)) {
                    cout << "Encomenda registrada com sucesso.\n";
                } else {
                    cout << "Falha ao registrar a encomenda. Verifique as entradas.\n";
                }
            
            // Apagar Encomenda    
            } else if (choice == 2) {
                string id;
                cout << "ID da Encomenda a ser apagada: ";
                cin >> id;
                encomendasManager.apagar_encomenda(id);
            
            // Exibir Encomendas
            } else if (choice == 3) {
                cout << "Encomendas Registradas:\n";
                encomendasManager.exibir_encomendas();
            
            // Verificar Encomenda    
            } else if (choice == 4) {
                string id;
                cout << "ID da Encomenda a ser verificada: ";
                cin >> id;
                if (encomendasManager.verificar_encomenda(id)) {
                    cout << "A encomenda com o ID " << id << " existe.\n";
                } else {
                    cout << "A encomenda com o ID " << id << " não existe.\n";
                }
                
            } else if (choice == 5) {
                break; // encerra programa
            }   
        }
        }

    // FIM DO PROGRAMA ================================================================================================================
        if (opcao == 4){
            cout <<"Até mais!\n";
            break;
        }  
    }
    return 0;
}
