function I = gaussiana_compuesta_iterativa(f, a, b, M, tol, iterMax)
  % Aproximación numérica iterativa de la integral de una función en un intervalo mediante la fórmula de Gauss compuesta.
  % Sintaxis: I = gaussiana_compuesta_iterativa(f, a, b, M, tol, iterMax)
  % Inputs:
  %   f: función a integrar
  %   a, b: límites de integración [a, b]
  %   M: orden de la cuadratura (considerar un orden máximo de 10)
  %   tol: tolerancia para la convergencia del resultado
  %   iterMax: número máximo de iteraciones
  % Output:
  %   I: aproximación numérica de la integral de f en [a, b]

  % Inicializar variables
  I_prev = gaussiana_compuesta(f, a, b, M-1); % Valor de la aproximación anterior
  I = gaussiana_compuesta(f, a, b, M); % Valor de la aproximación actual
  iter = 1; % Contador de iteraciones

  while abs(I - I_prev) > tol && iter < iterMax
    I_prev = I; % Guardar el valor anterior
    I = gaussiana_compuesta(f, a, b, M); % Calcular nueva aproximación
    iter = iter + 1; % Incrementar contador de iteraciones
  end

  if iter == iterMax
    fprintf('No se alcanzó la convergencia después de %d iteraciones.', iter);
  end
end

