#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //Variável 'a' na memória = 00000000 00000000 00000000 01000001 (4 bytes)
    int i, a = 65, pos = 0;
    /*ios :: in -> abrir o arquivo para leitura
    ios :: out -> abrir o arquivo para escrita
    ios :: ate -> abre e posiciona o final do arquivo (trabalha com leitura e gravação)
    ios :: binary -> abrir o arquivo em binário (setar o fim do arquivo)
    */
    fstream file("data.dat", ios :: in | ios :: out | ios :: ate | ios :: binary);  //Instância da variável file do tipo fstream
    //O arquivo file tem duas "cabeças", a cabeça de leitura e a de escrita

    //Condição: se o arquivo não existir
    if (!file.is_open())
    {
        file.open("data.dat", ios :: out);  //Abrir para criar o arquivo
        file.close();
        file.open("data.dat", ios :: in | ios :: out | ios :: ate | ios :: binary);     //Se o arquivo existir, garante que ele seja aberto
    }
    if (file.is_open())
    {
        //file.good() ~> verifica se tem falha na escrita no arquivo (falha no disco)
        for (i = 0; i < 10 && file.good(); i++)
        {
            pos = i * 4;    //Escrever de 4 em 4 bytes

            //Mover de 4 em 4 bytes
            file.seekp(pos);    //Move a cabeça de escrita para o byte designado

            /*Mesmo que a variável 'a' seja do tipo int, o programa irá interpretá-lo como char, temporariamente
            Sempre tem que especificar o tamanho do tipo int (sizeof() ~> quantos bytes tem no tipo da variável)
            */
            file.write(reinterpret_cast<char*>(&a), sizeof(int));   //Escreve um número específico de bytes (chars) para o arquivo

            //Incrementando a variável 'a' (no arquivo vai aparecer os caracteres que tem o tamanho de bytes respectivos)
            a++;
        }

        //Atribuindo um valor arbitrário à variável 'a' para mostrar a leitura
        cout << "===== Mostrando que o arquivo leu corretamente, mudando o valor de 'a' =====" << endl;
        a = 1000;
        cout << "a: " << a << endl;     //Ele aparece como int, mesmo sendo convertido para char
        pos = 0;    //Resetando o valor da variável 'pos'

        for (i = 0; i < 10 && file.good(); i++)
        {
            pos = i * 4;
            file.seekg(pos);    //Movendo a cabeça de leitura para o byte designado

            /*Armazena o valor lido num ponteiro de char (read não retorna, só armazena)
            O método 'reinterpret_cast' exige um endereço ou um ponteiro
            */
            file.read(reinterpret_cast<char*>(&a), sizeof(int));    //Ler um número específico de bytes (chars) do arquivo
            cout << "Dados lidos da pos " << i << ": " << a << endl;
        }
        file.close();   //Fechando o arquivo
    }
    else
    {
        cerr << "Não foi possível abrir o arquivo." << endl;    //Escreve na saída padrão de erros ("primo" do cout)
    }

    return 0;
}
