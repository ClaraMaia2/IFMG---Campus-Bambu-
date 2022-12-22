# -*- coding: utf-8 -*-
"""
Método do ponto fixo - método babilônico
"""
def g(x):
    return x / 2 + 5 / (2 * x)
#enddef

x = 2

print('k, x, xa, g(x), erro')
for k in range(5):
    xa = x; x = g(x); e = abs((x - xa) / max(x, 1))
    
    print('{k}, {x:.10f},'.format(k = k, x = x) + '{xa:.10f}, {fx:.10f}, {e:.10f}'.format(xa = xa, fx = g(x), e = e))
#endfor

"""
Método do ponto fixo - método de convergência
"""
import numpy as np

def f(x):
    return x * np.exp(x) - 10
#enddef

def g1(x):
    return x - 0.5 * f(x)
#enddef

x = 1.7; print('k, x, g1(x)')

for k in range(5):
    gx = g1(x); xa = x; x = g1(x)
    
    print('{k}, {x:.5f}, '.format(k = k + 1, x = xa) + '{gx:.5f}'.format(gx = gx))
