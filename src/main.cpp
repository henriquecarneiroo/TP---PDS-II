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
    int num_ap = 0;
    map<int, Apartamento> aps;

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
            while (num_ap <= 0){
                Apartamento apartamento(max_Moradores, max_Visitantes, max_Pets, max_Veiculos);
                cout << "Informe o número do apartamento: \n";
                cin >> num_ap;
                if (num_ap <= 0){
                    cout << "Digite um numero de apartamento válido\n";
                }
            }
        
    // MENU DE OPÇÕES APARTAMENTOS ====================================================================================================
            while (true) {
                cout << "Escolha uma ação:\n";
                cout << "1. Inserir Pessoa\n";
                cout << "2. Inserir Pet\n";
                cout << "3. Inserir Veículo\n";
                cout << "4. Exibir Estatísticas\n";
                cout << "5. Voltar\n";

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

                // Exibir estatisticas do apartamento
                } else if (escolha == 4) {
                    aps[num_ap].exibir_estatisticas();

                } else if (escolha == 5) {
                    break; // Encerra essa parte do programa
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
                //eventoManager.adicionar_convidado(responsavel, nome_evento);
            
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
