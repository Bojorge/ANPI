'''
Tarea #2 - ANPI
Alvaro Vargas M - 2018085151
'''

import numpy as np
import sympy as sp

def Newton_Raphson(max_iterations: int, tolerance: float, x_0: (float, float), f: []) -> None:
    '''
    This  function approximates the solution of a non-linear system using the Newton-Raphson method
    :param max_iterations: max amount of iterations to try on the succession
    :param tolerance: value of acceptable error of approximation
    :param x_0: Initial values
    :param f: List of functions that form the non-linear system to solve
    :return: Null
    '''

    '''General definitions'''
    max_iter = max_iterations
    tol = tolerance
    x, y = sp.symbols('x y') # Cambiar

    '''Initial value matrix'''
    x_ini = np.zeros((2,1))
    x_ini[0,0], x_ini[1,0] = x_0[0], x_0[1]

    '''Unevaluated Jacobian Matrix'''
    jacobian_matrix = np.matrix([[sp.diff(f[0],x), sp.diff(f[0],y)],
                                 [sp.diff(f[1],x), sp.diff(f[1],y)]])

    '''Function to evaluate the Jacobian Matrix'''
    def eval_jm(ex: float, ey: float) -> np.matrix:
        return np.matrix([[float(jacobian_matrix[0,0].evalf(subs = {x: ex, y: ey})),
                           float(jacobian_matrix[0,1].evalf(subs = {x: ex, y: ey}))],
                          [float(jacobian_matrix[1,0].evalf(subs = {x: ex, y: ey})),
                           float(jacobian_matrix[1,1].evalf(subs = {x: ex, y: ey}))]])

    '''Function to evaluate the given functions'''
    def eval_f(ex: float, ey: float) -> np.matrix:
        return np.matrix([[float(sp.simplify(f[0]).evalf(subs = {x: ex, y: ey}))],
                          [float(sp.simplify(f[1]).evalf(subs = {x: ex, y: ey}))]])

    '''Iterative loop'''
    for i in range(0, max_iter):
        # Gets X_k+1
        x_current = x_ini - np.linalg.solve(eval_jm(x_ini[0,0], x_ini[1,0]), eval_f(x_ini[0,0], x_ini[1,0]))

        # Error
        error = np.linalg.norm(eval_f(x_current[0,0],x_current[1,0]))

        # Check if current solution is good enough
        if abs(error) < tol:
            print('X_k aproximado:', x_current)
            print('Iteraciones:', i)
            print('Error:', error)
            break
        x_ini = x_current


Newton_Raphson(1000, 10e-5, (2.3, 2.3), ['exp(x**2) - exp(sqrt(2)*x)', 'x - y'])