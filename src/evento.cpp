#include "evento.hpp"
#include "apartamento.hpp"
#include <iostream>
#include <list>
#include <string>
#include <vector>

Evento::Evento(){
}

void Evento::criar_evento(Apartamento& ap,string responsavel, string nome_evento, string data_evento){

    Agendamento novo_evento;
    bool PessoaEncontrada = false;

    for(auto it = ap.pessoas_.begin(); it != ap.pessoas_.end(); it++){
        if(it->nome == responsavel){
            if(it->tipo_pessoa == "moradora"){
                novo_evento.responsavel = responsavel;
                novo_evento.nome_evento = nome_evento; 
                novo_evento.data_evento = data_evento;
                eventos_.push_back(novo_evento);
                cout << "\nEvento criado com sucesso\n" << endl;
            }
            else{
                //throw ExcecaoResponsavelNaoEhMorador{responsavel, it->tipo_pessoa};
                cout << "\nO responsável precisa ser morador\n" << endl;
                return;
            }
            PessoaEncontrada = true;
        }
    }
    if(!PessoaEncontrada){
        //throw ExcecaoPessoaNaoExiste{responsavel};
        cout << "\nPessoa não encontrada\n" << endl;
    }
    
    
};
//Pré-condição: convidados devem ser moradores ou visitantes
void Evento::adicionar_convidado(map<int,Apartamento>& ap, string evento, string convidado){
    bool pessoa_encontrada = false;

    for(auto it = ap.begin(); it != ap.end(); it++){ // passa por todos os apartamentos do map
        for(auto it2 = it->second.pessoas_.begin(); it2 != it->second.pessoas_.end(); it2++){ // passa por todas as pessoas do apartamento
            if(it2 -> nome == convidado){ // verifica se o nome do convidado existe no apartamento
                pessoa_encontrada = true;
                for(auto it3 = eventos_.begin(); it3 != eventos_.end(); it3++){ // procura o evento para adicionar o convidado
                    if(it3->nome_evento == evento){
                     it3 ->convidados.push_back(convidado); // adiciona o convidado ao evento
                     cout << "\nPessoa adicionada com sucesso\n" << endl;
                     return;   
                    }
                }
            }
        }
    }
    if(!pessoa_encontrada){
        cout << "\nPesssoa não encontrada\n" << endl;
    }
}
//Pré-condição: convidados devem ser moradores ou visitantes
/*
void Evento::adicionar_convidado(Apartamento& ap, string nome_evento, string convidado){
    bool PessoaEncontrada = false;
    for(auto it = ap.pessoas_.begin(); it != ap.pessoas_.end(); it++){
        if(it->nome == convidado){ // verifica se o nome do convidado está entre os moradores e visitantes
            for(auto i = eventos_.begin(); i != eventos_.end(); i++){
                if(i->nome_evento == nome_evento){
                    i->convidados.push_back(convidado);
                }
            }
            PessoaEncontrada = true;
        }
    }
    if(!PessoaEncontrada){
        //throw ExcecaoPessoaNaoExiste{convidado};
        cout << "\nPessoa não encontrada\n";
    } else {
        cout << "\nConvidado adicionado\n" << endl;
    }
}
*/

void Evento::editar_evento(Apartamento& ap, string responsavel, string nome_evento){
    for (auto it = eventos_.begin(); it != eventos_.end(); it++){
        if ((*it).responsavel == responsavel && (*it).nome_evento == nome_evento){
            string responsavel_aux, nome_evento_aux;
            cout << "Informe o novo responsável: ";
            cin >> responsavel_aux;
            cout << "Informe o novo nome do evento: ";
            cin >> nome_evento_aux;
            if (ap.eh_morador(responsavel_aux)){
                (*it).responsavel = responsavel_aux;
                (*it).nome_evento = nome_evento_aux;
                cout << "Evento alterado" << endl;
            } else {
                cout << "O novo responsavel nao existe\n";
            }
        }
    }
}


void Evento::excluir_evento(string responsavel, string nome_evento) {
    eventos_.remove_if([responsavel, nome_evento](const Agendamento& evento) {
        cout << "\nEvento excluido\n";
        return evento.responsavel == responsavel && evento.nome_evento == nome_evento;
    });
}

void Evento::exibir_evento(string responsavel, string nome_evento) {
    for (const auto& evento : eventos_) {
        if (evento.responsavel == responsavel && evento.nome_evento == nome_evento) {
            cout << "\nResponsável: " << evento.responsavel << endl;
            cout << "Nome do evento: " << evento.nome_evento << endl;
            cout << "Data do evento: " << evento.data_evento << endl;
            cout << "Convidados:" << endl;
            for (const string& convidado : evento.convidados) {
                cout << "  " << convidado << endl;
            }
            cout << endl; 
        }
    }
}

void Evento::exibir_eventos(){
    for (auto it = eventos_.begin(); it != eventos_.end(); it++){
        cout << "Responsável: " << (*it).responsavel << endl;
        cout << "Nome do evento: " << (*it).nome_evento << endl;
        cout << "Data do evento: " << (*it).data_evento << endl;
        cout << "Convidados:" << endl;
        for (auto it2 = (*it).convidados.begin(); it2 != (*it).convidados.end(); it2++){
            cout << (*it2) << " " << endl;
        }
        cout << "\n" << endl;
    }
}


/*
#include "evento.hpp"
#include "apartamento.hpp"

#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

Evento::Evento() {
}

void Evento::criar_evento(string responsavel, string nome_evento, string data_evento) {
    try {
        Agendamento novo_evento;
        novo_evento.responsavel = responsavel;
        novo_evento.nome_evento = nome_evento;
        novo_evento.data_evento = data_evento;

        // Verifica se o responsável já possui um evento com o mesmo nome
        for (const auto& evento : eventos_) {
            if (evento.responsavel == responsavel && evento.nome_evento == nome_evento) {
                throw runtime_error("Erro: Responsável já possui um evento com o mesmo nome.");
            }
        }

        eventos_.push_back(novo_evento);
        cout << "\nEvento criado com sucesso!\n" << endl;
    } catch (const exception& e) {
        cerr << "\nErro ao criar evento: " << e.what() << endl;
    }
}

void Evento::adicionar_convidado(string nome_evento, string convidado) {
    try {
        Apartamento ap;
        bool eventoEncontrado = false;

        for (auto& evento : eventos_) {
            if (evento.nome_evento == nome_evento) {
                eventoEncontrado = true;

                // Verifica se o convidado é morador ou visitante
                if (ap.eh_morador(convidado) || ap.eh_visitante(convidado)) {
                    evento.convidados.push_back(convidado);
                    cout << "Convidado adicionado ao evento com sucesso!" << endl;
                } else {
                    throw runtime_error("Erro: O convidado deve ser um morador ou visitante.");
                }
            }
        }

        if (!eventoEncontrado) {
            throw runtime_error("Erro: Evento não encontrado.");
        }
    } catch (const exception& e) {
        cerr << "\nErro ao adicionar convidado: " << e.what() << endl;
    }
}

void Evento::editar_evento(string responsavel, string nome_evento) {
    try {
        bool eventoEncontrado = false;

        for (auto& evento : eventos_) {
            if (evento.responsavel == responsavel && evento.nome_evento == nome_evento) {
                eventoEncontrado = true;

                string responsavel_aux, nome_evento_aux;
                cout << "Informe o novo responsável: ";
                cin >> responsavel_aux;
                cout << "Informe o novo nome do evento: ";
                cin >> nome_evento_aux;
                evento.responsavel = responsavel_aux;
                evento.nome_evento = nome_evento_aux;
                cout << "Evento alterado com sucesso!\n" << endl;
            }
        }

        if (!eventoEncontrado) {
            throw runtime_error("Erro: Evento não encontrado.");
        }
    } catch (const exception& e) {
        cerr << "\nErro ao editar evento: " << e.what() << endl;
    }
}

void Evento::excluir_evento(string responsavel, string nome_evento) {
    try {
        eventos_.remove_if([responsavel, nome_evento](const Agendamento& evento) {
            return evento.responsavel == responsavel && evento.nome_evento == nome_evento;
        });
        cout << "\nEvento excluído com sucesso!\n" << endl;
    } catch (const exception& e) {
        cerr << "\nErro ao excluir evento: " << e.what() << endl;
    }
}

void Evento::exibir_evento(string responsavel, string nome_evento) {
    try {
        bool eventoEncontrado = false;

        for (const auto& evento : eventos_) {
            if (evento.responsavel == responsavel && evento.nome_evento == nome_evento) {
                eventoEncontrado = true;

                cout << "Responsável: " << evento.responsavel << endl;
                cout << "Nome do evento: " << evento.nome_evento << endl;
                cout << "Data do evento: " << evento.data_evento << endl;

                if (!evento.convidados.empty()) {
                    cout << "Convidados:" << endl;
                    for (const string& convidado : evento.convidados) {
                        cout << "  " << convidado << endl;
                    }
                } else {
                    cout << "Nenhum convidado cadastrado." << endl;
                }

                cout << "----------------------------------\n" << endl;
            }
        }

        if (!eventoEncontrado) {
            throw runtime_error("Erro: Evento não encontrado.");
        }
    } catch (const exception& e) {
        cerr << "\nErro ao exibir evento: " << e.what() << endl;
    }
}

void Evento::exibir_eventos() {
    if (eventos_.empty()) {
        cout << "\nNenhum evento cadastrado.\n" << endl;
        return;
    }

    cout << "\nLista de Eventos:\n" << endl;

    for (const auto& evento : eventos_) {
        cout << "Responsável: " << evento.responsavel << endl;
        cout << "Nome do evento: " << evento.nome_evento << endl;
        cout << "Data do evento: " << evento.data_evento << endl;

        if (!evento.convidados.empty()) {
            cout << "Convidados:" << endl;
            for (const string& convidado : evento.convidados) {
                cout << "  " << convidado << endl;
            }
        } else {
            cout << "Nenhum convidado cadastrado." << endl;
        }

        cout << "----------------------------------\n" << endl;
    }
}
*/
