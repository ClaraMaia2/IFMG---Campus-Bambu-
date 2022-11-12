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
    this->nome.resize(MAX_NOME_TAMANHO);    //Pega o atributo e muda o tamanho dele para, no máximo, 128 bytes
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

/*Constrói uma string com o comprimento total de todos os atributos do objeto (calculado pelo método size())
É importante calcular o tamanho dessa maneira para evitar que o compilador tente estimar o tamanho
Preenche a string com o caracter '\0' (nulo) para garantir que não haja nenhum resíduo armazenado na memória que polua os dados, que poderiam ser interpretados incorretamente ao recuperar o objeto
Chama a função replace() para a representação, passando os atributos do objeto como parâmetro e seu tamanho, fazendo a conversão de tipos de dados quando necessário
*/
string estudante :: toString()
{
    string repr;    //Criando um objeto

    repr.resize(this->size());  //Mudando o tamanho da variável para 132 bytes (128 + 4 bytes)
    /*É necessário pois se a variável "nome" for menor do que 132 bytes, não terá lixo
    para ler e armazenar
    */
    repr.insert(0, this->size(), '\0');     //Inserir dentro da string um int de determinado valor, que nesse caso seria '\0' (caracter nulo)
    repr.replace(0, sizeof(int), reinterpret_cast<char*>(&id), sizeof(int));    //Substituir d0 byte 0 até o byte do tamanho de int pelos valores de "id", só que reinterpretando os valores para char
    repr.replace(sizeof(int), MAX_NOME_TAMANHO, nome);  //Do byte 4 até o byte do tamanho máximo (128), vai ser substituído pelos valores da variável "nome"

    return repr;
}

//Fazendo a desserialização do objeto
void estudante :: fromString(string repr)
{
    repr.copy(reinterpret_cast<char*>(&id), sizeof(int), 0);    //Copiando do objeto "repr" 4 bytes (começando do byte 0) para o tipo int (convertendo os dados para o tipo char, sendo visto como buffer de chars (string))
    nome = repr.substr(sizeof(int), MAX_NOME_TAMANHO);  //Copiar do objeto "repr" a porção que armazena a string com o nome do estudante (começando do byte 4 até o tamanho máximo do nome)
}

unsigned int estudante :: size()
{
    return sizeof(int) + MAX_NOME_TAMANHO;  //Retorna 4 bytes + 128 bytes = 132 bytes
}
