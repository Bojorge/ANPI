function I = simpson_compuesto_iterativo(f, a, b, n, tol, iterMax)
  % Aproximación numérica de la integral de una función en un intervalo mediante el método de Simpson compuesto iterativo.
  % Sintaxis: I = simpson_compuesto_iterativo(f, a, b, n, tol, iterMax)
  % Inputs:
  %   f: función a evaluar
  %   a, b: límites de integración [a, b]
  %   n: número de puntos en los que se divide el intervalo [a, b]
  %   tol: tolerancia para la convergencia del resultado
  %   iterMax: número máximo de iteraciones
  % Output:
  %   I: aproximación numérica de la integral

  I_prev = 0; % Valor de la aproximación anterior
  I = simpson_compuesto(f, a, b, n); % Valor de la aproximación actual
  iter = 1; % Contador de iteraciones

  while abs(I - I_prev) > tol && iter < iterMax
    I_prev = I; % Guardar el valor anterior
    I = simpson_compuesto(f, a, b, n); % Calcular nueva aproximación con mayor número de puntos

    iter = iter + 1; % Incrementar contador de iteraciones
  end

  if iter == iterMax
    fprintf('No se alcanzó la convergencia después de %d iteraciones.', iter);
  end
end
