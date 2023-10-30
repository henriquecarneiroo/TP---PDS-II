

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
     * @pre o id não pode ter menos de 6 caracteres e nem mais de 50 e se o destinatário nao existir, a encomenda nao sera registrada
    */
    bool registrar_encomenda (string id, string destinatario, string data_entrega);

    /**
     * @brief Permite apagar uma encomenda, o seu id deve ser fornecido
     * @pre o id deve existir, senao,nada acontecera
    */
    void apagar_encomenda (string id);

    /**
     * @brief Permite exibir todas as encomendas existentes
    */
    void exibir_encomendas ();

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