function I=simpson_compuesto_iterativo(f,a,b,n)
  % Aproximación numérica de la integral de una función en un intervalo mediante el metodo de Simpson compuesto iterativo.
  % Sintaxys : simpson_compuesto_iterativo(f,a,b,n)
  % Inputs:
  %    a, b = intervalo [a, b],
  %    n = numero de puntos en los que se divide el intervalo [a, b]
  % Outputs:
  %    I =  I = Aproximacion numerica de la integral

  h=(b-a)/(n-1);
  xSoporte=a:h:b;
  I=0;
  a_i = a
  b_i = a+h

  for i=1:n-1
    I=I+(b_i-a_i)/6*(fnum(a_i)+4*fnum((a_i+b_i)/2)+fnum(b_i));
    a_i=a_i+h;
    b_i=b_i+h;
  end

