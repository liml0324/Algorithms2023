# -*- coding: utf-8 -*-
"""
Created on Sun Oct  8 22:47:20 2023

@author: 16836
"""

import math
import scipy
import numpy as np
import matplotlib.pyplot as plt
from scipy.misc import derivative

n = 2000

F1 = []

for i in range(0,n):
    F1.append((1.0, False))
    
print(type(F1[0][1]))

def f1(k):
    #print("in f1" + str(k))
    k = int(k)
    if k >= n:
        return 1
    if k < len(F1):
        if F1[int(k)][1]:
            return F1[k][0]
    x = 0
    for i in range(k+1, n):
        x += f1(math.ceil(i*n/(n-i))) / i
    if k+1 <= n:
        x += 1/k
    if(1-x >= 0):
        return 1-x
    else:
        return 0

for i in range(n-1, 0, -1):
    F1[i] = (f1(i), True)
    #print("append")
F1[0] = (0, True)
print("Done")
    
def f(x):
    x = (int)(x*n)
    #print(x)
    if x >= len(F1):
        return 1
    elif x <= 0:
        return 0
    else:
        return F1[x][0]
    
def f_g(x):
    return 
    
def g1(k, n):
    x = 0
    for t in range(k, 2*k+1):
        if(t == 0):
            continue
        if(t < n):
            x += f(k/(n-t))/t
        else:
            x += 1/t
    return f(k/n) + x

G=[]
for i in range(n):
    G.append(g1(i, n))

def g(x):
    if(x < 0):
        return 0
    return G[(int)(x*n)]
    #return scipy.integrate.quad(f, x, 2*x)
    
def dg(x):
    return derivative(g, x, dx = 1/n, order=3)

DG = []
for i in range(n // 2):
    DG.append(dg(i/n))
print((DG.index(max(DG))/n,max(DG)))

xs = []
for i in range(n // 2):
    xs.append(i/n)
xs = np.array(xs).astype(np.double)
series1 = np.array(DG).astype(np.double)

plt.plot(xs, series1, linestyle='-')

plt.show()