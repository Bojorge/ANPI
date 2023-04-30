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
    print("")