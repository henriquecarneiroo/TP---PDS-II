#include "encomendas.hpp"
#include "apartamento.hpp"

#include <list>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool verifica_id(string id)
{
    if (id.size() < 6 || id.size() > 50)
    {
        return false;
    }
    return true;
}

bool Encomendas::registrar_encomenda(string id, string destinatario, string data_entrega)
{
    Encomenda encomenda;
    Apartamento ap;

    if (verifica_id(id) && ap.eh_morador(destinatario))
    {
        encomenda.data_entrega = data_entrega;
        encomenda.destinatario = destinatario;

        encomendas_[id] = encomenda;
        return true;
    }
    return false;
}

void Encomendas::apagar_encomenda(string id)
{
    for (auto it = encomendas_.begin(); it != encomendas_.end(); it++)
    {
        if ((*it).first == id)
        {
            encomendas_.erase(it);
            break;
        }
    }
}

void Encomendas::exibir_encomendas()
{
    for (auto it = encomendas_.begin(); it != encomendas_.end(); it++)
    {
        cout << "id: " << (*it).first << endl;
        cout << "destinatario: " << (*it).second.destinatario << endl;
        cout << "data de entrega: " << (*it).second.data_entrega << endl;
    }
}

bool Encomendas::verificar_encomenda(string id)
{
    for (auto it = encomendas_.begin(); it != encomendas_.end(); it++)
    {
        if ((*it).first == id)
        {
            return true;
        }
    }
    return false;
}


/*
#include "encomendas.hpp"
#include "apartamento.hpp"
#include <iostream>

// verifica se o tamanho do ID da encomenda está fora do intervalo desejado
bool verifica_id(string id) {
    return id.size() >= 6 && id.size() <= 50;
}

bool Encomendas::registrar_encomenda(string id, string destinatario, string data_entrega) {
    Apartamento ap;

    if (!verifica_id(id)) {
        std::cerr << "Erro ao registrar encomenda: ID de encomenda inválido." << std::endl;
        return false;
    }

    if (!ap.eh_morador(destinatario)) {
        std::cerr << "Erro ao registrar encomenda: Destinatário não é um morador válido." << std::endl;
        return false;
    }

    // Declaração da variável encomendas_ na classe Encomendas
    Encomenda encomenda;
    encomenda.data_entrega = data_entrega;
    encomenda.destinatario = destinatario;

    encomendas_[id] = encomenda;
    return true;
}

void Encomendas::apagar_encomenda(string id) {
    auto it = encomendas_.find(id);
    if (it == encomendas_.end()) {
        std::cerr << "Erro ao apagar encomenda: ID de encomenda não encontrado." << std::endl;
        return;
    }

    encomendas_.erase(it);
}

void Encomendas::exibir_encomendas() {
    for (const auto& entry : encomendas_) {
        cout << "ID: " << entry.first << endl;
        cout << "Destinatário: " << entry.second.destinatario << endl;
        cout << "Data de Entrega: " << entry.second.data_entrega << endl;
        cout << "-------------------------" << endl;
    }
}

bool Encomendas::verificar_encomenda(string id) {
    if (encomendas_.find(id) == encomendas_.end()) {
        std::cerr << "Erro ao verificar encomenda: ID de encomenda não encontrado." << std::endl;
        return false;
    }
    return true;
}
*/
