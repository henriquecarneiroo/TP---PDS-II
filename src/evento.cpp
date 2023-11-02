#include "evento.hpp"
#include "apartamento.hpp"

#include <iostream>
#include <list>
#include <string>
#include <vector>

Evento::Evento(){
}

void Evento::criar_evento(string responsavel, string nome_evento, string data_evento){
    Agendamento novo_evento;
    novo_evento.responsavel = responsavel;
    novo_evento.nome_evento = nome_evento;
    novo_evento.data_evento = data_evento;
    eventos_.push_back(novo_evento);
}

//Pré-condição: convidados devem ser moradores ou visitantes
void Evento::adicionar_convidado(string nome_evento, string convidado){
    Apartamento ap;
    for (auto it = eventos_.begin(); it != eventos_.end(); it++){
        if ((*it).nome_evento == nome_evento && (ap.eh_morador(convidado) || ap.eh_visitante(convidado))){
            (*it).convidados.push_back(convidado);
        }
    }
}

void Evento::editar_evento(string responsavel, string nome_evento){
    for (auto it = eventos_.begin(); it != eventos_.end(); it++){
        if ((*it).responsavel == responsavel && (*it).nome_evento == nome_evento){
            string responsavel_aux, nome_evento_aux;
            cout << "Informe o novo responsável: ";
            cin >> responsavel_aux;
            cout << "Informe o novo nome do evento: ";
            cin >> nome_evento_aux;
            (*it).responsavel = responsavel_aux;
            (*it).nome_evento = nome_evento_aux;
            cout << "Evento alterado!" << endl;
        }
    }
}


void Evento::excluir_evento(string responsavel, string nome_evento) {
    eventos_.remove_if([responsavel, nome_evento](const Agendamento& evento) {
        return evento.responsavel == responsavel && evento.nome_evento == nome_evento;
    });
}

void Evento::exibir_evento(string responsavel, string nome_evento) {
    for (const auto& evento : eventos_) {
        if (evento.responsavel == responsavel && evento.nome_evento == nome_evento) {
            cout << "Responsável: " << evento.responsavel << endl;
            cout << "Nome do evento: " << evento.nome_evento << endl;
            cout << "Data do evento: " << evento.data_evento << endl;
            cout << "Convidados:" << endl;
            for (const string& convidado : evento.convidados) {
                cout << "  " << convidado << endl;
            }
        }
    }
}

void Evento::exibir_eventos(){
    for (auto it = eventos_.begin(); it != eventos_.end(); it++){
        cout << "Responsável: " << (*it).responsavel << endl;
        cout << "Nome do evento: " << (*it).nome_evento << endl;
        cout << "Data do evento: " << (*it).data_evento << endl;
        cout << "Convidados:" << endl;
        for (auto it2 = (*it).convidados.begin(); it2 != (*it).convidados.end(); it++){
            cout << (*it2) << " " << endl;
        }
        cout << "\n" << endl;
    }
}