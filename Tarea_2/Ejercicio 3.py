import numpy as np


def a(x1, x2):
    
    funcion_1 = (pow(np.e,(x1**2)) - pow(np.e,(np.sqrt(2)*x1)))
    funcion_2 = x1 - x2

    vector_funciones = [funcion_1, funcion_2]
    vector_solucion_1 = [1, 2]
    vector_solucion_2 = [1, 2]

    return vector_funciones, vector_solucion_1, vector_solucion_2




def b(x1, x2):
    funcion_1 = x1 + pow(e,x2) - np.cos(x2)
    funcion_2 = 3*x1 - x2 - np.sin(x2)

    vector_funciones = [funcion_1, funcion_2]
    vector_solucion = [1, 2]

    return vector_funciones, vector_solucion



def c(x1, x2):
    funcion_1 = pow(x1,2) - 2*x1 - x2 - 0.5 
    funcion_2 = pow(x1,2) + 4*pow(x2,2) -4

    vector_funciones = [funcion_1, funcion_2]
    vector_solucion = [1,2]

    return vector_funciones, vector_solucion



def d(x1, x2):
    funcion_1 = pow(x1, 2) + pow(x2,2) - 1
    funcion_2 = pow(x1, 2) - pow(x2,2) + 0.5

    vector_funciones = [funcion_1, funcion_2]
    
    vector_solucion_1 = [1, 2]
    vector_solucion_2 = [1, 2]

    return vector_funciones, vector_solucion_1, vector_solucion_2
    

def e(x1, x2):
    funcion_1 = np.sin(x1) + x2*np.cos(x1) 
    funcion_2 = x1 - x2

    vector_funciones = [funcion_1, funcion_2]
    vector_solucion = [1,2]

    return vector_funciones, vector_solucion

def g(x1, x2, x3, x4):
    funcion_1 = x2*x3 + x4*(x2 + x3)
    funcion_2 = x1*x3 + x4*(x1 + x3)
    funcion_3 = x1*x2 + x4*(x1 + x2)
    funcion_4 = x1*x2 + x1*x3 + x2*x3 -1 

    vector_funciones = [funcion_1, funcion_2, funcion_3, funcion_4]
    vector_solucion_1 = [[-1/(np.sqrt(3))],[-1/(np.sqrt(3))],[-1/(np.sqrt(3))],[1/(2*(np.sqrt(3)))]]
    vector_solucion_2 = [[1/(np.sqrt(3))],[1/(np.sqrt(3))],[1/(np.sqrt(3))],[-1/(2*(np.sqrt(3)))]]

    return vector_funciones, vector_solucion_1, vector_solucion_2

