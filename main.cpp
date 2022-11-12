#include <iostream>
#include <string>
#include <fstream>
#include "estudante.cpp"

using namespace std;

int main()
{
    estudante e(123456, "Jonh Doe"), e2;
    string serializedEstudante = e.toString();
    char *aux = new char[e.size()];     //Criando uma string tradicional com tamanho de 132 bytes
    fstream file("estudante.dat", ios :: in | ios :: out | ios :: ate | ios :: binary);

    if (!file.is_open())
    {
        file.open("estudante.dat", ios :: out);
        file.close();
        file.open("estudante.dat", ios :: in | ios :: out | ios :: ate | ios :: binary);
    }

    file.seekp(0, ios :: beg);  //Posicionar a cabe�a de escrita no in�cio do arquivo (movimentar 0 bytes a partir do in�cio do arquivo)
    file.write(serializedEstudante.c_str(), e.size());  //Escrever a string serializada (o m�todo write n�o espera uma string, ent�o usa a fun��o c_str() para convert�-la para char*), do tamanho de 132 bytes

    file.seekg(0, ios :: beg);  //POsicionar a cabe�a de leitura do byte 0 a partir do come�o
    file.read(aux, e.size());   //Ler para aux (buffer tempor�rio) do arquivo para 132 bytes (guardar em aux)

    serializedEstudante = string(aux, e2.size());   //Desserializar o objeto convertendo ele para string padr�o de C++ de aux do tamanho de 132 bytes
    e2.fromString(serializedEstudante);

    //As duas sa�das tem que estar iguais
    cout << "=============================================" << endl;
    cout << "Estudante Original: " << endl;
    cout << "ID: " << e.getID() << endl;
    cout << "Nome: " << e.getNome() << endl;
    cout << "=============================================" << endl;
    cout << "Estudante lido pelo arquivo: " << endl;
    cout << "ID: " << e2.getID() << endl;
    cout << "Nome: " << e2.getNome() << endl;
    cout << "=============================================" << endl;

    //Desalocar o ponteiro "aux"
    if (aux)
    {
        delete[] aux;
        aux = nullptr;
    }

    return 0;
}
