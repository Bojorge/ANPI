function I = gaussiana_compuesta( f, a, b, N)
  % Aproximación numérica de la integral de una función en un intervalo mediante la fórmula de Gauss.
  % Sintaxys : gaussiana_compuesta(f,a,b,N)
  % Inputs:
  %    a, b = intervalo [a, b],
  %    N = numero de puntos en los que se divide el intervalo [a, b]
  % Outputs:
  %    I =  I = Aproximacion numerica de (1)
  g = @(x) ((b-a)/2) * f( (b-a) / 2*x + (b+a)/2 );
  [x,w]=pesos_X_gauss(N);
  y=0;
  for i = 1:N
    y = y + w(i) * g(x(i));
  end
  I = y;
end

