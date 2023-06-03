function ejecutable()
  % Prueba numericamente todas las funciones implementadas para aproximar el valor de la integral solicitada
  syms x;
  f = @(x) log(x) * asin(x);  % Definimos la función f(x)
  a = 0.1;  % Límite inferior del intervalo
  b = 0.9;  % Límite superior del intervalo
  N = 20;   % Número de puntos de integración
  tol = 1e-6;  % Tolerancia para la convergencia
  iterMax = 10000;  % Número máximo de iteraciones

  % Calculamos el valor exacto de la integral utilizando cálculo simbólico
  Integral_Exacta = int( f, x, a, b);

  % El método de gaussiana_compuesta para aproximar la integral
  Test_gaussiana_compuesta = gaussiana_compuesta( f, a, b, N);
  disp("Aproximación numérica de la integral por gaussiana_compuesta:");
  disp(double(Test_gaussiana_compuesta));

  % El método de gaussiana_compuesta_iterativa para aproximar la integral
  Test_gaussiana_compuesta_iterativa = gaussiana_compuesta_iterativa(f, a, b, N, tol, iterMax);
  disp("Aproximación numérica de la integral por gaussiana_compuesta_iterativa:");
  disp(double(Test_gaussiana_compuesta_iterativa));

  disp("Valor exacto de la integral:");
  disp(double(Integral_Exacta));

  % Comparación entre la aproximación numérica y el valor exacto
  numeric_approximation_gaussiana_compuesta = double(Test_gaussiana_compuesta);
  numeric_approximation_gaussiana_compuesta_iterativa = double(Test_gaussiana_compuesta_iterativa);

  numeric_exact_value = double(Integral_Exacta);

  error_gaussiana_compuesta = abs(numeric_approximation_gaussiana_compuesta - numeric_exact_value);
  error_gaussiana_compuesta_iterativa = abs(numeric_approximation_gaussiana_compuesta_iterativa - numeric_exact_value)

  disp("Error absoluto Metodo Gauss Compuesto :");
  disp(error_gaussiana_compuesta);
  disp("Error absoluto Metodo Gauss Compuesto Iterativo:");
  disp(error_gaussiana_compuesta);
end

ejecutable()

