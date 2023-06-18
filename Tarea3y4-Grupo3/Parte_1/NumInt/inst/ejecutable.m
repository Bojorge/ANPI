function ejecutable()
  % Prueba numericamente todas las funciones implementadas para aproximar el valor de la integral solicitada
  f = @(x) log(x) .* asin(x);  % Definimos la función f(x)
  a = 0.1;  % Límite inferior del intervalo
  b = 0.9;  % Límite superior del intervalo
  N = 20;   % Número de puntos de integración
  tol = 1e-6;  % Tolerancia para la convergencia
  iterMax = 10000;  % Número máximo de iteraciones

  % Calculamos el valor exacto de la integral utilizando cálculo simbólico
  Integral_Exacta = integral( f, a, b);

  % El método de trapecio_compuesto para aproximar la integral
  Test_trapecio_compuesto = trapecio_compuesto(f, a, b, N);
  disp("Aproximación numérica de la integral por trapecio_compuesto:");
  disp(double(Test_trapecio_compuesto));

  % El método de simpson_compuesto para aproximar la integral
  Test_simpson_compuesto = simpson_compuesto(f, a, b, N);
  disp("Aproximación numérica de la integral por simpson_compuesto:");
  disp(double(Test_simpson_compuesto));

  % El método de gaussiana_compuesta para aproximar la integral
  Test_gaussiana_compuesta = gaussiana_compuesta( f, a, b, N);
  disp("Aproximación numérica de la integral por gaussiana_compuesta:");
  disp(double(Test_gaussiana_compuesta));

  % El método de trapecio_compuesto_iterativo para aproximar la integral
  Test_trapecio_compuesto_iterativo = trapecio_compuesto_iterativo(f, a, b, N);
  disp("Aproximación numérica de la integral por trapecio_compuesto_iterativo:");
  disp(double(Test_trapecio_compuesto_iterativo));

  % El método de simpson_compuesto_iterativo para aproximar la integral
  Test_simpson_compuesto_iterativo = simpson_compuesto_iterativo(f, a, b, N, tol, iterMax);
  disp("Aproximación numérica de la integral por simpson_compuesto_iterativo:");
  disp(double(Test_simpson_compuesto_iterativo));

  % El método de gaussiana_compuesta_iterativa para aproximar la integral
  Test_gaussiana_compuesta_iterativa = gaussiana_compuesta_iterativa(f, a, b, N, tol, iterMax);
  disp("Aproximación numérica de la integral por gaussiana_compuesta_iterativa:");
  disp(double(Test_gaussiana_compuesta_iterativa));

  disp("Valor exacto de la integral:");
  disp(double(Integral_Exacta));

  % Comparación entre la aproximación numérica y el valor exacto

  numeric_approximation_trapecio_compuesta = double(Test_trapecio_compuesto);
  numeric_approximation_simpson_compuesta = double(Test_simpson_compuesto);
  numeric_approximation_gaussiana_compuesta = double(Test_gaussiana_compuesta);
  numeric_approximation_trapecio_compuesta_iterativo = double(Test_trapecio_compuesto_iterativo);
  numeric_approximation_simpson_compuesta_iterativo = double(Test_simpson_compuesto_iterativo);
  numeric_approximation_gaussiana_compuesta_iterativa = double(Test_gaussiana_compuesta_iterativa);

  numeric_exact_value = double(Integral_Exacta);

  error_trapecio_compuesto = abs(numeric_approximation_trapecio_compuesta - numeric_exact_value);
  error_simpson_compuesto = abs(numeric_approximation_simpson_compuesta - numeric_exact_value);
  error_gaussiana_compuesta = abs(numeric_approximation_gaussiana_compuesta - numeric_exact_value);
  error_trapecio_compuesta_iterativo = abs(numeric_approximation_trapecio_compuesta_iterativo - numeric_exact_value);
  error_simpson_compuesto_iterativo = abs(numeric_approximation_simpson_compuesta_iterativo - numeric_exact_value);
  error_gaussiana_compuesta_iterativa = abs(numeric_approximation_gaussiana_compuesta_iterativa - numeric_exact_value)

  disp("Error absoluto Metodo Trapecio Compuesto :");
  disp(error_trapecio_compuesto);
  disp("Error absoluto Metodo Simpson Compuesto :");
  disp(error_simpson_compuesto);
  disp("Error absoluto Metodo Gaussiana Compuesta :");
  disp(error_gaussiana_compuesta);
  disp("Error absoluto Metodo Trapecio Compuesto Iterativo:");
  disp(error_trapecio_compuesta_iterativo);
  disp("Error absoluto Metodo Simpson Compuesto Iterativo:");
  disp(error_simpson_compuesto_iterativo);
  disp("Error absoluto Metodo Gaussiana Compuesta Iterativa:");
  disp(error_gaussiana_compuesta_iterativa);
end

ejecutable()

