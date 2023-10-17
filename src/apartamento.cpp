#include "apartamento.h"
#include <list>
#include <string>
#include <iostream>

using namespace std;

void Apartamento::inserir_pessoa()
{
    int tipo;
    Pessoa pessoa;
    cin >> pessoa.nome;
    cin >> pessoa.data_nascimento;
    cin >> tipo;

    switch (tipo)
    {
    case 1:
        pessoa.tipo_pessoa = administradora;
    case 2:
        pessoa.tipo_pessoa = moradora;
    case 3:
        pessoa.tipo_pessoa = visitante;
    }
    pessoas_.push_back(pessoa);
}

void Apartamento::inserir_pet()
{
    int tipo;
    Pet pet;
    cin >> pet.nome;
    cin >> pet.raca;
    cin >> tipo;

    switch (tipo)
    {
    case 1:
        pet.tipo_pet = cachorro;
    case 2:
        pet.tipo_pet = gato;
    case 3:
        pet.tipo_pet = passaro;
    case 4:
        pet.tipo_pet = outro;
    }
    pets_.push_back(pet);
}

void Apartamento::inserir_veiculo()
{
    Veiculo veiculo;
    cin >> veiculo.modelo;
    cin >> veiculo.placa;
    cin >> veiculo.tipo_veiculo;

    veiculos_.push_back(veiculo);
}
void Apartamento::editar_pessoa(string nome_pessoa)
{
    int tipo;

    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++)
    {
        if ((*it).nome == nome_pessoa)
        {
            cin >> (*it).nome;
            cin >> (*it).data_nascimento;
            cin >> tipo;
            switch (tipo)
            {
            case 1:
                (*it).tipo_pessoa = administradora;
            case 2:
                (*it).tipo_pessoa = moradora;
            case 3:
                (*it).tipo_pessoa = visitante;
            }
            break;
        }
    }
}
void Apartamento::editar_pet(string nome_pet)
{
    int tipo;

    for (auto it = pets_.begin(); it != pets_.end(); it++)
    {
        if ((*it).nome == nome_pet)
        {
            cin >> (*it).nome;
            cin >> (*it).raca;
            cin >> tipo;

            switch (tipo)
            {
            case 1:
                (*it).tipo_pet = cachorro;
            case 2:
                (*it).tipo_pet = gato;
            case 3:
                (*it).tipo_pet = passaro;
            case 4:
                (*it).tipo_pet = outro;
            }

            break;
        }
    }
}
void Apartamento::editar_veiculo(string placa)
{
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++)
    {
        if ((*it).placa == placa)
        {
            cin >> (*it).modelo;
            cin >> (*it).placa;
            cin >> (*it).tipo_veiculo;

            break;
        }
    }
}

void Apartamento::editar_pessoa(string nome_pessoa)
{
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++)
    {
        if ((*it).nome == nome_pessoa)
        {
            pessoas_.erase(it);
            break;
        }
    }
}

void Apartamento::excluir_pet(string nome_pet)
{
    for (auto it = pets_.begin(); it != pets_.end(); it++)
    {
        if ((*it).nome == nome_pet)
        {
            pets_.erase(it);
        }
    }
}

void Apartamento::excluir_veiculo(string placa)
{
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++)
    {
        if ((*it).placa == placa)
        {
            veiculos_.erase(it);
        }
    }
}

void Apartamento::exibir_estatisticas()
{
    // as funções que irão contar as quantidades ainda precisam ser implementadas
    cout << "Quantidades de moradores do prédio: ";
    cout << "Quantidade de visitantes: ";
    cout << "Administrador(a): ";
    cout << "Quantidade de visitantes: ";
    cout << "Quantidade de pets: " << pets_.size();
    cout << "Quantidade de veículos: " << veiculos_.size();
}