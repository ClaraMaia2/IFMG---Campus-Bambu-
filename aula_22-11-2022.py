# -*- coding: utf-8 -*-
"""
Plotando um gráfico com uma função definida pelo usuário usando o método de Bolzano (uma única raiz)
"""
import numpy as np
import matplotlib.pyplot as pyplot

def eval_f(fx, x):  #Função que transforma uma equação string em uma função em Python
    return eval(fx)
#enddef

def plot(fx, a, b):     #Função que faz o plot de um gráfico da função definida pelo usuário
    intervalo = np.linspace(a, b)
    pyplot.plot(intervalo, eval_f(fx, intervalo))
    pyplot.grid()
    pyplot.show()
#enddef
 
funcao = input('Informe a função:')
a = float(input('Informe o ínicio do intervalo desejado:'))
b = float(input('Informe o fim do intervalo desejado:'))
plot(funcao, a, b)


"""
Plotando um gráfico com uma função pré-definida usando o método de bisseção
"""
import csv

def f(x):   #Função que define a expressão para qual buscamos a raiz
    return x ** 3 - 9 * x ** 2 + 22 * x - 15
#enddef

def bissecao(a, b, tol, n):      #Função que realiza o método da bisseção
    lista = []  #Lista para armazenar o resultado de todas as iterações
    x_anterior = float("nan")   #Inicialmente, não há um x anterior ("nan" = null)
    
    for i in range(n):  #Laço de repetição com as iterações
        x = (a + b) / 2     #Calcula x (ponto no meio do intervalo [a, b])
        fx = f(x)   #Armazenando o valor da função de expressão em uma variável (simplificar)
        sinal = f(a) * fx   
        erro = abs((x - x_anterior) / max(x, 1))    #Cálculo do erro relativo
        
        x_anterior = x  #Será usado na próxima iteração
        
        linha = {'Iteração': i, 'a': a, 'b': b, 'erro': erro, 'x': x, 'f(x)': fx, 'sinal':sinal}    #Dados da iteração atual
        lista.append(linha)     #Adiciona a linha atual à lista
        
        if fx == 0 or tol < erro:   #Testa a condição de parada: f(x) = 0 ou tolerância < erro
            break   #Interrompe o laço de repetição
        #endif
        
        if sinal > 0:   #Verifica se o sinal de f(a) * f(x) é menor que 0
            a = x   #Se for afirmativo, o próximo intervalo será [x, b]
        #endif
        else:
            b = x   #Se for negativo, o próximo intervalo será [a, x]
        #endelse
    #endfor
    return lista
#enddef

def salvaCSV(lista, nome_arquivo):  #Função que salva a lista de iterações em um arquivo CSV
    arquivo = open(nome_arquivo, 'w')   #Abre o arquivo
    cabecalho = ['Iteração', 'a', 'b', 'erro', 'x', 'f(x)', 'sinal']
    arq_csv = csv.DictWriter(arquivo, fieldnames = cabecalho)
    
    arq_csv.writeheader()
    arq_csv.writerows(lista)
#enddef

lista_it = bissecao(2, 3, 0.002, 20)
salvaCSV(lista_it, 'bissecao.csv')

for linha in lista_it:
    print(linha)
#endfor

print('Raiz aproximada:', linha['x'])
