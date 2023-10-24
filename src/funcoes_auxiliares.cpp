#include "funcoes_auxiliares.h"
#include "apartamento.h"

int contar_moradores(list<Pessoa>::iterator itB, list<Pessoa>::iterator itE)
{
    int num_moradores = 0;
    for (itB;itB != itE; itB++)
    {

        if ((*itB).tipo_pessoa == "moradora")
        {
            num_moradores++;
        }
    }
    return num_moradores;
}

int contar_visitantes(int contar_morador(list<Pessoa>::iterator itB, list<Pessoa>::iterator itE))
{
    int num_visitantes = 0;
    for (itB;itB != itE; itB++)
    {
        if ((*itB).tipo_pessoa == "visitante")
        {
            num_visitantes++;
        }
    }
    return num_visitantes;
}