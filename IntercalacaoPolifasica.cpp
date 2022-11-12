#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <list>

using namespace std;

//Função que vai criar as fitas de início e/ou limpá-las, caso existam
void reset_fita(string file_name)
{
    ofstream arquivo;
    arquivo.open(file_name.c_str(), std :: ios :: trunc);
    arquivo.close();
}

//Função de ordenação Bubble Sort
void bubble_sort(char *v, int quant)
{
    char aux;
    int trocou = 1;

    for (int i = 0; i < quant - 1 && trocou; i++)
    {
        trocou = 0;
        for (int j = 0; j < quant - 1 - i; j++)
        {
            if (v[j] < v[j + 1])
            {
                trocou = 1;
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

//Função que lerá o arquivo e vai pegar os seus caracteres
char ler_caracter(string arquivo, int indice)
{
    ifstream arq;
    arq.open(arquivo.c_str());
    int cont = 0;
    char caracter;

    while (cont <= indice)
    {
        arq >> caracter;
        cont++;
    }

    arq.close();

    return caracter;
}

//Função que adiciona char em um arquivo
void grava_char(char character, string nome_arq)
{
    ofstream arquivo;
    arquivo.open(nome_arq.c_str(), std :: ios :: app);  //Abrir um arquivo de escrita
    arquivo << character;
    arquivo.close();
}

//Função que fica alternando as fitas
int trocaFile(string &file_name)
{
    if (file_name == "fita1.txt")
    {
        file_name == "fita2.txt";
        return 0;
    }

    if (file_name == "fita2.txt")
    {
        file_name == "fita1.txt";
        return 0;
    }
}

//Função que vai pegar a entrada do teclado e retornar seu tamanho
int getInput(char *input)
{
    char c;
    int i = 0;

    do
    {
        c = getchar();

        if (c == '\n')
        {
            break;
        }
        if (c != ' ')
        {
            input[i] = c;
            i++;
        }
    }
    while (c != '\n');

    return i;
}

//Função que vai realizar a troca de um bloco
int trocar_bloco(int *cont_especial, list<char> &bloco, string &file_name, char *heap)
{
    //Se todos os cont_especial forem 1, irá ocorrer a troca de bloco
    if ((cont_especial[0] == 1) && (cont_especial[1] == 1) && (cont_especial[2] == 1))
    {
        cont_especial[0] = 0;
        cont_especial[1] = 0;
        cont_especial[2] = 0;
        bloco.push_back('#');

        //Armazena na fita
        while (!bloco.empty())
        {
            grava_char(bloco.front(), file_name);
            bloco.pop_front();
        }

        trocaFile(file_name);
        bubble_sort(heap, 3);

        return 1;
    }

    return 1;
}

//Função que retorna o índice de menor valor, e/ou retorna a comparação ocorrer entre um \0 ou um #
int menorValor(char *vetor, int *cont_compara)
{
    if (vetor[0] != '\0' && vetor[1] != '\0')
    {
        if (vetor[0] <= vetor[1] && vetor[0] != '#')
        {
            return 0;
        }
        else if (vetor[1] <= vetor[0] && vetor[1] != '#')
        {
            return 1;
        }
        else if (vetor[0] == '#' && vetor[1] != '#')
        {
            return 1;
        }
        else if (vetor[0] != '#' && vetor[1] == '#')
        {
            return 0;
        }
    }
    else if (vetor[0] == '\0' && vetor[1] != '\0')
    {
        return 1;
    }
    else if (vetor[1] == '\0' && vetor[0] != '\0')
    {
        return 0;
    }
    else
    {
        return 3;
    }
}

//Função de ordenação Heap Sort
void heap_sort(std :: list<char> &bloco, char *heap, int indice, int *cont_especial, int tam, char *entrada, std :: string &file_name)
{
    char aux;

    //Início do heap sort
    for (int i = 0; i <= tam; i++)
    {
        if ( i < tam)
        {
            bloco.push_back(heap[0]);   //Adicionando a posição 0 do heap no bloco
        }

        aux = heap[0];
        heap[0] = entrada[indice];
        indice++;

        //Condição: se o caracter que saiu é maior do que o que entrou
        if (aux > heap[0])
        {
            //Analisando os caracteres especiais
            if (cont_especial[2] == 0)
            {
                aux = heap[0];
                heap[0] = heap[2];
                heap[2] = aux;

                if (heap[0] > heap[1])
                {
                    aux = heap[0];
                    heap[0] = heap[1];
                    heap[2] = aux;
                }
                cont_especial[2]++;
            }
            //Analisando os caracteres especiais
            else if (cont_especial[1] == 0)
            {
                aux = heap[0];
                heap[0] = heap[1];
                heap[1] = aux;
                cont_especial[1]++;
            }
            //Analisando os caracteres especiais
            else if (cont_especial[0] == 0)
            {
                cont_especial[0]++;
            }
        }
        //Se o caracter que saiu for menor ou igual àquele que entrou
        else
        {
            //Se os 3 caracteres ainda são normais
            if (cont_especial[2] == 0)
            {
                bubble_sort(heap, 3);
            }
            //Se tem somente 2 caracteres normais
            else if (cont_especial[1] == 0)
            {
                if (heap[0] > heap[1])
                {
                    aux = heap[0];
                    heap[0] = heap[1];
                    heap[1] = aux;
                }
            }
        }

        trocar_bloco(cont_especial, bloco, file_name, heap);    //Quando todos os cont_especial forem igual a 1, cocorrerá uma mudança de bloco
    }
}

void interacao_polifasica(char *compara, std :: string &file1, std :: string file2, std :: string &file_vazio, int *cont_compara)
{
    char tempc[2];
    int temp;
    std :: string auxFile;

    while(1)
    {
        compara[0] = ler_caracter(file1, cont_compara[0]);
        compara[1] = ler_caracter(file2, cont_compara[1]);

        if (compara[0] == '#' && compara[1] == '#')
        {
            //O próximo valor poderá ser outro char ou um \0
            tempc[0] = ler_caracter(file1, cont_compara[0] + 1);
            tempc[1] = ler_caracter(file2, cont_compara[1] + 1);

            //Se entrar, irá terminar o programa (resetar as fitas)
            if (tempc[0] == '\0' && tempc[1] == '\0')
            {
                reset_fita(file1);
                reset_fita(file2);
                break;
            }
            else if (tempc[0] == '\0')
            {
                //Acabou a fita1 e ainda tem resto na fita2
                grava_char('\0', file_vazio);

                cont_compara[0] = 0;
                cont_compara[1]++;

                auxFile = file_vazio;   //Processo de troca de fitas
                file_vazio = file1;
                file1 = auxFile;

                reset_fita(file_vazio);
            }
            else if (tempc[1] == '\0')
            {
                //Acabou a fita2 e ainda tem resto na fita1
                grava_char('\0', file_vazio);

                cont_compara[1] = 0;
                cont_compara[0]++;

                auxFile = file_vazio;   //Processo de troca de fita
                file_vazio = file2;
                file2 = auxFile;

                reset_fita(file_vazio);
            }
            else
            {
                //O próximo char é um caracter
                cont_compara[0]++;
                cont_compara[1]++;

                grava_char('#', file_vazio);
            }
        }
        //Os calores são diferentes de #
        else
        {
            temp = menorValor(compara, cont_compara);

            //Se for igual a 3, vai encerrar o código e resetar as fitas
            if (temp == 3)
            {
                reset_fita(file1);
                reset_fita(file2);
                break;
            }
            else
            {
                grava_char(compara[temp], file_vazio);
                cont_compara[temp]++;
            }
        }
    }
}

int main(void)
{
    char input[27], heap[3], compara[2];
    int indice = 3, cont_especial[3] = {0, 0, 0}, cont_compara[2] = {0, 0}, tam, temp;
    //cont_especial serve para identificar quais os caracteres marcados
    std :: list<char> bloco;
    std :: string file_name = "fita1.txt";
    std :: string auxFile, file1, file2, file_vazio;

    //Resetando as fitas
    reset_fita("fita1.txt");
    reset_fita("fita2.txt");
    reset_fita("fita3.txt");

    tam = getInput(input);  //Obtendo a entrada e o tamanho do input

    heap[0] = input[0];
    heap[1] = input[1];
    heap[2] = input[2];

    bubble_sort(heap, 3);   //Organizando o primeiro heap usando o bubble sort

    heap_sort(bloco, heap, indice, cont_especial, tam, input, file_name);   //Ordenação de blocos

    grava_char('\0', "fita1.txt");
    grava_char('\0', "fita2.txt");

    //Início da interação polifásica
    file1 = "fita1.txt";
    file2 = "fita2.txt";
    file_vazio = "fita3.txt";

        interacao_polifasica(compara, file1, file2, file_vazio,cont_compara);   //Chamando a função que faz a interação polifásica
    }
