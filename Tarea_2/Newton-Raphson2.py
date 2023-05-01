import numpy as np
import sympy as sp

def Newton_Raphson_TURBO(max_iterations: int, tolerance: float, x_0: (float, float), f: []) -> None:
    '''General definitions'''
    max_iter = max_iterations
    tol = tolerance
    x, y = sp.symbols('x y')

    '''Initial value matrix'''
    x_ini = np.zeros((2,1))
    x_ini[0,0], x_ini[1,0] = x_0[0], x_0[1]
    #print(x_ini)

    '''Unevaluated Jacobian Matrix'''
    jacobian_matrix = np.matrix([[sp.diff(f[0],x), sp.diff(f[0],y)],
                                 [sp.diff(f[1],x), sp.diff(f[1],y)]])
    print('Jacobian Matrix', jacobian_matrix)

    '''Function to evaluate the Jacobian Matrix'''
    def eval_jm(ex: float, ey: float) -> np.matrix:
        return np.matrix([[float(jacobian_matrix[0,0].evalf(subs = {x: ex, y: ey})), float(jacobian_matrix[0,1].evalf(subs = {x: ex, y: ey}))],
                          [float(jacobian_matrix[1,0].evalf(subs = {x: ex, y: ey})), float(jacobian_matrix[1,1].evalf(subs = {x: ex, y: ey}))]])
    #print(eval_jm(x_ini[0, 0], x_ini[1, 0]))

    '''Function to evaluate the given functions'''
    def eval_f(ex: float, ey: float) -> np.matrix:
        return np.matrix([[float(sp.simplify(f[0]).evalf(subs = {x: ex, y: ey}))],
                          [float(sp.simplify(f[1]).evalf(subs = {x: ex, y: ey}))]])
    #print(eval_f(x_ini[0, 0], x_ini[1, 0]))

    '''Iterative loop'''
    for i in range(0, 100): # ITERMAX DURA MUCHO
        # Gets X_k+1
        x_current = x_ini - np.linalg.solve(eval_jm(x_ini[0,0], x_ini[1,0]), eval_f(x_ini[0,0], x_ini[1,0]))
        #print(x_current)

        # Error
        error = np.linalg.norm(eval_f(x_current[0,0],x_current[1,0]))
        print(error)

        # Check if current solution is good enough
        if abs(error) < tol:
            print("SUCCESS")
            break
        x_ini = x_current


Newton_Raphson_TURBO(1000, 10e-5, (2.3, 2.3), ['exp(x**2) + exp(sqrt(2)*x)', 'x - y'])