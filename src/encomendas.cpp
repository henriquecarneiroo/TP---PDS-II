#include "encomendas.hpp"
#include "apartamento.hpp"

#include <list>
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

// Verifica se o id é válido
bool verifica_id(string id){
    if (id.size() < 6 || id.size() > 50){ 
        return false;
    }
    return true;
}

void Encomendas::registrar_encomenda(string id, string destinatario, string data_entrega){
    Encomenda encomenda;
    if (verifica_id(id)){
        encomenda.data_entrega = data_entrega;
        encomenda.destinatario = destinatario;
        encomendas_[id] = encomenda;
        cout << "\nEncomenda registrada!\n" << endl;
        return;
    }
    cout << "Registro de encomenda falhou, ID inválido :(\n" << endl;
}

void Encomendas::apagar_encomenda(string id){
    bool apagado = false;
    if(encomendas_.size()>0){
    for (auto it = encomendas_.begin(); it != encomendas_.end(); it++){
        if (it->first == id){
            encomendas_.erase(it);
            apagado = true;
            return;
        }
    }
    }
    else{
        cout << "\nNão existem encomendas a serem apagadas\n" << endl;
    }
    if(!apagado){
        cout << "\nEncomenda não encontrada\n" << endl;
    }
}

void Encomendas::exibir_encomendas(){
    for (auto it = encomendas_.begin(); it != encomendas_.end(); it++){
        cout << "\nId: " << it->first << endl;
        cout << "Destinatario: " << it->second.destinatario << endl;
        cout << "Data de entrega: \n" << it->second.data_entrega << endl << endl;
    }
}

void Encomendas::procurar_encomenda(string id){
    if (verificar_encomenda(id)){
        for(auto it = encomendas_.begin(); it != encomendas_.end(); it++){
            if(it->first == id){
                cout << "\nDados da encomenda:\n" << "Id: " << it->first << "\nDestinatário: " << it->second.destinatario 
                << "\nData de entrega: " << it->second.data_entrega << "\n" << endl;
                return;
            }
        }
    } else {
        cout << "Essa encomenda não existe" << endl;
    }
}

bool Encomendas::verificar_encomenda(string id){
    for (auto it = encomendas_.begin(); it != encomendas_.end(); it++){
        if (it->first == id){
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
    // preenche os membros da encomenda com os valores fornecidos como argumentos para a função registrar_encomenda
    // necessário para criar uma nova encomenda com informações sobre a data de entrega e o destinatário.
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
