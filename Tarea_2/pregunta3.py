import sympy as sp
import numpy as np
from sympy import cos, sin, exp
from numpy import sqrt

from pregunta2 import Newton_Raphson

# f = sp.sympify('x**2 + y')
x1 = sp.symbols('x1')
x2 = sp.symbols('x2') 
x3 = sp.symbols('x3')
x4 = sp.symbols('x4') 

e = np.e

#a
f_a1 = e**(x1**2) - e**(sqrt(2)*x1)
f_a2 = x1 - x2

F_a = [f_a1, f_a2]
sol_a1 = (sqrt(2), sqrt(2))
sol_a2 = (0, 0)


#b
f_b1 = x1 + e**x2 - cos(x2)
f_b2 = 3*x1 - x2 - sin(x2)

F_b = [f_b1, f_b2]
sol_b = (0, 0)


#c
f_c1 = x1**2 - 2*x1 - x2 + 0.5
f_c2 = x1**2 + 4*(x2**2) - 4

F_c = [f_c1, f_c2]
sol_c = (1.9007, 0.3112)

#d
f_d1 = x1**2 + x2**2 - 1
f_d2 = x1**2 - x2**2 + 0.5

F_d = [f_d1, f_d2]
sol_d1 = (1/2, sqrt(3)/2)
sol_d2 = (1/2, -(sqrt(3)/2))

#e
f_e1 = sin(x1) + x2*cos(x1)
f_e2 = x1 - x2

F_e = [f_e1, f_e2]
sol_e = (0, 0)

#g
f_g1 = x2*x3 + x4*(x2 + x3)
f_g2 = x1*x3 + x4*(x1 + x3)
f_g3 = x1*x2 + x4*(x1 + x2)
f_g4 = x1*x2 + x1*x3 + x2*x3 - 1
 
F_g = [f_g1, f_g2, f_g3, f_g4]
sol_g1 = (-(1/sqrt(3)), -(1/sqrt(3)), -(1/sqrt(3)), (1/(2*sqrt(3))))
sol_g2 = ((1/sqrt(3)), (1/sqrt(3)), (1/sqrt(3)), -(1/(2*sqrt(3))))

"""
Newton_Raphson(1000, 10e-5, sol_a1, F_a)
Newton_Raphson(1000, 10e-5, sol_a2, F_a)

Newton_Raphson(1000, 10e-5, sol_b, F_b)

Newton_Raphson(1000, 10e-5, sol_c, F_c)

Newton_Raphson(1000, 10e-5, sol_d1, F_d)
Newton_Raphson(1000, 10e-5, sol_d2, F_d)

Newton_Raphson(1000, 10e-5, sol_g1, F_g)
Newton_Raphson(1000, 10e-5, sol_g2, F_g)
"""