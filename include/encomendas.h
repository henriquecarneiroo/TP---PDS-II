#ifndef ENCOMENDAS_H_
#define ENCOMENDAS_H_
#include "apartamento.h"

#include <list>
#include <string>
#include <vector>
#include <map>
class Encomendas{
    public:

    void registrar_encomenda (string id, string destinatario, string data_entrega);

    /* Permite inserir uma nova encomenda, informando o seu id, que não pode ter menos de
    6 caracteres e nem mais de 50, o destinatário que deve ser um morador do prédio, caso
    não seja, a encomenda não será registrada, e a data de entrega
    */

    void apagar_encomenda (string id);

    /* Permite apagar uma encomenda, o seu id deve ser fornecido, caso ele não exista, nada
    acontecerá */

    void exibir_encomendas ();
    /*tirei o parâmetro id pq não precisa dele pra exibir as encomendas*/
    /* Permite exibir todas as encomendas existentes */

    bool verificar_encomenda (string id);

    /* Permite permite verificar se uma encomenda existe ou não  */

    private:

    struct Encomenda {
        string destinatario;
        string data_entrega;
    };

    std::map <string, Encomenda> encomendas_;

};

#endif