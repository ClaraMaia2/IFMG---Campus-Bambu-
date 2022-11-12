#include "estudante.h"

//Construtor default
estudante :: estudante()
{
    id = 0;
    nome.resize(MAX_NOME_TAMANHO);
    nome = "";
}

//Construtor parametrizado
estudante :: estudante(int id, string nome)
{
    this->id = id;
    this->nome.resize(MAX_NOME_TAMANHO);    //Pega o atributo e muda o tamanho dele para, no m�ximo, 128 bytes
    this->nome = nome.substr(0, MAX_NOME_TAMANHO);
}

//Setters
void estudante :: setID(int i)
{
    id = i;
}

void estudante :: setNome(string n)
{
    this->nome.resize(MAX_NOME_TAMANHO);
    this->nome = n.substr(0, MAX_NOME_TAMANHO);
}

/*Constr�i uma string com o comprimento total de todos os atributos do objeto (calculado pelo m�todo size())
� importante calcular o tamanho dessa maneira para evitar que o compilador tente estimar o tamanho
Preenche a string com o caracter '\0' (nulo) para garantir que n�o haja nenhum res�duo armazenado na mem�ria que polua os dados, que poderiam ser interpretados incorretamente ao recuperar o objeto
Chama a fun��o replace() para a representa��o, passando os atributos do objeto como par�metro e seu tamanho, fazendo a convers�o de tipos de dados quando necess�rio
*/
string estudante :: toString()
{
    string repr;    //Criando um objeto

    repr.resize(this->size());  //Mudando o tamanho da vari�vel para 132 bytes (128 + 4 bytes)
    /*� necess�rio pois se a vari�vel "nome" for menor do que 132 bytes, n�o ter� lixo
    para ler e armazenar
    */
    repr.insert(0, this->size(), '\0');     //Inserir dentro da string um int de determinado valor, que nesse caso seria '\0' (caracter nulo)
    repr.replace(0, sizeof(int), reinterpret_cast<char*>(&id), sizeof(int));    //Substituir d0 byte 0 at� o byte do tamanho de int pelos valores de "id", s� que reinterpretando os valores para char
    repr.replace(sizeof(int), MAX_NOME_TAMANHO, nome);  //Do byte 4 at� o byte do tamanho m�ximo (128), vai ser substitu�do pelos valores da vari�vel "nome"

    return repr;
}

//Fazendo a desserializa��o do objeto
void estudante :: fromString(string repr)
{
    repr.copy(reinterpret_cast<char*>(&id), sizeof(int), 0);    //Copiando do objeto "repr" 4 bytes (come�ando do byte 0) para o tipo int (convertendo os dados para o tipo char, sendo visto como buffer de chars (string))
    nome = repr.substr(sizeof(int), MAX_NOME_TAMANHO);  //Copiar do objeto "repr" a por��o que armazena a string com o nome do estudante (come�ando do byte 4 at� o tamanho m�ximo do nome)
}

unsigned int estudante :: size()
{
    return sizeof(int) + MAX_NOME_TAMANHO;  //Retorna 4 bytes + 128 bytes = 132 bytes
}
