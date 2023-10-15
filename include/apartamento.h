#ifndef APARTAMNETO_H_
#define APARTAMENTO_H_

#include <list>
#include <string>

using std::list;
using std::string;

/* Coisas que podem ser adicionadas:
    - Um destruidor
    - Uma funçao que verifica se a pesssoa eh adm ou moradora para faciliar a
    implementacao das outras classes

   Consideracoes antes de alterar o codigo:
   - Nenhuma por enquanto
 */

class Apartamento {
    public:

    Apartamento(int max_Adm = 1, int max_Morador = 5, int max_Visitante = 10, 
                int max_Pet = 3, int max_Veiculo = 2);
    
    /* Construtor que permite definir limites máximos para diferentes tipos de 
    pessoas, pets e veículos*/

    void inserir_pessoa ();

    // Insere uma pessoa

    void inserir_pet ();

    // Insere um pet

    void inserir_veiculo ();

    // Insere um veiculo

    void editar_pessoa (string nome_pessoa);

    // Edita uma pessoa

    void editar_pet (string nome_pet);

    // Edita um pet

    void editar_veiculo (string placa);

    // Edita um veiculo

    void excluir_pessoa (string nome_pessoa);

    // Exclui uma pessoa

    void excluir_pet (string nome_pet);

    // Exclui um pet

    void excluir_veiculo (string placa);

    // Exclui um veiculo

    void exibir_estatisticas ();

    /*
    Exibe, de um modo geral as informacoes de um apartamento, como:
    - Estatísticas (por enquanto so a quantidade de cada objeto, com o passar
    do tempo podemos adicionar mais se quisermos)
    - Informações gerais de cada objeto
    */

    private:

    enum TipoPessoa {
        administradora,
        moradora,
        visitante,
    };

    struct Pessoa{
        string nome;
        string data_nascimento;
        TipoPessoa tipo_pessoa;
    };

    enum TipoPet {
        cachorro,
        gato,
        passaro,
        outro,
    };

    struct Pet {
        string nome;
        string raca;
        TipoPet tipo_pet;
    };

    struct Veiculo {
        string modelo;
        string placa;
        string tipo_veiculo;
    };

    list <Pessoa> pessoas_;
    list <Pet> pets_;
    list <Veiculo> veiculos_;

    // As variaveis abaixo sao limitadores de pessoas, pets e veiculos

    static const int MAX_ADM;
    static const int MAX_MORADORES;
    static const int MAX_VISITANTES;
    static const int MAX_PETS;
    static const int MAX_VEICULOS;

    int numeroAdm = 0;
    int numeroMoradores = 0;
    int numeroVisitantes = 0;
    int numeroPets = 0;
    int numeroVeiculos = 0;
};

#endif