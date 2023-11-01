#include "apartamento.hpp"

#include <list>
#include <string>
#include <iostream>

using namespace std;

// tem que testar esse construtor pra ver se ele funciona como o esperado
Apartamento::Apartamento(int max_Moradores, int max_Visitantes,
                         int max_Pets, int max_Veiculos)
{
    NumeroRestanteMoradores = max_Moradores;
    NumeroRestanteVisitantes = max_Visitantes;
    NumeroRestantePets = max_Pets;
    NumeroRestanteVeiculos = max_Veiculos;
}

void Apartamento::inserir_pessoa(string nome, string data_nascimento, string tipo_pessoa)
{
    Pessoa pessoa;
    pessoa.nome = nome;
    pessoa.data_nascimento = data_nascimento;
    if (tipo_pessoa == "moradora")
    {
        if(NumeroRestanteMoradores > 0){
            pessoa.tipo_pessoa = moradora;
            pessoas_.push_back(pessoa);
            NumeroRestanteMoradores--;
            contador["Moradores"]++;
        }
    }
    else if (tipo_pessoa == "visitante")
    {
        if(NumeroRestanteVisitantes > 0){
            pessoa.tipo_pessoa = visitante;
            pessoas_.push_back(pessoa);
            NumeroRestanteVisitantes--;
            contador["Visitantes"]++;
        }
    }
}

void Apartamento::inserir_pet(string nome, string raca, string tipo)
{
    Pet pet;

    pet.nome = nome;
    pet.raca = raca;

    if(NumeroRestantePets > 0){
        if (tipo == "cachorro")
        {
            pet.tipo_pet = cachorro;
        }
        else if (tipo == "gato")
        {
            pet.tipo_pet = gato;
        }
        else if (tipo == "passaro")
        {
            pet.tipo_pet = passaro;
        }
        else if (tipo == "outro")
        {
            pet.tipo_pet = outro;
        }

        pets_.push_back(pet);
        NumeroRestantePets--;
        contador["Pets"]++;
    }
}

void Apartamento::inserir_veiculo(string modelo, string placa, string tipo_veiculo)
{
    Veiculo veiculo;

    veiculo.modelo = modelo;
    veiculo.placa = placa;
    veiculo.tipo_veiculo = tipo_veiculo;

    if(NumeroRestanteVeiculos > 0){
        veiculos_.push_back(veiculo);
        NumeroRestanteVeiculos--;
        contador["Veículos"]++;
    }
}

void Apartamento::editar_pessoa(string nome_antigo, string data_nascimento_antiga, string tipo_pessoa_antigo,
                                string nome_novo, string data_nascimento_nova, string tipo_pessoa_novo)
{
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++)
    {
        if ((*it).nome == nome_antigo && (*it).data_nascimento == data_nascimento_antiga)
        {
            (*it).nome = nome_novo;
            (*it).data_nascimento = data_nascimento_nova;

            if (tipo_pessoa_novo == "moradora")
            {
                (*it).tipo_pessoa = moradora;
                if(tipo_pessoa_antigo == "visitante"){
                    contador["Visitantes"]--;
                    contador["Moradores"]++;
                }
            }
            else if (tipo_pessoa_novo == "visitante")
            {
                (*it).tipo_pessoa = visitante;
                if(tipo_pessoa_antigo == "moradora"){
                    contador["Moradores"]--;
                    contador["Visitantes"]++;
                }
            }
            break;
        }
    }
}

void Apartamento::editar_pet(string nome_pet_antigo, string raca_antiga, string tipo_antigo,
                             string nome_pet_novo, string raca_nova, string tipo_novo)
{

    for (auto it = pets_.begin(); it != pets_.end(); it++)
    {
        if ((*it).nome == nome_pet_antigo && (*it).raca == raca_antiga)
        {
            (*it).nome = nome_pet_novo;
            (*it).raca = raca_nova;

            // Essa parte define o novo tipo de pet
            if (tipo_novo == "cachorro")
            {
                (*it).tipo_pet = cachorro;
            }
            else if (tipo_novo == "gato")
            {
                (*it).tipo_pet = gato;
            }
            else if (tipo_novo == "passaro")
            {
                (*it).tipo_pet = passaro;
            }
            else if (tipo_novo == "outro")
            {
                (*it).tipo_pet = outro;
            }
            break;
        }
    }
}

void Apartamento::editar_veiculo(string placa_antiga,
                                 string placa_nova, string modelo_novo, string tipo_veiculo_novo)
{
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++)
    {
        if ((*it).placa == placa_antiga)
        {
            (*it).modelo = modelo_novo;
            (*it).placa = placa_nova;
            (*it).tipo_veiculo = tipo_veiculo_novo;
            break;
        }
    }
}

// Exclui a pessoa e atualiza os contadores
void Apartamento::excluir_pessoa(string nome_pessoa)
{
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++)
    {
        if ((*it).nome == nome_pessoa)
        {
            if ((*it).tipo_pessoa == moradora){
                pessoas_.erase(it);
                contador["Moradores"]--;
                NumeroRestanteMoradores++;
                break;
            }
            else if ((*it).tipo_pessoa == visitante){
                pessoas_.erase(it);
                contador["Visitantes"]--;
                NumeroRestanteVisitantes++;
                break;
            }
        }
    }
}

// Lembrar de tratar exceções, pro caso dos dados não baterem
// Lembrando que podemos retirar esse contadores de tipos, talvez seja desnecessário
// Exclui um pet e atualiza os contadores
void Apartamento::excluir_pet(string nome_pet, string raca, string tipo)
{
    for (auto it = pets_.begin(); it != pets_.end(); it++)
    {
        if(NumeroRestantePets < 3){
            if ((*it).nome == nome_pet && (*it).raca == raca)
            {
                pets_.erase(it);
                NumeroRestantePets++;
                contador["Pets"]--;
            }
        }
        break;
    }
}

// Exclui um veículo e atualiza os contadores
void Apartamento::excluir_veiculo(string placa)
{
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++)
    {
        if(NumeroRestanteVeiculos < 2){
            if ((*it).placa == placa)
            {
                veiculos_.erase(it);
                contador["Veiculos"]--;
                NumeroRestanteVeiculos++;
            }
        }
        break;
    }
}

void Apartamento::exibir_estatisticas()
{
    cout << "Quantidades de moradores do prédio: " << contador["Moradores"] << endl;
    cout << "Quantidade de visitantes: " << contador["Visitantes"] << endl;
    cout << "Quantidade de pets: " << contador["Pets"] << endl;
    cout << "Quantidade de veículos: " << contador["Veículos"] << endl;
}

// Retorna a quantidade de itens, a partir da chave passada, do contador
int Apartamento::quantidade(string chave){
    return contador[chave];
}

bool Apartamento::eh_morador(string nome){
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++){
        if ((*it).nome == nome && (*it).tipo_pessoa == moradora){
            return true;
        }
    }
    return false;
}

bool Apartamento::eh_visitante(string nome){
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++){
        if ((*it).nome == nome && (*it).tipo_pessoa == visitante){
            return true;
        }
    }
    return false;
}