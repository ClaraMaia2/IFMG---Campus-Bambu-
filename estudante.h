#ifndef ESTUDANTE_H
#define ESTUDANTE_H
#include <string>

using namespace std;

/*Constante global
N�o est� usando #define porque se for usar, ele troca o valor antes de compilar,
de maneira que ele n�o se importa com o tipo da vari�vel ou constante
N�O FAZER VARI�VEL GLOBAL
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
    //M�todos para serializa��o
    string toString();  //Reconstruir o objeto. Passar os dados serializados (pega os dados da classe e os transforma em string para escrever no arquivo)
    void fromString(string repr);   //Retorna a representa��o dos dados
    //Unsigned ~> a vari�vel somente representa n�meros positivos e zero (n�o-negativos)
    unsigned int size();    //Fun��o que retorna o tamanho do dado

protected:
    int id;
    string nome;
};
#endif // ESTUDANTE_H
