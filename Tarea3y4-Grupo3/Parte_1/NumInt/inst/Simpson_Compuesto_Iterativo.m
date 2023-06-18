function I = simpson_compuesto_iterativo(f, a, b, n)
  % Aproximación numérica de la integral de una función en un intervalo mediante el método de Simpson compuesto iterativo.
  % Sintaxis: I = simpson_compuesto_iterativo(f, a, b, n)
  % Inputs:
  %   f: función a evaluar
  %   a, b: límites de integración [a, b]
  %   n: número de puntos en los que se divide el intervalo [a, b]
  % Output:
  %   I: aproximación numérica de la integral

  b - a) / (n - 1);
  xSoporte = a:h:b;
  ;
  for i = 1:n-1
    I + simpson(f, xSoporte(i), xSoporte(i+1));
  end
end
