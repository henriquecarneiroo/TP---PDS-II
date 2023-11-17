#include "apartamento.hpp"

#include <list>
#include <string>
#include <iostream>

using namespace std;


Apartamento::Apartamento(int _Moradores, int _Visitantes, int _Pets, int _Veiculos)
    : MAX_MORADORES(_Moradores), MAX_VISITANTES(_Visitantes), MAX_PETS(_Pets), MAX_VEICULOS(_Veiculos){   
    }

Apartamento::Apartamento(){}


void Apartamento::inserir_pessoa(string nome, string data_nascimento, string tipo_pessoa)
{
    Pessoa pessoa;
    pessoa.nome = nome;
    pessoa.data_nascimento = data_nascimento;
    if (tipo_pessoa == "moradora")
    {
        if(MAX_MORADORES > 0){
            pessoa.tipo_pessoa = "moradora";
            pessoas_.push_back(pessoa);
            MAX_MORADORES--;
            contador["Moradores"]++;
        }
        cout << "Morador inserido com sucesso\n";
        return;
    }
    if (tipo_pessoa == "visitante")
    {
        if(MAX_VISITANTES > 0){
            pessoa.tipo_pessoa = "visitante";
            pessoas_.push_back(pessoa);
            MAX_VISITANTES--;
            contador["Visitantes"]++;
        }
        return;
    }
}

void Apartamento::inserir_pet(string nome, string raca, string tipo)
{
    Pet pet;

    pet.nome = nome;
    pet.raca = raca;

    if(MAX_PETS > 0){
        if (tipo == "cachorro")
        {
            pet.tipo_pet = "cachorro";
        }
        else if (tipo == "gato")
        {
            pet.tipo_pet = "gato";
        }
        else if (tipo == "passaro")
        {
            pet.tipo_pet = "passaro";
        }
        else if (tipo == "outro")
        {
            pet.tipo_pet = "outro";
        }

        pets_.push_back(pet);
        MAX_PETS--;
        contador["Pets"]++;
    }
}

void Apartamento::inserir_veiculo(string modelo, string placa, string tipo_veiculo)
{
    Veiculo veiculo;

    veiculo.modelo = modelo;
    veiculo.placa = placa;
    veiculo.tipo_veiculo = tipo_veiculo;

    if(MAX_VEICULOS > 0){
        veiculos_.push_back(veiculo);
        MAX_VEICULOS--;
        contador["Veiculos"]++;
    }
}

// da para deixar so o nome
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
                (*it).tipo_pessoa = "moradora";
                if(tipo_pessoa_antigo == "visitante"){
                    contador["Visitantes"]--;
                    contador["Moradores"]++;
                }
            }
            else if (tipo_pessoa_novo == "visitante")
            {
                (*it).tipo_pessoa = "visitante";
                if(tipo_pessoa_antigo == "moradora"){
                    contador["Moradores"]--;
                    contador["Visitantes"]++;
                }
            }
            break;
        }
    }
}

// da para deixar so o nome 
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
                (*it).tipo_pet = "cachorro";
            }
            else if (tipo_novo == "gato")
            {
                (*it).tipo_pet = "gato";
            }
            else if (tipo_novo == "passaro")
            {
                (*it).tipo_pet = "passaro";
            }
            else if (tipo_novo == "outro")
            {
                (*it).tipo_pet = "outro";
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
            if ((*it).tipo_pessoa == "moradora"){
                pessoas_.erase(it);
                contador["Moradores"]--;
                MAX_MORADORES++;
                break;
            }
            else if ((*it).tipo_pessoa == "visitante"){
                pessoas_.erase(it);
                contador["Visitantes"]--;
                MAX_VISITANTES++;
                break;
            }
        }
    }
}

// Lembrar de tratar exceções, pro caso dos dados não baterem
// Lembrando que podemos retirar esse contadores de tipos, talvez seja desnecessário
// Exclui um pet e atualiza os contadores

//Da para deixar so com o nome do pet 
void Apartamento::excluir_pet(string nome_pet, string raca, string tipo)
{
    for (auto it = pets_.begin(); it != pets_.end(); it++)
    {
        if(MAX_PETS < 3){
            if ((*it).nome == nome_pet && (*it).raca == raca)
            {
                pets_.erase(it);
                MAX_PETS++;
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
            if ((*it).placa == placa)
            {
                veiculos_.erase(it);
                contador["Veiculos"]--;
                MAX_VEICULOS++;
            }
        break;
    }
}

void Apartamento::exibir_estatisticas()
{
    cout << "Quantidades de moradores: " << contador["Moradores"] << endl;
    cout << "Quantidade de visitantes: " << contador["Visitantes"] << endl;
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++){
        cout <<"Nome: "<< it->nome << endl <<"Data de Nascimemto: "<< it->data_nascimento << endl <<"Tipo: "<< it->tipo_pessoa << endl;
    }
    cout << "Quantidade de pets: " << contador["Pets"] << endl;
    for (auto it = pets_.begin(); it != pets_.end(); it++){
        cout <<"Nome: "<< it->nome << endl <<"Raca: "<< it->raca << endl <<"Tipo Pet: "<< it->tipo_pet << endl;
    }
    cout << "Quantidade de veículos: " << contador["Veiculos"] << endl;
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++){
        cout <<"Modelo: "<< it->modelo << endl <<"Placa: "<< it->placa << endl <<"Tipo Veiculo: "<< it->tipo_veiculo << endl;
    }
}

// Retorna a quantidade de itens, a partir da chave passada, do contador
int Apartamento::quantidade(string chave){
    return contador[chave];
}

bool Apartamento::eh_morador(string nome){
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++){
        if ((*it).nome == nome && (*it).tipo_pessoa == "moradora"){
            return true;
        }
    }
    return false;
}

bool Apartamento::eh_visitante(string nome){
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++){
        if ((*it).nome == nome && (*it).tipo_pessoa == "visitante"){
            return true;
        }
    }
    return false;
}