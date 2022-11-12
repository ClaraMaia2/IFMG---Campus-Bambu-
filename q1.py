# -*- coding: utf-8 -*-
"""
Algoritmo para converter números para outras bases
Nome: Clara Araújo Maia
Questão 1 da Lista 01 de Cálculo Numérico
"""
def octal_decimal(n):
    num = n
    valor_decimal = 0
    base = 1
    temp = num
    
    while temp:
        ultimo_digito = temp % 10
        temp = int(temp / 10)
        
        valor_decimal += ultimo_digito * base
        
        base = base * 8
    #endwhile
    
    return valor_decimal
#enddef

def binario_decimal(n):
    n1 = int(n)
    decimal, i, n = 0, 0, 0
    
    while n1 != 0:
        dec = n1 % 10
        decimal = decimal + dec * pow(2, i)
        n1 = n1 // 10
        i += 1
    #endwhile
    
    return decimal
#enddef

def decimal_binario(n):
    binario = ''
    
    while n > 0:
        binario += str(n % 2)
        n //= 2
    #endwhile
    
    return binario[:: -1]
#enddef
'''
def decimal_4(n):
    n = n // 4
    
    return n
'''

def decimal_hexadecimal(n):
    hexaDecinum = ['0'] * 100
    i = 0
    
    while n != 0:
        temp = 0
        temp = n % 16
        
        if temp < 10:
            hexaDecinum[i] = chr(temp + 48)
        #endif
        else:
            hexaDecinum[i] = chr(temp + 55)
            i = i + 1
        #endelse
        n = int(n / 16)
    #endwhile
    
    j = i - 1
    
    while j >= 0:
        print((hexaDecinum[j]), end="")
        j = j -1
    #endwhile
#enddef

def binario_hexadecimal(n):
    decimal = binario_decimal(n)
    
    return decimal_hexadecimal(decimal)
#enddef

'''
Letra A
'''
n1 = 425135
print('1) {} na base decimal é {}.'.format(n1, octal_decimal(n1)))
print()
n2 = 1001101.1101
print('2) {} na base decimal é {}.'.format(n2, binario_decimal(n2)))
print()
n3 = '12FA74C8'
n3Dec = int(n3, 16)
print('3) {} na base decimal é {}.'.format(n3, n3Dec))
print()

print('=' * 22)

'''
Letra B
'''
num = 126485
print('O número {} na base binária é {}.'.format(num, decimal_binario(num)))
print()
#print('O número {} na base quaternária é {}.'.format(num, quaternario)) 
print()
print('O número {} na base octa é {}.'.format(num, oct(num)))
print()
print('O número {} na base hexadecimal é {}.'.format(num, hex(num)))
print()

print('=' * 22)

'''
Letra C
'''
num = int(1010010.011)
#print('O número {} na base quaternária é {}.'.format(n, quaternario))
print()
print('O número {} na base octal é {}.'.format(num, oct(num)))
print()
print('O número {} na base decimal é {}.'.format(num, binario_decimal(num)))
print()
#print('O número {} na base hexadecimal é {}.'.format(num, binario_hexadecimal(num)))
