#include <iostream>
#include <string>
#include <fstream>
#include "estudante.cpp"

using namespace std;

int main()
{
    estudante e(123456, "John Doe"), e2;
    string serializedEstudante = e.toString();
    char *aux = new char[e.size()];
    fstream file("estudante.dat", ios :: in | ios :: out | ios :: ate | ios :: binary);

    if (!file.is_open())
    {
        file.open("estudante.dat", ios :: out);
        file.close();
        file.open("estudante.dat", ios :: in | ios :: out | ios :: ate | ios :: binary);
    }

    file.seekp(0, ios :: beg);
    file.write(serializedEstudante.c_str(), e.size());

    file.seekg(0, ios :: beg);
    file.read(aux, e.size());

    serializedEstudante = string(aux, e2.size());
    e2.fromString(serializedEstudante);

    cout << "=====================================" << endl;
    cout << "Estudante Original: " << endl;
    cout << "ID: " << e.getID() << endl;
    cout << "Nome: " << e.getNome() << endl;
    cout << "=====================================" << endl;
    cout << "Estudante lido pelo arquivo: " << endl;
    cout << "ID: " << e2.getID() << endl;
    cout << "Nome: " << e2.getNome() << endl;

    if (aux)
    {
        delete[] aux;
        aux = nullptr;
    }

    return 0;
}
