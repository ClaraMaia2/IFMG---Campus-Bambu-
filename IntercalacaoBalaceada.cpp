#include <iostream>
#define TAM 3
using namespace std;

//Struct do buffer -> armazena o numero e a fita de onde o numero veio
typedef struct bf
{
    int elem;   //Numero a ser ordenado
    int fita;   //Fita de onde o numero veio
}Buffer;

//Funcao de ordenacao de um vetor
void insertionSort(int arr[], int n);

//Funcao de ordenacao de um vetor da struct Buffer
void insertionSortBuf(Buffer arr[], int n);

//Funcao que faz a primeira divisao
int dividirArquivos(FILE *entrada, FILE *arquivo1, FILE *arquivo2, FILE *arquivo3);

//Grava os elementos do buffer em um arquivo
void gravaBuffer(int bf[], int tamanho, FILE *arquivo);

//Junta, ordena e grava o bloco dos arquivos de entrada para o arquivo de saida
void ordenarBloco(FILE *entrada1, FILE *entrada2, FILE *entrada3, FILE *saida);

//Calcula quantas passadas serao necessarias fazer, baseado em quantos registros h� no arquivo de entrada
int passadas(float registros, int buffer);

//
void passadaArquivo(FILE *entrada1, FILE *entrada2, FILE *entrada3, FILE *saida1, FILE *saida2, FILE *saida3);

//Converte um arquivo com registros separados por /t para /n
void converterArquivoSaida(FILE *entrada, FILE *saida, int quantidade);

int main()
{
    int quant, pass, cont = 1;

    FILE *entrada, *f1, *f2, *f3, *f4, *f5, *f6, *saida;

    entrada = fopen("entrada.txt", "r");    //Abre o arquivo de entrada em modo de leitura
    f1 = fopen("f1.txt", "w");  //Abre a fita1 em modo de grava��o
    f2 = fopen("f2.txt", "w");  //Abre a fita 2 em modo de grava��o
    f3 = fopen("f3.txt", "w");  //Abre a fita3 em modo de grava��o

    quant = dividirArquivos(entrada, f1, f2, f3);   //faz a primeira divis�o do arquivo e pega o n�mero de registros dele

    //Fecha os arquivos
    fclose(entrada);
    fclose(f1);
    fclose(f2);
    fclose(f3);

    pass = passadas(quant, TAM);    //Calcula o numero de vezes que sera necessario ordenar apos a primeira divisao

    //Faz a passada de ordena��o quantas vezes for necessario de acordo com o calculo acima
    while (cont <= pass)
    {
        //Alterna os arquivos de entrada e de saida
        if (cont % 2 != 0)
        {
            f1 = fopen("f1.txt", "r");  //Abre a fita1 em modo de leitura
            f2 = fopen("f2.txt", "r");  //Abre a fita2 em modo de leitura
            f3 = fopen("f3.txt", "r");  //Abre a fita3 em modo de leitura
            f4 = fopen("f4.txt", "w");  //Abre a fita4 em modo de grava��o
            f5 = fopen("f5.txt", "w");  //Abre a fita5 em modo de grava��o
            f6 = fopen("f6.txt", "w");  //Abre a fita6 em modo de grava��o

            //Faz a chamada da fun��o de ordena��o, usando f1, f2 e f3 de entrada; e f4, f5 e f6 de saida
            passadaArquivo(f4, f5, f6, f1, f2, f3);

            //Fechando os arquivos
            fclose(f1);
            fclose(f2);
            fclose(f3);
            fclose(f4);
            fclose(f5);
            fclose(f6);
        }
        else
        {
            f1 = fopen("f1.txt", "w");  //Abre a fita1 em modo de grava��o
            f2 = fopen("f2.txt", "w");  //Abre a fita2 em modo de grava��o
            f3 = fopen("f3.txt", "w");  //Abre a fita3 em modo de grava��o
            f4 = fopen("f4.txt", "r");  //Abre a fita4 em modo de leitura
            f5 = fopen("f5.txt", "r");  //Abre a fita5 em modo de leitura
            f6 = fopen("f6.txt", "r");  //Abre a fita6 em modo de leitura

            //Chamando a fun��o de ordena��o, usando f4, f5 e f6 de entrada; e f1, f2 e f3 de saida
            passadaArquivo(f4, f5, f6, f1, f2, f3);

            //Fehca os arquivos
            fclose(f1);
            fclose(f2);
            fclose(f3);
            fclose(f4);
            fclose(f5);
            fclose(f6);
        }
        cont++;     //Incrementa o contador
    }

    //Converte o arquivo de saida separado por /t para /n
    saida = fopen("saida.txt", "w");    //Abre o arquivo de saida em modo de grava��o

    //Verifica se a saida esta no f1.txt ou f4.txt e converte o arquivo, armazenando o resultado em saida.txt
    if (pass % 2 == 0)
    {
        f1 = fopen("f1.txt", "r");  //Abre a fita1 em modo leitura

        converterArquivoSaida(f1, saida, quant);    //Converte a fita1 para o arquivo de saida

        fclose(f1);     //Fecha a fita1
    }
    else
    {
        f4 = fopen("f4.txt", "r");  //Abre a fita4 em modo de leitura

        converterArquivoSaida(f4, saida, quant);    //Converte a fita4 para o arquivo de saida

        fclose(f4);     //Fecha a fita4
    }

    fclose(saida);  //Fecha o arquivo de saida

    cout << "Arquivo ordenado!" << endl;    //Informa que o arquivo foi ordenado
    cout << "Arquivo de saida: saida.txt" << endl;  //Informa o arquivo de saida

    return 0;
}

/*M�todo de ordena��o Insertion Sort:
@param arr -> vetor de inteiros que sera ordenado
@param n -> quantidade de elementos no vetor para ordenar
*/
void insertionSort(int arr[], int n)    //Ordena��o de um vetor
{
    int i, key, j;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        i = i - 1;

        //Move elementos de arr[0...i - 1],que s�o maiores do que key, para uma posi��o a frente daquela que eles est�o
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

/* M�todo de ordena��o Insertion Sort da struct Buffer:
@param arr -> vetor de struct Buffer que ser� ordenado
@param n -> quantidade de elementos no vetor para ordenar
*/
void insertionSortBuf(Buffer arr[], int n)  //Ordena��o usando um vetor da struct Buffer
{
    int i, key, fita, j;

    for (i = 1; i < n; i++)
    {
        key = arr[i].elem;
        fita = arr[i].fita;
        j = i - 1;

        //Move elementos de arr[0...i - 1], que s�o maiores do que a key, para uma posi��o a frente do que eles est�o
        while (j >= 0 && arr[j].elem > key)
        {
            arr[j + 1].elem = arr[j].elem;
            arr[j + 1].fita = arr[j].fita;
            j = j - 1;
        }

        arr[j + 1].elem = key;
        arr[j + 1].fita = fita;
    }
}

/* Faz a primeira divis�o: divide o arquivo de entrada em arquivos menores e retorna a quantidade de n�meros do arquivo de entrada
@param entrada -> arquivo de entrada: primeira linha do arquivo indica quantas linhas tem nele (sem contar a primeira)
@param arquivo1 -> arquivo que ser� usado como fita 1
@param arquivo2 -> arquivo que ser� usado como fita 2
@param arquivo3 -> arquivo que ser� usado como fita 3
@return numero de registros do arquivo a serem ordenados
*/
int dividirArquivos(FILE *entrada, FILE *arquivo1, FILE *arquivo2, FILE *arquivo3)
{
    int buffer[TAM], indice, cont, i, quant = 0;

    if (entrada == 0)
    {
        cout << "Erro na abertura do arquivo." << endl;
        fclose(entrada);
    }
    else
    {
        indice = 0;
        cont = 1;
        fscanf(entrada, "%d\n", &quant);    //Pega o primeiro n�mero do arquivo, que indica a quantidade de n�meros a serem lidos

        for (i = 1; i <= quant; i++)
        {
            fscanf(entrada, "%d\n", &buffer[indice]);

            //Verifica se foram preenchidas as 3 posi��es do buffer
            if (i % TAM == 0)
            {
                insertionSort(buffer, TAM);     //Chamada da fun��o que ordena o buffer

                //Verifica qual a fita a ser gravada
                switch (cont)
                {
                case 1:
                    gravaBuffer(buffer, TAM, arquivo1);
                    putc('\n', arquivo2);   //Finaliza o bloco com uma quebra de linha
                    break;

                case 2:
                    gravaBuffer(buffer, TAM, arquivo2);
                    putc('\n', arquivo2);   //Finaliza o bloco com uma quebra de linha
                    break;

                case 3:
                    gravaBuffer(buffer, TAM, arquivo3);
                    putc('\n', arquivo3);   //Finaliza o bloco com uma quebra de linha
                    cont = 0;
                }

                indice = 0;     //Reseta o �ndice do buffer
                cont++;     //Incrementa o contador da fita
            }
            else
            {
                indice++;   //Incrementa o contador de �ndice do buffer
            }
        }

        //Verifica se sobraram n�meros no buffer a serem gravados
        if (quant % TAM != 0)
        {
            //Verifica qual a fita a ser gravada
            switch (cont)
            {
            case 1:
                //Grava o n�mero (se for apenas 1)
                if (quant % TAM == 1)
                {
                    fprintf(arquivo1, "%d", buffer[0]);
                }
                //Se forem 2 n�meros, os ordena e os grava
                else
                {
                    insertionSort(buffer, 2);
                    gravaBuffer(buffer, 2, arquivo1);
                }
                break;

            case 2:
                //Grava o n�mero (se for apenas 1)
                if (quant % TAM == 1)
                {
                    fprintf(arquivo2, "%d", buffer[0]);
                }
                //Se forem 2, os ordena e os grava
                else
                {
                    insertionSort(buffer, 2);
                    gravaBuffer(buffer, 2, arquivo2);
                }
                break;

            case 3:
                //Grava o n�mero (se for apenas 1)
                if (quant % TAM == 1)
                {
                    fprintf(arquivo3, "%d", buffer[0]);
                }
                //Se forem 2, os ordena e os grava
                else
                {
                    insertionSort(buffer, 2);
                    gravaBuffer(buffer, 2, arquivo3);
                }
            }
        }
    }
    return quant;
}

/* M�todo que grava o buffer (vetor de inteiros em n posi��es) em um arquivo
@param bf -> vetor de inteiros que ser� gravado
@param tamanho -> quantidade de elementos que ser� gravado
@param arquivo -> arquivo no qual os elementos ser�o gravados
*/
void gravaBuffer(int bf[], int tamanho, FILE *arquivo)
{
    //Grava o buffer na fita
    for (int i = 0; i < tamanho; i++)
    {
        fprintf(arquivo, "%d", bf[i]);

        if (i < tamanho - 1)
        {
            putc('\t', arquivo);    //Separa os elementos com tab
        }
    }
}

/* M�todo que grava  no arquivo de sa�da o bloco de elementos dos arquivos de entrada ordenados
@param entrada1 -> arquivo de entrada 1
@param entrada2 -> arquivo de entrada 2
@param entrada3 -> arquivo de entrada 3
@param saida -> arquivo de sa�da
*/
void ordenarBloco(FILE *entrada1, FILE *entrada2, FILE *entrada3, FILE *saida)
{
    int f1v, f2v, f3v;  //Vari�veis usadas para indicar se ainda h� n�meros no bloco
    char c;
    Buffer buffer[TAM];

    //Pega o primeiro n�mero do bloco
    if (fscanf(entrada1, "%d", &buffer[0].elem) == 1)
    {
        buffer[0].fita = 1;
        f1v = 1;
    }
    //Ou indica que n�o h� n�meros nesse bloco
    else
    {
        f1v = 0;
    }

    //Pega o primeiro n�mero do bloco
     if (fscanf(entrada2, "%d", &buffer[1].elem) == 1)
    {
        buffer[1].fita = 2;
        f2v = 1;
    }
    //Ou indica que n�o h� n�meros nesse bloco
    else
    {
        f2v = 0;
    }

    //Pega o primeiro n�mero do bloco
     if (fscanf(entrada3, "%d", &buffer[2].elem) == 1)
    {
        buffer[02].fita = 3;
        f3v = 1;
    }
    //Ou indica que n�o h� n�meros nesse bloco
    else
    {
        f3v = 0;
    }

    //Verifica se ainda tem n�meros no bloco
    while (f1v || f2v || f3v)
    {
        insertionSortBuf(buffer, f1v + f2v + f3v);  //Chamada da fun��o que ordena o buffer
        fprintf(saida, "%d", buffer[0].elem);   //Grava na sa�da o menor n�mero

        //Verifica de qual arquivo saiu o menor n�mero
        switch (buffer[0].fita)
        {
        case 1:
            c = fgetc(entrada1);

            //Se n�o houver mais n�meros no bloco, indica na vari�vel de validade do bloco e puxa as posi��es seguintes do buffer
            if (c != '\t')
            {
                f1v = 0;

                buffer[0].elem = buffer[1].elem;
                buffer[0].fita = buffer[1].fita;

                buffer[1].elem = buffer[2].elem;
                buffer[1].fita = buffer[2].fita;
            }
            //Se ainda houver, pega o pr�ximo n�mero e insere no buffer
            else
            {
                fscanf(entrada1, "%d", &buffer[0].elem);
            }
            break;

        case 2:
            c = fgetc(entrada2);

            //Se n�o houver mais n�meros no bloco, indica na vari�vel de validade do bloco e puxa as posi��es seguintes do buffer
            if (c != '\t')
            {
                f2v = 0;

                buffer[0].elem = buffer[1].elem;
                buffer[0].fita = buffer[1].fita;

                buffer[1].elem = buffer[2].elem;
                buffer[1].fita = buffer[2].fita;
            }
            //Se ainda houver, pega o pr�ximo n�mero e insere no buffer
            else
            {
                fscanf(entrada2, "%d", &buffer[0].elem);
            }
            break;

        case 3:
            c = fgetc(entrada3);

            //Se n�o houver mais n�meros no bloco, indica a vari�vel de validade do bloco e puxa as posi��es seguintes do buffer
            if (c != '\t')
            {
                f3v = 0;

                buffer[0].elem = buffer[1].elem;
                buffer[0].fita = buffer[1].fita;

                buffer[1].elem = buffer[2].elem;
                buffer[1].fita = buffer[2].fita;
            }
            //Se ainda houver, pega o pr�ximo n�emro e insere no buffer
            else
            {
                fscanf(entrada3, "%d", &buffer[0].elem);
            }
            break;
        }

        //Se ainda houver n�meros em algum dos blocos, adiciona um taba para separar os n�meros no arquivo
        if (f1v || f2v || f3v)
        {
            fputc('\t', saida);
        }
        //Caso contr�rio, quebra a linha
        else
        {
            fputc('\n', saida);
        }
    }
}

/* M�todo que calcula e retorna quantas passadas nos arquivos, ap�s a primeira divis�o, ser�o necess�rias para a ordena��o
@param registros -> n�mero de elementos do arquivo de entrada a serem ordenados
@param buffer -> n�mero de posi��es do buffer utilizado na ordena��o
@return n�mero de passadas que ser�o necess�rias para a ordena��o
*/
int passadas(float registros, int buffer)
{
    if (registros <= buffer)
    {
        return 0;
    }

    return 1 + passadas(registros / buffer, buffer);
}

/* M�todo que faz a ordena��o de todos os blocos de elementos dos arquivos de entrada para os arquivos de sa�da
@param registros -> n�mero de elementos do arquivo de entrada a serem ordenados
@param entrada1 -> arquivo de entrada 1
@param entrada2 -> arquivo de entrada 2
@param entrada3 -> arquivo de entrada 3
@param saida1 -> arquivo de sa�da 1
@param saida2 -> arquivo de sa�da 2
@param saida3 -> arquivo de sa�da 3
*/
void passadaArquivo(FILE *entrada1, FILE *entrada2, FILE *entrada3, FILE *saida1, FILE *saida2, FILE *saida3)
{
    int cont = 1;

    //Verifica se chegou ao fim dos 3 arquivos de entrada
    while (!feof(entrada1) && !feof(entrada2) && !feof(entrada3))
    {
        //Usa o contador para alternar entre os arquivos de sa�da
        switch (cont)
        {
        case 1:
            ordenarBloco(entrada1, entrada2, entrada3, saida1);     //Chamada da fun��o que passa os blocos dos arquivos de entrada, ordenados, para o arquivo de sa�da 1
            break;

        case 2:
            ordenarBloco(entrada1, entrada2, entrada3, saida2);     //Chamada da fun��o que passa os blocos dos arquivos de entrada, ordenados, para o arquivo de sa�da 2
            break;

        case 3:
            ordenarBloco(entrada1, entrada2, entrada2, saida3);     //Chamada da fun��o que passa os blocos dos arquivos de entrada, ordenados, para o arquivo de sa�da 3
            cont = 0;   //Reseta o contador
        }
        cont++;     //Incrementa o contador
    }
}

/* M�todo que faz a ordena��o de todos os blocos de elementos dos arquivos de entrada para os arquivos de sa�da
@param entrada -> arquivo de entrada
@param saida -> arquivo de sa�da
@param quantidade -> quantidade de elementos do arquivo de entrada
*/
void converterArquivoSaida(FILE *entrada, FILE *saida, int quantidade)
{
    int num;

    for (int i = 0; i < quantidade; i++)    //Executa n vezes, de acordo com a quantidade de registros do arquivo de entrada
    {
        fscanf(entrada, "%d", &num);    //Pega o n�mero do arquivo de entrada

        cout << num;    //Mostra os n�meros na tela

        fprintf(saida, "%d", num);  //N�mero no arquivo de sa�da

        //Verifica se n�o � o �ltimo n�mero
        if (i < quantidade - 1)
        {
            putc('\n', saida);  //Quebra a linha
        }
    }
}
