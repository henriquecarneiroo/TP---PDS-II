#include "apartamento.hpp"

#include <list>
#include <string>
#include <iostream>

using namespace std;

bool Apartamento::verifica_quantidade_restante(string tipo)
{
    if (tipo == "moradora")
    {
        if (MAX_MORADORES > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (tipo == "visitante")
    {
        if(MAX_VISITANTES > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (tipo == "pet")
    {
        if(MAX_PETS > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (tipo == "veiculo")
    {
        if(MAX_VEICULOS > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool Apartamento::esta_vazio(string tipo)
{
    if(tipo == "pessoa")
    {
        if(pessoas_.size() == 0)
        {
            return true;
        }
        else
        return false;
    }
    else if(tipo == "pet")
    {
        if(pets_.size() == 0)
        {
            return true;
        }
        return false;
    }
    else if(tipo == "veiculo")
    {
        if(veiculos_.size() == 0)
        {
            return true;
        }
        return false;
    }
    return false;
}

Apartamento::Apartamento(int _Moradores, int _Visitantes, int _Pets, int _Veiculos)
    : MAX_MORADORES(_Moradores), MAX_VISITANTES(_Visitantes), MAX_PETS(_Pets), MAX_VEICULOS(_Veiculos)
{
}

Apartamento::Apartamento() {}

void Apartamento::inserir_pessoa(string nome, string data_nascimento, string tipo_pessoa)
{
    Pessoa pessoa;
    pessoa.nome = nome;
    pessoa.data_nascimento = data_nascimento;
    if (tipo_pessoa == "moradora" || 0)
    {
        if (verifica_quantidade_restante(tipo_pessoa))
        {
            pessoa.tipo_pessoa = moradora;
            pessoas_.push_back(pessoa);
            MAX_MORADORES--;
            contador["Moradores"]++;
        }
    }
    else if (tipo_pessoa == "visitante" || 1)
    {
        if (verifica_quantidade_restante(tipo_pessoa))
        {
            pessoa.tipo_pessoa = visitante;
            pessoas_.push_back(pessoa);
            MAX_VISITANTES--;
            contador["Visitantes"]++;
        }
    }
}

void Apartamento::inserir_pet(string nome, string raca, string tipo)
{
    Pet pet;

    pet.nome = nome;
    pet.raca = raca;

    if (verifica_quantidade_restante("pet"))
    {
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

    if (verifica_quantidade_restante("veiculo"))
    {
        veiculos_.push_back(veiculo);
        MAX_VEICULOS--;
        contador["Veiculos"]++;
    }
}

void Apartamento::editar_pessoa(string nome_antigo,
                                string nome_novo, string data_nascimento_nova, string tipo_pessoa_novo){

    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++){ // procura a pessoa
        if (it->nome == nome_antigo){
            it->nome = nome_novo;
            it->data_nascimento = data_nascimento_nova;
            if (tipo_pessoa_novo == "moradora"){ // faz a alteração do tipo e dos contadores
                if (it->tipo_pessoa == visitante){
                    contador["Visitantes"]--;
                    contador["Moradores"]++;
                    it->tipo_pessoa = moradora;
                    cout << "Edição concluída! \n" << endl;

                } else if (it->tipo_pessoa == moradora){
                    it->tipo_pessoa = moradora;
                    cout << "Edição concluída! \n" << endl;
                }
            } else if (tipo_pessoa_novo == "visitante"){
                if (it->tipo_pessoa == moradora){
                    contador["Moradores"]--;
                    contador["Visitantes"]++;
                    it->tipo_pessoa = visitante;
                    cout << "Edição concluída! \n" << endl;
                } else if (it->tipo_pessoa == visitante){
                    it->tipo_pessoa = visitante;
                    cout << "Edição concluída! \n" << endl;
                }
            }
            break;
        }
    }
}

void Apartamento::editar_pet(string nome_pet_antigo, string raca_antiga, string tipo_antigo,
                             string nome_pet_novo, string raca_nova, string tipo_novo)
{
    if(verifica_quantidade_restante("pet")){
    for (auto it = pets_.begin(); it != pets_.end(); it++)
    {
        if (it->nome == nome_pet_antigo && it->raca == raca_antiga)
        {
            it->nome = nome_pet_novo;
            it->raca = raca_nova;

            // Essa parte define o novo tipo de pet
            if (tipo_novo == "cachorro")
            {
                it->tipo_pet = cachorro;
            }
            else if (tipo_novo == "gato")
            {
                it->tipo_pet = gato;
            }
            else if (tipo_novo == "passaro")
            {
                it->tipo_pet = passaro;
            }
            else if (tipo_novo == "outro")
            {
                it->tipo_pet = outro;
            }
            break;
        }
    }
    }
}

void Apartamento::editar_veiculo(string placa_antiga,
                                 string placa_nova, string modelo_novo, string tipo_veiculo_novo)
{
    if(verifica_quantidade_restante("veiculo")){
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++)
    {
        if (it->placa == placa_antiga)
        {
            it->modelo = modelo_novo;
            it->placa = placa_nova;
            it->tipo_veiculo = tipo_veiculo_novo;
            break;
        }
    }
    }
}

// Exclui a pessoa e atualiza os contadores
void Apartamento::excluir_pessoa(string nome_pessoa, string data_nascimento, string tipo_pessoa)
{
    if(!esta_vazio("pessoa")){ 
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++)
    {
        if (it->nome == nome_pessoa && it->data_nascimento == data_nascimento) // problema do enum denovo
        {
            if (it->tipo_pessoa == moradora)
            {
                pessoas_.erase(it);
                contador["Moradores"]--;
                MAX_MORADORES++;
                break;
            }
            else if (it->tipo_pessoa == visitante)
            {
                pessoas_.erase(it);
                contador["Visitantes"]--;
                MAX_VISITANTES++;
                break;
            }
        }
    }
    }
}

// Lembrar de tratar exceções, pro caso dos dados não baterem
// Lembrando que podemos retirar esse contadores de tipos, talvez seja desnecessário
// Exclui um pet e atualiza os contadores
void Apartamento::excluir_pet(string nome_pet, string raca, string tipo)
{
    if(!esta_vazio("pet")){
    for (auto it = pets_.begin(); it != pets_.end(); it++)
    {
        if (MAX_PETS < 3)
        {
            if (it->nome == nome_pet && it->raca == raca)
            {
                pets_.erase(it);
                MAX_PETS++;
                contador["Pets"]--;
            }
        }
        break;
    }
    }
}

// Exclui um veículo e atualiza os contadores
void Apartamento::excluir_veiculo(string placa)
{
    if(!esta_vazio("veiculo")){
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++)
    {
        //if (MAX_VEICULOS < 2)
        {
            if (it->placa == placa)
            {
                veiculos_.erase(it);
                contador["Veiculos"]--;
                MAX_VEICULOS++;
            }
        }
        break;
    }
    }
}

void Apartamento::exibir_estatisticas()
{
    cout << endl;
    cout << "Quantidades de moradores do prédio: " << contador["Moradores"] << endl;
    cout << "Quantidade de visitantes: " << contador["Visitantes"] << endl;
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++)
    {
        cout<< endl << "\t" << "Nome: " << it->nome << endl
             << "\t" << "Data de Nascimemto: " << it->data_nascimento << endl
             << "\t" << "Tipo: " << it->tipo_pessoa << endl;
    }
    cout << endl << "Quantidade de pets: " << contador["Pets"] << endl;
    for (auto it = pets_.begin(); it != pets_.end(); it++)
    {
        cout << "\t" << "Nome: " << it->nome << endl
             << "\t" << "Raca: " << it->raca << endl
             << "\t" << "Tipo Pet: " << it->tipo_pet << endl;
    }
    cout << endl << "Quantidade de veículos: " << contador["Veiculos"] << endl;
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++)
    {
        cout << "\t" << "Modelo: " << it->modelo << endl
             << "\t" << "Placa: " << it->placa << endl
             << "\t" << "Tipo Veiculo: " << it->tipo_veiculo << endl << endl;
    }
}

// Retorna a quantidade de itens, a partir da chave passada, do contador
int Apartamento::quantidade(string chave)
{
    return contador[chave];
}

bool Apartamento::eh_morador(string nome)
{
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++)
    {
        if (it->nome == nome && it->tipo_pessoa == moradora)
        {
            return true;
        }
    }
    return false;
}

bool Apartamento::eh_visitante(string nome)
{
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++)
    {
        if (it->nome == nome && it->tipo_pessoa == visitante)
        {
            return true;
        }
    }
    return false;
}