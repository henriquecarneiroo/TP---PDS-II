#include "apartamento.h"
#include "evento.h"
#include "encomendas.h"

#include <iostream>
#include <string>

int main() {
    int max_Moradores, max_Visitantes, max_Pets, max_Veiculos;

    std::cout << "Informe o número máximo de moradores: ";
    std::cin >> max_Moradores;

    std::cout << "Informe o número máximo de visitantes: ";
    std::cin >> max_Visitantes;

    std::cout << "Informe o número máximo de pets: ";
    std::cin >> max_Pets;

    std::cout << "Informe o número máximo de veículos: ";
    std::cin >> max_Veiculos;

    Apartamento apartamento(max_Moradores, max_Visitantes, max_Pets, max_Veiculos);

    while (true) {
        std::cout << "Escolha uma ação:\n";
        std::cout << "1. Inserir Pessoa\n";
        std::cout << "2. Inserir Pet\n";
        std::cout << "3. Inserir Veículo\n";
        std::cout << "4. Exibir Estatísticas\n";
        std::cout << "5. Sair\n";

        int escolha;
        std::cin >> escolha;

        if (escolha == 1) {
            std::string nome, data_nascimento, tipo_pessoa;
            std::cout << "Nome: ";
            std::cin >> nome;
            std::cout << "Data de Nascimento: ";
            std::cin >> data_nascimento;
            std::cout << "Tipo de Pessoa (moradora/visitante): ";
            std::cin >> tipo_pessoa;
            apartamento.inserir_pessoa(nome, data_nascimento, tipo_pessoa);
          
        } else if (escolha == 2) {
            std::string nome, raca, tipo;
            std::cout << "Nome do Pet: ";
            std::cin >> nome;
            std::cout << "Raça do Pet: ";
            std::cin >> raca;
            std::cout << "Tipo de Pet (cachorro/gato/passaro/outro): ";
            std::cin >> tipo;
            apartamento.inserir_pet(nome, raca, tipo);
        } else if (escolha == 3) {
            std::string modelo, placa, tipo_veiculo;
            std::cout << "Modelo do Veículo: ";
            std::cin >> modelo;
            std::cout << "Placa do Veículo: ";
            std::cin >> placa;
            std::cout << "Tipo de Veículo: ";
            std::cin >> tipo_veiculo;
            apartamento.inserir_veiculo(modelo, placa, tipo_veiculo);
          
        } else if (escolha == 4) {
            apartamento.exibir_estatisticas();
          
        } else if (escolha == 5) {
            break; // Encerra o programa
        }
    }

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

        if (choice == 1) {
            std::string responsavel, nome_evento, data_evento;
            std::cout << "Responsável: ";
            std::cin >> responsavel;
            std::cout << "Nome do Evento: ";
            std::cin >> nome_evento;
            std::cout << "Data do Evento: ";
            std::cin >> data_evento;
            eventoManager.criar_evento(responsavel, nome_evento, data_evento);
          
        } else if (choice == 2) {
            std::string responsavel, nome_evento;
            std::cout << "Responsável do Evento: ";
            std::cin >> responsavel;
            std::cout << "Nome do Evento: ";
            std::cin >> nome_evento;
            eventoManager.adicionar_convidado(responsavel, nome_evento);
          
        } else if (choice == 3) {
            std::string responsavel, nome_evento;
            std::cout << "Responsável do Evento: ";
            std::cin >> responsavel;
            std::cout << "Nome do Evento: ";
            std::cin >> nome_evento;
            eventoManager.exibir_evento(responsavel, nome_evento);
          
        } else if (choice == 4) {
            std::string responsavel, nome_evento;
            std::cout << "Responsável do Evento: ";
            std::cin >> responsavel;
            std::cout << "Nome do Evento: ";
            std::cin >> nome_evento;
            eventoManager.excluir_evento(responsavel, nome_evento);
          
        } else if (choice == 5) {
            break; // Encerra o programa
        }
    }

    Encomendas encomendasManager;
    int choice;

    while (true) {
        std::cout << "Escolha uma ação:\n";
        std::cout << "1. Registrar Encomenda\n";
        std::cout << "2. Apagar Encomenda\n";
        std::cout << "3. Exibir Encomendas\n";
        std::cout << "4. Verificar Encomenda\n";
        std::cout << "5. Sair\n";

        std::cin >> choice;

        if (choice == 1) {
            std::string id, destinatario, data_entrega;
            std::cout << "ID da Encomenda: ";
            std::cin >> id;
            std::cout << "Destinatário: ";
            std::cin >> destinatario;
            std::cout << "Data de Entrega: ";
            std::cin >> data_entrega;

            if (encomendasManager.registrar_encomenda(id, destinatario, data_entrega)) {
                std::cout << "Encomenda registrada com sucesso.\n";
            } else {
                std::cout << "Falha ao registrar a encomenda. Verifique as entradas.\n";
            }
            
        } else if (choice == 2) {
            std::string id;
            std::cout << "ID da Encomenda a ser apagada: ";
            std::cin >> id;
            encomendasManager.apagar_encomenda(id);
            
        } else if (choice == 3) {
            std::cout << "Encomendas Registradas:\n";
            encomendasManager.exibir_encomendas();
            
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
    return 0;
}
