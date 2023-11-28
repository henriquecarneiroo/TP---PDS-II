#ifndef ENCOMENDAS_HPP
#define ENCOMENDAS_HPP

#include <list>
#include <string>
#include <vector>
#include <map>

using std::string;
using std::map;

/**
 * @class Encomendas 
 * Classe que organiza as operações realizadas nas Encomendas
*/
class Encomendas{
    public:

    /**
     * @brief Permite inserir uma nova encomenda, informando o seu id,o destinatário que deve ser um morador do prédio e a data 
     * de entrega
     * @pre O id não pode ter menos de 6 caracteres e nem mais de 50;
     * O destinatário deve ser um morador;
     * Se o destinatário não existir ou se não for um morador, a encomenda não será registrada
    */
    void registrar_encomenda (string id, string destinatario, string data_entrega);

    /**
     * @brief Permite apagar uma encomenda, o seu id deve ser fornecido
     * @pre O id deve existir, senão, nada acontecerá.
    */
    void apagar_encomenda (string id);

    /**
     * @brief Permite exibir todas as encomendas existentes
    */
    void exibir_encomendas ();

    /**
     * @brief Permite procurar uma encomenda registrada pelo seu id
     * e retornar os demais dados dessa encomenda
     * @pre A id deve ser válida
    */
    void procurar_encomenda (string id);

    /**
     * @brief Permite permite verificar se uma encomenda existe ou não
    */
    bool verificar_encomenda (string id);

    private:

    /**
     * Variáveis que serão utilizadas nas funções
    */
    struct Encomenda {
        string destinatario;
        string data_entrega;
    };

    std::map <string, Encomenda> encomendas_;

};

#endif