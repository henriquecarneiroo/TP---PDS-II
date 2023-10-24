#include "apartamento.h"
#include <list>
#include <string>
#include <iostream>

using namespace std;
/*
Mudanças no ultimo commit:
criado o construtor
algumas funções refeitas para usar os parâmetros
chamada de funções implementadas no .h

ideias:
vincular o pet e o veículo a um dono
colocar mais estatisticas
*/

// tem que testar esse construtor pra ver se ele funciona como o esperado
Apartamento::Apartamento(int max_Moradores, int max_Visitantes, int max_Pessoas,
                         int max_Pets, int max_Veiculos)
{
    NumeroRestanteMoradores = max_Moradores;
    NumeroRestanteVisitantes = max_Visitantes;
    NumeroRestantePessoas = max_Pessoas;
    NumeroRestantePets = max_Pets;
    NumeroRestanteVeiculos = max_Veiculos;
}

// Introduzindo a ideia do contador e retirando o tipo adm
// Lembrar de tratar a exceção para nomes, datas e tipos inválidos
// Lembrar de tratar exceção quando quiser adicionar mais moradores ou visitantes que o maximo permitido
// mesmo quando o numero de pessoas restante é válido
void Apartamento::inserir_pessoa(string nome, string data_nascimento, string tipo_pessoa)
{
    if (NumeroRestantePessoas > 0){
        Pessoa pessoa;

        pessoa.nome = nome;
        pessoa.data_nascimento = data_nascimento;

        if (tipo_pessoa == "moradora")
        {
            if(NumeroRestanteMoradores > 0){
                pessoa.tipo_pessoa = moradora;
                contador["Moradores"]++;
            }
        }
        else if (tipo_pessoa == "visitante")
        {
            if(NumeroRestanteVisitantes > 0){
                pessoa.tipo_pessoa = visitante;
                NumeroRestanteVisitantes--;
                contador["Visitantes"]++;
            }
        }

        pessoas_.push_back(pessoa);
        NumeroRestantePessoas--;
        contador["Pessoas"]++;
    }//else?
}

// introduzindo a ideia do contador
// lembrar de tratar exceções para nomes, raças e/ou tipos inválidos e para as quantidades máximas
void Apartamento::inserir_pet(string nome, string raca, string tipo)
{
    Pet pet;

    pet.nome = nome;
    pet.raca = raca;

    if(NumeroRestantePets > 0){
        if (tipo == "cachorro")
        {
            pet.tipo_pet = cachorro;
            contador["Cachorros"]++;
            // "Cães"?
        }
        else if (tipo == "gato")
        {
            pet.tipo_pet = gato;
            contador["Gatos"]++;
        }
        else if (tipo == "passaro")
        {
            pet.tipo_pet = passaro;
            contador["Passaros"]++;
        }
        else if (tipo == "outro")
        {
            pet.tipo_pet = outro;
            contador["Outras racas"]++;
            //... "raças"?
        }

        pets_.push_back(pet);
        NumeroRestantePets--;
        contador["Pets"]++;
    }//else?
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
    } //else?
}

// É necessário implementar número restante?
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

// Pensar como remover a raça antiga do contador (pensei por ifs, mas ficaria grande)
// É necessário implementar número restante?
void Apartamento::editar_pet(string nome_pet_antigo, string raca_antiga, string tipo_antigo,
                             string nome_pet_novo, string raca_nova, string tipo_novo)
{

    for (auto it = pets_.begin(); it != pets_.end(); it++)
    {
        if ((*it).nome == nome_pet_antigo && (*it).raca == raca_antiga)
        {
            (*it).nome = nome_pet_novo;
            (*it).raca = raca_nova;

            if (tipo_novo == "cachorro")
            {
                (*it).tipo_pet = cachorro;
                contador["Cachorros"]++;
            }
            else if (tipo_novo == "gato")
            {
                (*it).tipo_pet = gato;
                contador["Gatos"]++;
            }
            else if (tipo_novo == "passaro")
            {
                (*it).tipo_pet = passaro;
                contador["Passaros"]++;
            }
            else if (tipo_novo == "outro")
            {
                (*it).tipo_pet = outro;
                contador["Outras racas"]++;
            }
            break;
        }
    }
}

// Talvez não seja necessário tantos parâmetros, apagar depois
// Lembrar de tratar exceções, pro caso dos dados não baterem
// É necessário implementar número restante?
void Apartamento::editar_veiculo(string placa_antiga, string modelo_antigo, string tipo_veiculo_antigo,
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

// Lembrar de tratar exceções, pro caso dos dados não baterem
void Apartamento::excluir_pessoa(string nome_pessoa, string data_nascimento)
{
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++)
    {
        if ((*it).nome == nome_pessoa && (*it).data_nascimento == data_nascimento)
        {
            if(NumeroRestantePessoas < 15){
                if ((*it).tipo_pessoa == moradora){
                    contador["Moradores"]--;
                    NumeroRestanteMoradores++;
                }
                else if ((*it).tipo_pessoa == visitante){
                    contador["Visitantes"]--;
                    NumeroRestanteVisitantes++;
                }
                pessoas_.erase(it);
                NumeroRestantePessoas++;
                contador["Pessoas"]--;
                break;
            }
        }
    }
}

// Lembrar de tratar exceções, pro caso dos dados não baterem
// Lembrando que podemos retirar esse contadores de tipos, talvez seja desnecessário
void Apartamento::excluir_pet(string nome_pet, string raca, string tipo)
{
    for (auto it = pets_.begin(); it != pets_.end(); it++)
    {
        if(NumeroRestantePets < 3){
            if ((*it).nome == nome_pet && (*it).raca == raca)
            {
                if (tipo == "cachorro")
                {
                    contador["Cachorros"]--;
                }
                else if (tipo == "gato")
                {
                    contador["Gatos"]--;
                }
                else if (tipo == "passaro")
                {
                    contador["Passaros"]--;
                }
                else if (tipo == "outro")
                {
                    contador["Outras racas"]--;
                }
                pets_.erase(it);
                NumeroRestantePets++;
                contador["Pets"]--;
            }
        }
        break;
    }
}

// Lembrar de tratar exceções, pro caso dos dados não baterem
void Apartamento::excluir_veiculo(string placa)
{
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++)
    {
        if(NumeroRestanteVeiculos < 2){
            if ((*it).placa == placa)
            {
                veiculos_.erase(it);
                NumeroRestanteVeiculos++;
            }
        }
        break;
    }
}

// Não tenho certeza se é possível acessar o contador assim direto, visto que ele é privado
// apesar de ele estar no .cpp. De qq, forma, se não, alteremos depois
void Apartamento::exibir_estatisticas()
{
    cout << "Quantidades de moradores do prédio: " << contador["Moradores"] << endl;
    cout << "Quantidade de visitantes: " << contador["Visitantes"] << endl;
    cout << "Quantidade de pets: " << contador["Pets"] << endl;
    cout << "Quantidade de veículos: " << contador["Veículos"] << endl;
}
