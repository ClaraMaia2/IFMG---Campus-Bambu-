//Código que escreve e lê arquivos do tipo ask (.txt, bloco de notas, etc...)
#include <iostream>
#include <fstream>  //Incluindo automaticamente as 3 classes (ifstream, ofstream e fstream)

using namespace std;

int main()
{
    char c;
    int i;

    ofstream outFile("file.txt");   //Escrever em um arquivo
    ifstream inFile;    //Ler um arquivo

    //Evitando erros (se o arquivo realmente existir e/ou não é permitida a escrita)
    if (outFile.is_open())
    {
        for (i = 0; i < 10; i++)
        {
            cout << "Digite um caracter: ";
            cin >> c;
            outFile << c << endl;   //Escrevendo o caracter no arquivo
        }

        //Se abriu, feche
        outFile.close();
    }

    inFile.open("file.txt");    //Abrindo o mesmo arquivo file.txt para fazer a leitura dele

    //Evitar erros (se o arquivo existe e/ou não é permitida a leitura)
    if (inFile.is_open())
    {
        while (inFile >> c)     //O operador >> vai extrair para a variavel os dados presentes no arquivo
        {
            cout << c << endl;
        }

        //Se fizer dessa forma, o ultimo caracter aparece repetido (eof() -> fim de arquivo)
        /*while (!inFile.eof())
        {
            inFile >> c;
            cout << c << endl;
        }
        */

        //Se abriu, feche
        inFile.close();
    }

    return 0;
}
//Não lê e escreve arquivos em binário (.docx, word, etc...)
