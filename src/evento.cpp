#include "evento.h"
#include "funcoes_auxiliares.h"

#include <iostream>
#include <list>
#include <string>
#include <vector>

void Evento::criar_evento(string responsavel, string nome_evento, string data_evento) {
    Agendamento novo_evento;
    novo_evento.responsavel = responsavel;
    novo_evento.nome_evento = nome_evento;
    novo_evento.data_evento = data_evento;
    eventos_.push_back(novo_evento);
}

//Pré-condição: convidados devem ser moradores ou visitantes
void Evento::adicionar_convidado(Apartamento& apartamento) {
    for (auto& it : eventos_) {
        if (it.responsavel == apartamento.getResponsavel()) {
            evento.convidados.push_back(apartamento.getNomeConvidado());
        }
    }
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

void Evento::excluir_evento(string responsavel, string nome_evento) {
    eventos_.remove_if([responsavel, nome_evento](const Agendamento& evento) {
        return evento.responsavel == responsavel && evento.nome_evento == nome_evento;
    });
}
