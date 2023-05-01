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

    #norma_F = norma(F(xk))

    Jacobiano = jacobiano(F, x)

    #Jacobiano_inverso = []

    xk1 = xk - Jacobiano_inverso(xk) * F(xk)

    while k<iterMax :
        xk = x0
        Jacobiano_inverso = []
        xk1 = xk - Jacobiano_inverso(xk) * F(xk)

        xk = xk1

        #Jf(xk)xk=f(xk)
    
    
    
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


# Metodo para resolver un sistema de ecuaciones
def resolver_sistema(M, b):
    

    solucion = np.linalg.solve(M, b)

    return solucion


# Metodo para derivar una expresion simbolica
def derivar(expresion, x):
    funcion = sp.Lambda(x, expresion)
    derivada = sp.diff(funcion(x), x)
    return derivada

# Metodo para evaluar una función sustituyendo x0 (constante) donde este x (variable)
def evaluar_funcion(funcion, x, x0):
    return funcion.subs(x, x0).evalf()


# Metodo para crear la matriz Jacobiana
def jacobiano(Funciones, variables):
    matriz_jacobiana = []
    if len(Funciones) == len(variables):
        n = len(variables)
        for i in range(n):
            fila = []
            for j in range(n):
                derivada = derivar(Funciones[i], variables[j])
                fila.append(derivada)
                #fila.append(evaluar_funcion(derivada, variables[j], 1))
            matriz_jacobiana.append(fila)
    else:
        print("El número de funciones debe ser igual al número de variables")
    return matriz_jacobiana


# Metodo para evaluar las variables de la matriz jacobiana
def evaluar_jacobiano(jacobiano, constantes, variables):
    if len(jacobiano) == len(constantes):
        n = len(constantes)
        for i in range(n):
            for j in range(n):
                jacobiano[i][j] = evaluar_funcion(jacobiano[i][j], variables[j], constantes[j])
    else:
        print("El número de funciones debe ser igual al número de variables")
    return jacobiano





################################################  TEST  ###################################################



"""
x1 = sp.symbols('x1')
x2 = sp.symbols('x2')
x = [x1, x2]
x0 = 0

f1 = (pow(np.e,(x1**2)) - pow(np.e,(np.sqrt(2)*x1)))
f2 = x1 - x2
F = [f1, f2]
tol = 1
iterMax = 1000

newton_raphson(x0, F, x, tol, iterMax)
"""

x = sp.symbols('x')
y = sp.symbols('y')
z = sp.symbols('z')
var = [x, y, z]

f1 = x**2 + y**2 + z**2 - 1
f2 = 2*(x**2) + y**2 - 4*z
f3 = 3*(x**2) - 4*y + z**2

c = [1, -2, 3]

#f1 = x*2 + 3*y - z*3
#f2 = 3*x - 4*y + 3*z
#f3 = 2*x - 4*y - 2*z

F = [f1, f2, f3]

b = [5, 8, 6]

J = jacobiano(F, var)

h = [1,1,1]

je = evaluar_jacobiano(J, h, var)



#s = resolver_sistema(je, b)
print(J)


