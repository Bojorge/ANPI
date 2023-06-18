import numpy as np
import matplotlib.pyplot as plt
import time

def edo2(p, q, f, h, a, b, y0, yn):
    """
    Resuelve una ecuación diferencial de segundo orden utilizando el método de diferencias finitas.

    Parámetros:
    p : función
        Función que define el coeficiente p(x) en la ecuación diferencial y'' = p(x)y' + q(x)y + f(x).
    q : función
        Función que define el coeficiente q(x) en la ecuación diferencial y'' = p(x)y' + q(x)y + f(x).
    f : función
        Función que define el término f(x) en la ecuación diferencial y'' = p(x)y' + q(x)y + f(x).
    h : float
        Tamaño del paso en el intervalo [a, b].
    a : float
        Valor inicial del intervalo.
    b : float
        Valor final del intervalo.
    y0 : float
        Valor inicial de y(a).
    yn : float
        Valor final de y(b).

    Retorna:
    x : array
        Vector con los puntos x donde se calcula la solución aproximada.
    y : array
        Vector con los valores de la solución aproximada y en los puntos x.
    """

    n = int((b - a) / h)  # Número de puntos
    x = np.linspace(a, b, n+1)  # Vector de puntos x

    # Construir la matriz tridiagonal A
    A = np.zeros((n+1, n+1))
    A[0, 0] = 1.0
    A[n, n] = 1.0

    for i in range(1, n):
        A[i, i-1] = 1.0 - (h/2) * p(x[i])
        A[i, i] = -2.0 + h**2 * q(x[i])
        A[i, i+1] = 1.0 + (h/2) * p(x[i])

    # Construir el vector b
    b = np.zeros(n+1)
    b[0] = y0
    b[n] = yn

    for i in range(1, n):
        b[i] = h**2 * f(x[i])

    # Resolver el sistema de ecuaciones lineales
    y = np.linalg.solve(A, b)

    return x, y

def p(x):
    return -1 / x

def q(x):
    return (1 / (x**2)) - 1

def f(x):
    return 0

def solucion_exacta(x):
    return np.sin(6 - x) / (np.sin(5) * np.sqrt(x))

def script():
    # Parámetros de la ecuación diferencial
    h = 0.1
    a = 1
    b = 6
    y0 = 1
    yn = 0

    # Resolver la ecuación diferencial utilizando la función edo2
    x, y = edo2(p, q, f, h, a, b, y0, yn)

    # Imprimir los resultados
    for i in range(len(x)):
        print("x = {:.2f}, y = {:.6f}".format(x[i], y[i]))

    # Graficar la solución
    plt.plot(x, y, marker='o', label='Aproximación')
    plt.plot(x, solucion_exacta(x), label='Solución exacta')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Solución de la ecuación diferencial')
    plt.legend()
    plt.grid(True)
    plt.show()

def animacion():
    # Parámetros de la ecuación diferencial
    a = 1
    b = 6
    y0 = 1
    yn = 0

    hs = np.arange(1, 11)
    
    for h in hs:
        # Resolver la ecuación diferencial utilizando la función edo2
        x, y = edo2(p, q, f, h, a, b, y0, yn)

        # Graficar la solución
        plt.plot(x, y, marker='o', label='Aproximación (h={})'.format(h))
        plt.xlabel('x')
        plt.ylabel('y')
        plt.title('Aproximación de la ecuación diferencial (h={})'.format(h))
        plt.legend()
        plt.grid(True)
        plt.show()
        time.sleep(2)

# Llamar a la función script para resolver la ecuación diferencial y mostrar la solución
script()

# Esperar un segundo antes de comenzar la animación
time.sleep(1)

# Llamar a la función animacion para realizar la animación de las aproximaciones
animacion()

