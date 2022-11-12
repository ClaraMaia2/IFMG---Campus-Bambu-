#ifndef ESTUDANTE_H
#define ESTUDANTE_H
#include <string>

using namespace std;

/*Constante global
Não está usando #define porque se for usar, ele troca o valor antes de compilar,
de maneira que ele não se importa com o tipo da variável ou constante
NÃO FAZER VARIÁVEL GLOBAL
*/
const int MAX_NOME_TAMANHO = 128;   //Fixando o tamanho de nome

class estudante
{
public:
    estudante();    //Construtor default da classe
    estudante(int id, string nome);     //Construtor parametrizado da classe
    virtual ~estudante() {}     //Destrutor da classe
    //Getters
    int getID() const {return id;}
    string getNome() const {return nome;}
    //Setters
    void setID(int i);
    void setNome(string n);
    //Métodos para serialização
    string toString();  //Reconstruir o objeto. Passar os dados serializados (pega os dados da classe e os transforma em string para escrever no arquivo)
    void fromString(string repr);   //Retorna a representação dos dados
    //Unsigned ~> a variável somente representa números positivos e zero (não-negativos)
    unsigned int size();    //Função que retorna o tamanho do dado

protected:
    int id;
    string nome;
};
#endif // ESTUDANTE_H
