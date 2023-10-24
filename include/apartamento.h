#ifndef APARTAMNETO_H_
#define APARTAMENTO_H_

#include <list>
#include <map>
#include <string>
#include <iostream>
using std::list;
using std::string;

/* Coisas que podem ser adicionadas:
    - Um destruidor
    - Uma funçao que verifica se a pesssoa eh adm ou moradora para faciliar a
    implementacao das outras classes

   Consideracoes antes de alterar o codigo:
   - Nenhuma por enquanto
    
    Mudanças no último commit:
    adicionadas funções privadas, adicionados parâmetros nas funções
    incluindo alguns para dar mais segurança (como data de nascimento
    pra editar a pessoa)

    att.: Adicionando também a opção de alterar o tipo da pessoa, pet ou veículo para 
    que as funções fiquem mais completas;
    Removendo o tipo administradora, já que ela não vai mais existir
 */

class Apartamento
{
public:
    Apartamento(int max_Moradores = 5, int max_Visitantes = 10, int max_Pessoas = 15,
                int max_Pets = 3, int max_Veiculos = 2);

    /* Construtor que permite definir limites máximos para diferentes tipos de
    pessoas, pets e veículos*/

    void inserir_pessoa(string nome, string data_nascimento, string tipo_pessoa);

    // Insere uma pessoa

    void inserir_pet(string nome, string raca, string tipo);

    // Insere um pet

    void inserir_veiculo(string modelo, string placa, string tipo_veiculo);

    // Insere um veiculo

    void editar_pessoa(string nome_antigo, string data_nascimento_antiga, string tipo_pessoa_antigo,
                       string nome_novo, string data_nascimento_nova, string tipo_pessoa_novo);

    // Edita uma pessoa

    void editar_pet(string nome_pet_antigo, string raca_antiga, string tipo_antigo,
                        string nome_pet_novo, string raca_nova, string tipo_novo);

    // Edita um pet

    void editar_veiculo(string placa_antiga, string modelo_antigo, string tipo_veiculo_antigo,
                        string placa_nova, string modelo_novo, string tipo_veiculo_novo);

    // Edita um veiculo

    void excluir_pessoa(string nome_pessoa, string data_nascimento);

    // Exclui uma pessoa

    void excluir_pet(string nome_pet, string raca, string tipo);

    // Exclui um pet

    void excluir_veiculo(string placa);

    // Exclui um veiculo

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
   // Achei interessante implementar essa função por meio de um map que conta
   // a quantidade desses objetos, podendo ser muito útil com o desenvolvimento

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

    list<Pessoa> pessoas_;
    list<Pet> pets_;
    list<Veiculo> veiculos_;
    map<string,int> contador;

    /*
    fiz algumas pesquisas e não tem como declarar essas funções privadas do 
    jeito que eu queria, que era o mesmo que declara os métodos publicos, se
    alguém tiver alguma outra ideia será muito bem vinda, mas lembre de que
    uma função só pode executar uma coisa
    */

    // As variaveis abaixo sao limitadores de pessoas, pets e veiculos
    // Adicionei MAX_PESSOAS para facilitar implementações

    static const int MAX_MORADORES;
    static const int MAX_VISITANTES;
    static const int MAX_PESSOAS;
    static const int MAX_PETS;
    static const int MAX_VEICULOS;

    // Troquei o nome para ficar mais intuitivo

    int NumeroRestanteMoradores = 0;
    int NumeroRestanteVisitantes = 0;
    int NumeroRestantePessoas = 0;
    int NumeroRestantePets = 0;
    int NumeroRestanteVeiculos = 0;
};

#endif