
function test()
  clc; clear;
  f='log(asin(x))/log(x)';
  a=0.1; b=0.8;
  n=1000;
  I2=simpson_compuesto(f,a,b,n)
end

function I=simpson_compuesto(f,a,b,n);
  %Escribir la ayuda de la funcion
  h=(b-a)/(n-1);
  xSoporte=a:h:b;
  I=0;
  for i=1:n-1
    I=I+simpson(f,xSoporte(i),xSoporte(i+1));
  end
end

function I=simpson(f,a,b)
  %%%% Comentar la funcion correctamente
  fnum=str2func(['@(x)' f]);
  I=(b-a)/6*(fnum(a)+4*fnum((a+b)/2)+fnum(b));
end

