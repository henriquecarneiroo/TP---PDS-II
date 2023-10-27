#ifndef EVENTO_H_
#define EVENTO_H_
#include "apartamento.h"

#include <list>
#include <string>
#include <vector>
using namespace std;
class Evento {
    public:

    void criar_evento (string responsavel, string nome_evento, string data_evento);

    /*  Cria um evento, informando o nome do responsavel, o nome do evento e sua data
        Um responsavel nao pode ter em seu nome dois eventos com o mesmo nome
        Visitantes nao podem criar eventos
    */

    void adicionar_convidado (Apartamento& apartamento);

    /*  Adiciona um convidado ao evento, o apartamento dele deve ser passado*/

    void editar_evento (string responsavel, string nome_evento);

    /* Permite editar um evento*/
    
    void excluir_evento (string responsavel, string nome_evento);

    /* Permite exluir um evento da lista de eventos */

    void exibir_evento (string responsavel, string nome_evento);

    /* Exibe todas a informacoes do evento, como data e lista de convidados*/

    void exibir_eventos ();

    /* Exibe todos os eventos ja criados */

    private:

    struct Agendamento {
        string responsavel;
        string nome_evento;
        string data_evento;
        vector <string> convidados;
    };

    list <Agendamento> eventos_;
};

#endif

