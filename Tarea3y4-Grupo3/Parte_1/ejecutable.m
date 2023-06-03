function ejecutable()
  % Prueba numericamente todas las funciones implementadas para aproximar el valor de la integral solicitada
  syms x;
  f = @(x) log(x) * asin(x);  % Definimos la función f(x)
  a = 0.1;  % Límite inferior del intervalo
  b = 0.9;  % Límite superior del intervalo
  N = 3;   % Número de puntos de integración
  %N = 20;

  % Calculamos el valor exacto de la integral utilizando cálculo simbólico
  Integral_Exacta = int( f, x, a, b);

  % El método de gaussiana_compuesta para aproximar la integral
  Test_gaussiana_compuesta = gaussiana_compuesta( f, a, b, N);
  disp("Aproximación numérica de la integral:");
  disp(double(Test_gaussiana_compuesta));

  disp("Valor exacto de la integral:");
  disp(double(Integral_Exacta));

  % Comparación entre la aproximación numérica y el valor exacto
  numeric_approximation = double(Test_gaussiana_compuesta);
  numeric_exact_value = double(Integral_Exacta);
  error = abs(numeric_approximation - numeric_exact_value);
  disp("Error absoluto Metodo Gauss Compuesto :");
  disp(error);
end

ejecutable()

