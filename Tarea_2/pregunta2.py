from matplotlib import pyplot as plt
import math
import numpy as np
import sympy as sp

################################################  ENTRADAS  ################################################
# vector inicial: x0
# vector de funciones: F
# vector de variables: x
# tolerancia: tol
# iteraciones maximas: iterMax


################################################  SALIDAS  ################################################
# vector que aproxima la solución del problema: xk
# cantidad de iteraciones: k
# error: ek
# grafica: iteraciones vs errores


def newton_raphson(x0, F, x, tol, iterMax):
    k = 0
    ek = 1
    xk = x0

    norma_F = norma(F(xk))

    Jacobiano = []
    Jacobiano_inverso = []

    xk1 = xk - Jacobiano_inverso(xk) * F(xk)

    while k<iterMax and tol>norma_F:
        xk = x0
        Jacobiano_inverso = []
        xk1 = xk - Jacobiano_inverso(xk) * F(xk)

    
    
    
    return xk, k, ek



def norma(Matriz):
    suma_cuadrados = 0

    # Calcular la suma de cuadrados de todos los elementos de la matriz
    for fila in Matriz:
        for elemento in fila:
            suma_cuadrados += elemento ** 2

    # Calcular la raíz cuadrada de la suma de cuadrados
    norma_dos = math.sqrt(suma_cuadrados)

    return norma_dos


################################################  TEST  ###################################################
x1 = sp.symbols('x1')
x2 = sp.symbols('y2')
x = [x1, x2]
x0 = 0

f1 = (pow(np.e,(x1**2)) - pow(np.e,(np.sqrt(2)*x1)))
f2 = x1 - x2
F = [f1, f2]
tol = 1
iterMax = 1000

#newton_raphson(x0, F, x, tol, iterMax)
