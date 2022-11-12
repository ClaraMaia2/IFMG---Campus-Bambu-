# -*- coding: utf-8 -*-
"""
Calcular os erros absoluto e relativo das aproximações
Nome: Clara Araújo Maia
Questão 3 da Lista 1 de Cálculo Numérico
"""
def erro_absoluto(x, x_barra):
    return abs(x - x_barra)
#enddef

def erro_relativo(x, x_barra):
    return abs((x - x_barra) / x_barra)
#enddef

#Letra A
print('A) Erro absoluto = {} e Erro relativo = {}'.format(erro_absoluto(1.00001, 1), erro_relativo(1.00001, 1)))
print('-' * 22)

#Letra B
print('B) Erro absoluto = {} e Erro relativo = {}'.format(erro_absoluto(100001, 100000), erro_relativo(100001, 100000)))
print('-' * 22)

#Letra C
print('C) Erro absoluto = {} e Erro relativo = {}'.format(erro_absoluto(32.65483, 34.1645), erro_relativo(32.65483, 34.1645)))
print('-' * 22)

#Letra D
print('D) Erro absoluto = {} e Erro relativo = {}'.format(erro_absoluto(5.87135, 5.87049), erro_relativo(5.87135, 5.87049)))
print('-' * 22)