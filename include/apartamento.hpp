#ifndef APARTAMENTO_HPP
#define APARTAMENTO_HPP

#include <list>
#include <map>
#include <string>
#include <iostream>

using namespace std;
using std::list;
using std::string;
using std::map;

class Apartamento {
public:
    Apartamento(int max_Moradores = 5, int max_Visitantes = 10,
                int max_Pets = 3, int max_Veiculos = 2);

    /* Construtor que permite definir limites máximos para diferentes tipos de
    pessoas, pets e veículos*/

    void inserir_pessoa(string nome, string data_nascimento, string tipo_pessoa);

    // Insere uma pessoa
    // Pré-condição: não há uma pessoa com o mesmo nome
    // dentro de um mesmo apartamento (associado ao número)

    void inserir_pet(string nome, string raca, string tipo);

    // Insere um pet
    // Pré-condição: não há um pet com o mesmo nome, raça e tipo
    // dentro de um mesmo apartamento (associado ao número)

    void inserir_veiculo(string modelo, string placa, string tipo_veiculo);

    // Insere um veiculo
    // Pré-condição: não há outro veículo com a mesma placa cadastrada
    // em nenhum outro apartamento

    void editar_pessoa(string nome_antigo, string data_nascimento_antiga, string tipo_pessoa_antigo,
                       string nome_novo, string data_nascimento_nova, string tipo_pessoa_novo);

    // Edita uma pessoa
    // Pré-condição: essa pessoa deve existir de acordo com os dados passados

    void editar_pet(string nome_pet_antigo, string raca_antiga, string tipo_antigo,
                        string nome_pet_novo, string raca_nova, string tipo_novo);

    // Edita um pet
    // Pré-condição: esse pet deve existir de acordo com os dados passados

    void editar_veiculo(string placa_antiga,
                        string placa_nova, string modelo_novo, string tipo_veiculo_novo);

    // Edita um veiculo
    // Pré-condição: esse veículo deve existir de acordo com os dados passados

    void excluir_pessoa(string nome_pessoa);

    // Exclui uma pessoa
    // Pré-condição: essa pessoa deve existir de acordo com os dados passados

    void excluir_pet(string nome_pet, string raca, string tipo);

    // Exclui um pet
    // Pré-condição: esse pet deve existir de acordo com os dados passados

    void excluir_veiculo(string placa);

    // Exclui um veiculo
    // Pré-condição: esse veículo deve existir de acordo com os dados passados

    void exibir_estatisticas();

    /*
    Exibe, de um modo geral as informacoes de um apartamento, como:
    - Estatísticas (por enquanto so a quantidade de cada objeto, com o passar
    do tempo podemos adicionar mais se quisermos)
    - Informações gerais de cada objeto
    */

   int quantidade(string);

   // Função que retorna a quantidade de algo específico dentro das classes
   // desde o número de pessoas, visitantes, moradores, pets, tipos de pets...

private:
    enum TipoPessoa
    {
        moradora,
        visitante,
    };

    struct Pessoa
    {
        string nome;
        string data_nascimento;
        TipoPessoa tipo_pessoa;
    };

    enum TipoPet
    {
        cachorro,
        gato,
        passaro,
        outro,
    };

    struct Pet
    {
        string nome;
        string raca;
        TipoPet tipo_pet;
    };

    struct Veiculo
    {
        string modelo;
        string placa;
        string tipo_veiculo;
    };

    int numero_apartamento;
    list <Pessoa> pessoas_;
    list <Pet> pets_;
    list <Veiculo> veiculos_;
    map <string , int> contador;
    
    friend class Evento;
    friend class Encomendas;

    /*
    fiz algumas pesquisas e não tem como declarar essas funções privadas do 
    jeito que eu queria, que era o mesmo que declara os métodos publicos, se
    alguém tiver alguma outra ideia será muito bem vinda, mas lembre de que
    uma função só pode executar uma coisa
    */

    // As variaveis abaixo sao limitadores de pessoas, pets e veiculos

    static const int MAX_MORADORES;
    static const int MAX_VISITANTES;
    static const int MAX_PETS;
    static const int MAX_VEICULOS;

    // Troquei o nome para ficar mais intuitivo

    int NumeroRestanteMoradores = 0;
    int NumeroRestanteVisitantes = 0;
    int NumeroRestantePets = 0;
    int NumeroRestanteVeiculos = 0;


};

#endif