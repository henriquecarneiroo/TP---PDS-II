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
            cout << "Morador inserido com sucesso\n";
        } else {
            cout << "Morador não inserido, número máximo atingido\n";
        }
        return;
    }
    if (tipo_pessoa == "visitante")
    {
        if(MAX_VISITANTES > 0){
            pessoa.tipo_pessoa = "visitante";
            pessoas_.push_back(pessoa);
            MAX_VISITANTES--;
            contador["Visitantes"]++;
            cout << "Visitante inserido com sucesso\n";
        } else {
            cout << "Morador não inserido, número máximo atingido\n";
        }
        return;
    } else {
        cout << "Inserção Falhou\n";
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
            cout << "Pet inserido com sucesso\n";
        }
        else if (tipo == "gato")
        {
            pet.tipo_pet = "gato";
            cout << "Pet inserido com sucesso\n";
        }
        else if (tipo == "passaro")
        {
            pet.tipo_pet = "passaro";
            cout << "Pet inserido com sucesso\n";
        }
        else if (tipo == "outro")
        {
            pet.tipo_pet = "outro";
            cout << "Pet inserido com sucesso\n";
        } else {
            cout << "Inserção Falhou\n";
        }

        pets_.push_back(pet);
        MAX_PETS--;
        contador["Pets"]++;
        return;
    } else {
        cout << "Pet não inserido, número máximo atingido\n";
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
        cout << "Veículo inserido com sucesso\n";
    } else {
        cout << "Veículo não inserido, número máximo atingido\n";
    }
}

void Apartamento::editar_pessoa(string nome_antigo,
                                string nome_novo, string data_nascimento_nova, string tipo_pessoa_novo){
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++){
        if (it->nome == nome_antigo){
            it->nome = nome_novo;
            it->data_nascimento = data_nascimento_nova;

            if (tipo_pessoa_novo == "moradora"){
                if(it->tipo_pessoa == "visitante"){
                    it->tipo_pessoa = "moradora";
                    contador["Visitantes"]--;
                    contador["Moradores"]++;
                    cout << "Edição concluída com sucesso\n";
                    return;
                } else if (it->tipo_pessoa == "moradora") {
                    cout << "Edição concluída com sucesso\n";
                    return;
                }
            } else if (tipo_pessoa_novo == "visitante"){
                if(it->tipo_pessoa == "moradora"){
                    it->tipo_pessoa = "visitante";
                    contador["Moradores"]--;
                    contador["Visitantes"]++;
                    cout << "Edição concluída com sucesso\n";
                    return;
                } else if (it->tipo_pessoa == "visitante"){
                    cout << "Edição concluída com sucesso\n";
                    return;
                }
            }
            break;
        }
    }
    cout << "Edição Falhou\n";
}

void Apartamento::editar_pet(string nome_pet_antigo,
                             string nome_pet_novo, string raca_nova, string tipo_novo){

    for (auto it = pets_.begin(); it != pets_.end(); it++){
        if (it->nome == nome_pet_antigo){
            it->nome = nome_pet_novo;
            it->raca = raca_nova;

            // Essa parte define o novo tipo de pet
            if (tipo_novo == "cachorro"){
                it->tipo_pet = "cachorro";
                cout << "Edição concluída com sucesso\n";
                return;
            } else if (tipo_novo == "gato"){
                it->tipo_pet = "gato";
                cout << "Edição concluída com sucesso\n";
                return;
            } else if (tipo_novo == "passaro"){
                it->tipo_pet = "passaro";
                cout << "Edição concluída com sucesso\n";
                return;
            } else if (tipo_novo == "outro"){
                it->tipo_pet = "outro";
                cout << "Edição concluída com sucesso\n";
                return;
            }
            break;
        }
    }
    cout << "Edição Falhou\n";
}

void Apartamento::editar_veiculo(string placa_antiga,
                                 string placa_nova, string modelo_novo, string tipo_veiculo_novo){
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++){
        if (it->placa == placa_antiga){
            it->modelo = modelo_novo;
            it->placa = placa_nova;
            it->tipo_veiculo = tipo_veiculo_novo;
            cout << "Edição concluída com sucesso\n";
            return;
            break;
        }
    }
    cout << "Edição Falhou\n";
}

// Exclui a pessoa e atualiza os contadores
void Apartamento::excluir_pessoa(string nome_pessoa){
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++){
        if (it->nome == nome_pessoa){
            if (it->tipo_pessoa == "moradora"){
                pessoas_.erase(it);
                contador["Moradores"]--;
                MAX_MORADORES++;
                cout << "Pessoa excluida com sucesso\n";
                return;
                break;
            }
            else if (it->tipo_pessoa == "visitante"){
                pessoas_.erase(it);
                contador["Visitantes"]--;
                MAX_VISITANTES++;
                cout << "Pessoa excluida com sucesso\n";
                return;
                break;
            }
        }
    }
    cout << "Exclusão Falhou\n";
}

// Lembrar de tratar exceções, pro caso dos dados não baterem
// Lembrando que podemos retirar esse contadores de tipos, talvez seja desnecessário
// Exclui um pet e atualiza os contadores

//Da para deixar so com o nome do pet 
void Apartamento::excluir_pet(string nome_pet){
    for (auto it = pets_.begin(); it != pets_.end(); it++){
        if(MAX_PETS < 3){
            if (it->nome == nome_pet){
                pets_.erase(it);
                MAX_PETS++;
                contador["Pets"]--;
                cout << "Pet excluido com sucesso\n";
                return;
            }
        }
        break;
    }
    cout << "Exclusão Falhou\n";
}

// Exclui um veículo e atualiza os contadores
void Apartamento::excluir_veiculo(string placa){
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++){
            if (it->placa == placa){
                veiculos_.erase(it);
                contador["Veiculos"]--;
                MAX_VEICULOS++;
                cout << "Veículo excluida com sucesso\n";
                return;
            }
        break;
    }
    cout << "Exclusão Falhou\n";
}

void Apartamento::exibir_estatisticas(){
    cout << "\nQuantidades de moradores: " << contador["Moradores"] << endl;
    cout << "Quantidade de visitantes: " << contador["Visitantes"] << "\n" << endl;
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++){
        cout <<"\tNome: "<< it->nome << endl <<"\tData de Nascimento: "<< it->data_nascimento << endl <<"\tTipo: "<< it->tipo_pessoa << "\n" << endl;
    }
    cout << "\nQuantidade de pets: " << contador["Pets"] << "\n" << endl;
    for (auto it = pets_.begin(); it != pets_.end(); it++){
        cout <<"\tNome: "<< it->nome << endl <<"\tRaca: "<< it->raca << endl <<"\tTipo Pet: "<< it->tipo_pet << "\n" << endl;
    }
    cout << "\nQuantidade de veículos: " << contador["Veiculos"] << "\n" << endl;
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++){
        cout <<"\tModelo: "<< it->modelo << endl <<"\tPlaca: "<< it->placa << endl <<"\tTipo Veiculo: "<< it->tipo_veiculo << "\n" << endl;
    }
}

// Retorna a quantidade de itens, a partir da chave passada, do contador
int Apartamento::quantidade(string chave){
    return contador[chave];
}

bool Apartamento::eh_morador(string nome){
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++){
        if (it->nome == nome && it->tipo_pessoa == "moradora"){
            return true;
        }
    }
    return false;
}

bool Apartamento::eh_visitante(string nome){
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++){
        if (it->nome == nome && it->tipo_pessoa == "visitante"){
            return true;
        }
    }
    return false;
}