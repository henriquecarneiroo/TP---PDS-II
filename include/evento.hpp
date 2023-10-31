#ifndef EVENTO_HPP
#define EVENTO_HPP

#include <list>
#include <string>
#include <vector>
#include "apartamento.hpp"
using namespace std;

/**
 * @class Evento
 * Classe que organiza as operações realizadas nos Eventos
*/
class Evento {
    public:

    /**
     * @brief Construtor do tipo evento
     * 
    */
    Evento();
    
    /**
     * @brief Cria um evento, informando o nome do responsavel, o nome do evento e sua data
     * @pre Um responsavel nao pode ter em seu nome dois eventos com o mesmo nome. Visitantes nao podem criar eventos
    */
    void criar_evento (string responsavel, string nome_evento, string data_evento);

    /**
     * @brief Adiciona um convidado ao evento 
     * @pre O apartamento dele deve ser passado
    */
    void adicionar_convidado (/*Apartamento::Apartamento& apartamento*/);

    /**
     * @brief Permite editar um evento
    */
    void editar_evento (string responsavel, string nome_evento);

    /**
     * @brief Permite exluir um evento da lista de evento
    */
    void excluir_evento (string responsavel, string nome_evento);

    /**
     * @brief Exibe todas a informacoes do evento, como data e lista de convidados
    */
    void exibir_evento (string responsavel, string nome_evento);

    /**
     * @brief Exibe todos os eventos ja criados
    */
    void exibir_eventos ();

    private:

    /**
     * Variáveis que serão utilizadas nas funções
    */

    struct Agendamento {
        string responsavel;
        string nome_evento;
        string data_evento;
        vector <string> convidados;
    };

    list <Agendamento> eventos_;
};

#endif

