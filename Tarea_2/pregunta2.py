import numpy as np
import sympy as sp
from matplotlib import pyplot as plt



def Newton_Raphson(max_iterations: int, tolerance: float, x_0, f) -> None:
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
    errors = []
    x1 = sp.symbols('x1')
    x2 = sp.symbols('x2') 
    x3 = sp.symbols('x3')
    x4 = sp.symbols('x4')

    '''Initial value matrix'''
    x_ini = np.zeros((2,1))
    x_ini[0,0], x_ini[1,0] = x_0[0], x_0[1]

    '''Unevaluated Jacobian Matrix'''
    jacobian_matrix = np.matrix([[sp.diff(f[0],x1), sp.diff(f[0],x2)],
                                 [sp.diff(f[1],x1), sp.diff(f[1],x2)]])

    '''Function to evaluate the Jacobian Matrix'''
    def eval_jm(ex: float, ey: float) -> np.matrix:
        return np.matrix([[float(jacobian_matrix[0,0].evalf(subs = {x1: ex, x2: ey})),
                           float(jacobian_matrix[0,1].evalf(subs = {x1: ex, x2: ey}))],
                          [float(jacobian_matrix[1,0].evalf(subs = {x1: ex, x2: ey})),
                           float(jacobian_matrix[1,1].evalf(subs = {x1: ex, x2: ey}))]])

    '''Function to evaluate the given functions'''
    def eval_f(ex: float, ey: float) -> np.matrix:
        return np.matrix([[float(sp.simplify(f[0]).evalf(subs = {x1: ex, x2: ey}))],
                          [float(sp.simplify(f[1]).evalf(subs = {x1: ex, x2: ey}))]])

    '''Iterative loop'''
    for i in range(0, max_iter):
        # Gets X_k+1
        x_current = x_ini - np.linalg.solve(eval_jm(x_ini[0,0], x_ini[1,0]), eval_f(x_ini[0,0], x_ini[1,0]))

        # Error
        error = np.linalg.norm(eval_f(x_current[0,0],x_current[1,0]))
        errors.append(error)

        # Check if current solution is good enough
        if abs(error) < tol:
            print('X_k aproximado:', x_current)
            print('Iteraciones:', i)
            print('Error:', error)

            #Iter vs Error
            plt.title("Iteraciones vs Error")
            plt.xlabel("Iteraciones ")
            plt.ylabel("Error ")
            plt.plot(range(i+1), errors, 'b.')
            plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
            plt.show()
            break
        x_ini = x_current
     
  

