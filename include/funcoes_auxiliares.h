#ifndef FUNCOES_AUXILIARES_H_
#define FUNCOES_AUXILIARES_H_
#include <string>
#include <list>
#include "apartamento.h"

using std::string;
using std::list;

struct Pessoa
{
    string nome;
    string data_nascimento;
    string tipo_pessoa;
};

list<Pessoa> pessoas_;
auto itB = pessoas_.begin();
auto itE = pessoas_.end();

int contar_morador(list<Pessoa>::iterator itB, list<Pessoa>::iterator itE);
int contar_visitante(int contar_morador(list<Pessoa>::iterator itB, list<Pessoa>::iterator itE)
);

#endif