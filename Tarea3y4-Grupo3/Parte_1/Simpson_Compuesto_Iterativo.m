function test()
  clc; clear;
  f='log(asin(x))/log(x)';
  a=0.1; b=0.8;
  n=1000;
  I2=trapecio_compuesto(f,a,b,n)

function I=simpson_compuesto_iterativo(f,a,b,n)
   %Escribir la ayuda de la funcion
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

