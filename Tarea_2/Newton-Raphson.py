import numpy as np
import sympy as sp
from matplotlib import pyplot as plt


def newton_raphson(max_iterations: int, tolerance: float, example: str, x_0, f) -> None:
    """
    This  function approximates the solution of a non-linear system using the Newton-Raphson method
    :param max_iterations: max amount of iterations to try on the succession
    :param tolerance: value of acceptable error of approximation
    :param example: Name of the example to run, used for plotting
    :param x_0: Initial values
    :param f: List of functions that form the non-linear system to solve
    :return: None
    """

    '''General definitions'''
    is_g = False
    max_iter = max_iterations
    tol = tolerance
    errors = []
    x1, x2, x3, x4 = sp.symbols('x1 x2 x3 x4')

    '''Checks if it is the example G'''
    if len(f) != 2:
        is_g = True

    '''Initial value matrix'''
    if is_g:
        x_ini = np.zeros((4, 1))
        x_ini[0, 0], x_ini[1, 0], x_ini[2, 0], x_ini[3, 0] = x_0[0], x_0[1], x_0[2], x_0[3]
    else:
        x_ini = np.zeros((2, 1))
        x_ini[0, 0], x_ini[1, 0] = x_0[0], x_0[1]

    '''Unevaluated Jacobian Matrix'''
    if is_g:
        jacobian_matrix = np.matrix([[sp.diff(f[0], x1), sp.diff(f[0], x2), sp.diff(f[0], x3), sp.diff(f[0], x4)],
                                     [sp.diff(f[1], x1), sp.diff(f[1], x2), sp.diff(f[1], x3), sp.diff(f[1], x4)],
                                     [sp.diff(f[2], x1), sp.diff(f[2], x2), sp.diff(f[2], x3), sp.diff(f[2], x4)],
                                     [sp.diff(f[3], x1), sp.diff(f[3], x2), sp.diff(f[3], x3), sp.diff(f[3], x4)]])
    else:
        jacobian_matrix = np.matrix([[sp.diff(f[0], x1), sp.diff(f[0], x2)],
                                     [sp.diff(f[1], x1), sp.diff(f[1], x2)]])

    '''Functions to evaluate the Jacobian Matrix'''

    def eval_jm(ex: float, ey: float) -> np.matrix:
        return np.matrix([[float(jacobian_matrix[0, 0].evalf(subs={x1: ex, x2: ey})),
                           float(jacobian_matrix[0, 1].evalf(subs={x1: ex, x2: ey}))],
                          [float(jacobian_matrix[1, 0].evalf(subs={x1: ex, x2: ey})),
                           float(jacobian_matrix[1, 1].evalf(subs={x1: ex, x2: ey}))]])

    def eval_jm_g(e1: float, e2: float, e3: float, e4: float) -> np.matrix:
        return np.matrix([[float(jacobian_matrix[0, 0].evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4})),
                           float(jacobian_matrix[0, 1].evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4})),
                           float(jacobian_matrix[0, 2].evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4})),
                           float(jacobian_matrix[0, 3].evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4}))],
                          [float(jacobian_matrix[1, 0].evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4})),
                           float(jacobian_matrix[1, 1].evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4})),
                           float(jacobian_matrix[1, 2].evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4})),
                           float(jacobian_matrix[1, 3].evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4}))],
                          [float(jacobian_matrix[2, 0].evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4})),
                           float(jacobian_matrix[2, 1].evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4})),
                           float(jacobian_matrix[2, 2].evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4})),
                           float(jacobian_matrix[2, 3].evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4}))],
                          [float(jacobian_matrix[3, 0].evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4})),
                           float(jacobian_matrix[3, 1].evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4})),
                           float(jacobian_matrix[3, 2].evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4})),
                           float(jacobian_matrix[3, 3].evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4}))]])

    '''Functions to evaluate the given functions'''

    def eval_f(ex: float, ey: float) -> np.matrix:
        return np.matrix([[float(sp.simplify(f[0]).evalf(subs={x1: ex, x2: ey}))],
                          [float(sp.simplify(f[1]).evalf(subs={x1: ex, x2: ey}))]])

    def eval_f_g(e1: float, e2: float, e3: float, e4: float) -> np.matrix:
        return np.matrix([[float(sp.simplify(f[0]).evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4}))],
                          [float(sp.simplify(f[1]).evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4}))],
                          [float(sp.simplify(f[2]).evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4}))],
                          [float(sp.simplify(f[3]).evalf(subs={x1: e1, x2: e2, x3: e3, x4: e4}))]])

    '''Iterative loop'''
    for i in range(0, max_iter):
        # Gets X_k+1
        if is_g:
            x_current = x_ini - np.linalg.solve(eval_jm_g(x_ini[0, 0], x_ini[1, 0], x_ini[2, 0], x_ini[3, 0]),
                                                eval_f_g(x_ini[0, 0], x_ini[1, 0], x_ini[2, 0], x_ini[3, 0]))
        else:
            x_current = x_ini - np.linalg.solve(eval_jm(x_ini[0, 0], x_ini[1, 0]), eval_f(x_ini[0, 0], x_ini[1, 0]))

        # Error
        if is_g:
            error = np.linalg.norm(eval_f_g(x_current[0, 0], x_current[1, 0], x_current[2, 0], x_current[3, 0]))
        else:
            error = np.linalg.norm(eval_f(x_current[0, 0], x_current[1, 0]))
        errors.append(error)

        # Check if current solution is good enough
        if abs(error) < tol:
            print('--Ejemplo ' + example + ' usando ' + str(x_0) + ' como valor inicial--')
            print('Xk aproximado: ', x_current)
            print('Iteraciones: ', i)
            print('Error: ', error)
            print('\n')

            # Iter vs Error
            plt.title('Iteraciones vs Error - Ejemplo ' + example + ' usando ' + str(x_0))
            plt.xlabel('Iteraciones ')
            plt.ylabel('Error ')
            plt.plot(range(i + 1), errors, 'b.')
            plt.ticklabel_format(style='sci', axis='y', scilimits=(0, 0))
            plt.show()

            break
        # Continues with a new iteration
        x_ini = x_current


# A
newton_raphson(1000, 10e-5, 'A', (2.3, 2.3), ['exp(x1 ** 2) - exp(sqrt(2) * x1)', 'x1 - x2'])
newton_raphson(1000, 10e-5, 'A', (1.8, 1.8), ['exp(x1 ** 2) - exp(sqrt(2) * x1)', 'x1 - x2'])
newton_raphson(1000, 10e-5, 'A', (0.8, 0.8), ['exp(x1 ** 2) - exp(sqrt(2) * x1)', 'x1 - x2'])

# B
newton_raphson(1000, 10e-5, 'B', (1.5, 2.0), ['x1 + exp(x2) - cos(x2)', '3 * x1 - x2 - sin(x2)'])
newton_raphson(1000, 10e-5, 'B', (0.3, 0.5), ['x1 + exp(x2) - cos(x2)', '3 * x1 - x2 - sin(x2)'])

# C
newton_raphson(1000, 10e-5, 'C', (3.0, 2.0), ['x1 ** 2 - 2 * x1 - x2 + 0.5', 'x1 ** 2 + 4 * (x2 ** 2) - 4'])
newton_raphson(1000, 10e-5, 'C', (1.6, 0.0), ['x1 ** 2 - 2 * x1 - x2 + 0.5', 'x1 ** 2 + 4 * (x2 ** 2) - 4'])

# D
newton_raphson(1000, 10e-5, 'D', (0.7, 1.2), ['x1 ** 2 + x2 ** 2 - 1', 'x1 ** 2 - x2 ** 2 + 0.5'])
newton_raphson(1000, 10e-5, 'D', (-1, -2.0), ['x1 ** 2 + x2 ** 2 - 1', 'x1 ** 2 - x2 ** 2 + 0.5'])

# E
newton_raphson(1000, 10e-5, 'E', (1.2,-1.5), ['sin(x1) + x2 * cos(x1)', 'x1 - x2'])
newton_raphson(1000, 10e-5, 'E', (-0.6,0.6), ['sin(x1) + x2 * cos(x1)', 'x1 - x2'])

# G
newton_raphson(1000, 10e-5, 'G', (-1, -1, -1, -1), ['x2 * x3 + x4 * (x2 + x3)',
                                                    'x1 * x3 + x4 * (x1 + x3)',
                                                    'x1 * x2 + x4 * (x1 + x2)',
                                                    'x1 * x2 + x1 * x3 + x2 * x3 - 1'])
newton_raphson(1000, 10e-5, 'G', (2., 2., 2., 0.), ['x2 * x3 + x4 * (x2 + x3)',
                                                    'x1 * x3 + x4 * (x1 + x3)',
                                                    'x1 * x2 + x4 * (x1 + x2)',
                                                    'x1 * x2 + x1 * x3 + x2 * x3 - 1'])
