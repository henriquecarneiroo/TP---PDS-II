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