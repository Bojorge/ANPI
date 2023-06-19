function I=trapecio_compuesto_iterativa(f,a,b,iterMax,tol);
  % Aproximación numérica de la integral de una función en un intervalo mediante
  % el metodo del trapecio compuesto iterativo, el cual divide en subitervalos y
  % utiliza iteraciones para aplicar el metodo del trapecio a cada intervalo con
  % diferentes cantidades de divisiones hasta hallar la que supere una
  % tolerancia.
  % Sintaxys : trapecio_compuesto(f,a,b)
  % Inputs:
  %    f = funcion a evaluar,
  %    a, b = intervalo [a, b]
  %    iterMax = cantidad de iteraciones maxima
  %    tol = tolerancia permitida del error
  % Outputs:
  %    I =  I = Aproximacion numerica de la integral
  fnum = str2func(['@(x)' f])
  Ir = quad(fnum, a, b);
  I = 0
  for k=1:iterMax
    I=trapecio_compuesto(f,a,b,k);
    error=abs(I-Ir);
    if error<tol
      break
    end
  end
end


function I=trapecio_compuesto(f,a,b,N);
  % Aproximación numérica de la integral de una función en un intervalo mediante
  % el metodo del trapecio compuesto, el cual divide en subitervalos y utiliza
  % recursivodad para aplicar el metodo del trapecio a cada intervalo.
  % Sintaxys : trapecio_compuesto(f,a,b,N)
  % Inputs:
  %    f = funcion a evaluar,
  %    a, b = intervalo [a, b],
  %    N = numero de puntos en los que se divide el intervalo [a, b]
  % Outputs:
  %    I =  I = Aproximacion numerica de la integral
  h=(b-a)/(N-1);
  xSoporte=a:h:b;
  I=0;
  for i=1:N-1
    I=I+trapecio(f,xSoporte(i),xSoporte(i+1));
  end
end

function I=trapecio(f,a,b)
  % Aproximación numérica de la integral de una función en un intervalo mediante
  % el método del trapecio.
  % Sintaxis: I = trapecio(f,a,b)
  % Inputs:
  %   f: función a evaluar
  %   a, b: límites de integración [a, b]
  % Output:
  %   I: aproximación numérica de la integral
  fnum=str2func(['@(x)' f]);
  I=(b-a)*(fnum(b)+fnum(a))/2;
end
