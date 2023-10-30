#include "apartamento.hpp"
#include "evento.hpp"
#include "encomendas.hpp"

#include <iostream>
#include <string>

int main() {

// CONSTRUTORES =======================================================================================================================

    int max_Moradores, max_Visitantes, max_Pets, max_Veiculos;

    std::cout << "Informe o número máximo de moradores: ";
    std::cin >> max_Moradores;

    std::cout << "Informe o número máximo de visitantes: ";
    std::cin >> max_Visitantes;

    std::cout << "Informe o número máximo de pets: ";
    std::cin >> max_Pets;

    std::cout << "Informe o número máximo de veículos: ";
    std::cin >> max_Veiculos;

    // Map que armazena os apartamentos com o número de cada 
    int num_ap = 0;
    map<int, Apartamento> aps;

// PAINEL INICIAL ====================================================================================================================

    while (true){
        std::cout << "Escolha uma opção:\n";
        std::cout << "1. Modificar Apartamentos\n";
        std::cout << "2. Modificar Eventos\n";
        std::cout << "3. Modificar Encomendas\n";
        std::cout << "4. Encerrar programa\n";
        int opcao;
        std::cin >> opcao;


        // Permite o gerenciamento dos Apartamentos
        if (opcao == 1){
            while (num_ap <= 0){
                Apartamento apartamento(max_Moradores, max_Visitantes, max_Pets, max_Veiculos);
                std::cout << "Informe o número do apartamento: \n";
                std::cin >> num_ap;
                if (num_ap <= 0){
                    std::cout << "Digite um numero de apartamento válido\n";
                }
            }
        
    // MENU DE OPÇÕES APARTAMENTOS ====================================================================================================5
            while (true) {
                std::cout << "Escolha uma ação:\n";
                std::cout << "1. Inserir Pessoa\n";
                std::cout << "2. Inserir Pet\n";
                std::cout << "3. Inserir Veículo\n";
                std::cout << "4. Exibir Estatísticas\n";
                std::cout << "5. Sair\n";

                int escolha;
                std::cin >> escolha;

                // Inserir pessoa
                if (escolha == 1) {
                    std::string nome, data_nascimento, tipo_pessoa;
                    std::cout << "Nome: ";
                    std::cin >> nome;
                    std::cout << "Data de Nascimento: ";
                    std::cin >> data_nascimento;
                    std::cout << "Tipo de Pessoa (moradora ou visitante): ";
                    std::cin >> tipo_pessoa;
                    aps[num_ap].inserir_pessoa(nome, data_nascimento, tipo_pessoa);

                // Inserir pet
                } else if (escolha == 2) {
                    std::string nome, raca, tipo;
                    std::cout << "Nome do Pet: ";
                    std::cin>> nome;
                    std::cout << "Raça do Pet: ";
                    std::cin >> raca;
                    std::cout << "Tipo de Pet (cachorro, gato, passaro ou outro): ";
                    std::cin >> tipo;
                    aps[num_ap].inserir_pet(nome, raca, tipo);

                // Inserir veículo
                } else if (escolha == 3) {
                    std::string modelo, placa, tipo_veiculo;
                    std::cout << "Modelo do Veículo: ";
                    std::cin>> modelo;
                    std::cout << "Placa do Veículo: ";
                    std::cin >> placa;
                    std::cout << "Tipo de Veículo: ";
                    std::cin >> tipo_veiculo;
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
            std::cout << "Escolha uma ação:\n";
            std::cout << "1. Criar Evento\n";
            std::cout << "2. Adicionar Convidado\n";
            std::cout << "3. Exibir Evento\n";
            std::cout << "4. Excluir Evento\n";
            std::cout << "5. Sair\n";

            std::cin >> choice;

            // Criar Evento
            if (choice == 1) {
                std::string responsavel, nome_evento, data_evento;
                std::cout << "Responsável: ";
                std::cin>> responsavel;
                std::cout << "Nome do Evento: ";
                std::cin>> nome_evento;
                std::cout << "Data do Evento: ";
                std::cin >> data_evento;
                eventoManager.criar_evento(responsavel, nome_evento, data_evento);
            
            // Adicionar Convidado
            } else if (choice == 2) {
                std::string responsavel, nome_evento;
                std::cout << "Responsável do Evento: ";
                std::cin>> responsavel;
                std::cout << "Nome do Evento: ";
                std::cin>> nome_evento;
                //eventoManager.adicionar_convidado(responsavel, nome_evento);
            
            // Exibir Evento
            } else if (choice == 3) {
                std::string responsavel, nome_evento;
                std::cout << "Responsável do Evento: ";
                std::cin>> responsavel;
                std::cout << "Nome do Evento: ";
                std::cin>> nome_evento;
                eventoManager.exibir_evento(responsavel, nome_evento);
            
            // Excluir Evento
            } else if (choice == 4) {
                std::string responsavel, nome_evento;
                std::cout << "Responsável do Evento: ";
                std::cin>> responsavel;
                std::cout << "Nome do Evento: ";
                std::cin>> nome_evento;
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
            std::cout << "Escolha uma ação:\n";
            std::cout << "1. Registrar Encomenda\n";
            std::cout << "2. Apagar Encomenda\n";
            std::cout << "3. Exibir Encomendas\n";
            std::cout << "4. Verificar Encomenda\n";
            std::cout << "5. Sair\n";
            int choice;
            std::cin >> choice;

            // Registrar Encomenda
            if (choice == 1) {
                std::string id, destinatario, data_entrega;
                std::cout << "ID da Encomenda: ";
                std::cin >> id;
                std::cout << "Destinatário: ";
                std::cin>> destinatario;
                std::cout << "Data de Entrega: ";
                std::cin >> data_entrega;

                if (encomendasManager.registrar_encomenda(id, destinatario, data_entrega)) {
                    std::cout << "Encomenda registrada com sucesso.\n";
                } else {
                    std::cout << "Falha ao registrar a encomenda. Verifique as entradas.\n";
                }
            
            // Apagar Encomenda    
            } else if (choice == 2) {
                std::string id;
                std::cout << "ID da Encomenda a ser apagada: ";
                std::cin >> id;
                encomendasManager.apagar_encomenda(id);
            
            // Exibir Encomendas
            } else if (choice == 3) {
                std::cout << "Encomendas Registradas:\n";
                encomendasManager.exibir_encomendas();
            
            // Verificar Encomenda    
            } else if (choice == 4) {
                std::string id;
                std::cout << "ID da Encomenda a ser verificada: ";
                std::cin >> id;
                if (encomendasManager.verificar_encomenda(id)) {
                    std::cout << "A encomenda com o ID " << id << " existe.\n";
                } else {
                    std::cout << "A encomenda com o ID " << id << " não existe.\n";
                }
                
            } else if (choice == 5) {
                break; // encerra programa
            }   
        }
        }

    // FIM DO PROGRAMA ================================================================================================================
        if (opcao == 4){
            std::cout <<"Até mais!\n";
            break;
        }  
    }
    return 0;
}
