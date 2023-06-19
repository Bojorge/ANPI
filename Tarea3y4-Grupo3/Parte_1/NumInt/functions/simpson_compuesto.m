function I=simpson_compuesto(f,a,b,n);
  % Aproximación numérica de la integral de una función en un intervalo mediante el metodo de Simpson compuesto, el cual divide en subitervalos y utiliza recursivamente para aplicar el metodo de Simpson a cada intervalo.
  % Sintaxys : simpson_compuesto(f,a,b,n)
  % Inputs:
  %    f = funcion a evaluar,
  %    a, b = intervalo [a, b],
  %    n = numero de puntos en los que se divide el intervalo [a, b]
  % Outputs:
  %    I =  I = Aproximacion numerica de la integral

  h=(b-a)/(n-1);
  xSoporte=a:h:b;
  I=0;
  for i=1:n-1
    I=I+simpson(f,xSoporte(i),xSoporte(i+1));
  end
end

function I = simpson(f, a, b)
  % Aproximación numérica de la integral de una función en un intervalo mediante el método de Simpson.
  % Sintaxis: I = simpson(f, a, b)
  % Inputs:
  %   f: función a evaluar
  %   a, b: límites de integración [a, b]
  % Output:
  %   I: aproximación numérica de la integral
  I = (b - a) / 6 * (f(a) + 4 * f((a + b) / 2) + f(b));
end


