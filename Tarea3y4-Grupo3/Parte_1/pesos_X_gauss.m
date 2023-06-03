function [x,w]=pesos_X_gauss(n)
  % Devuelve los nodos y pesos para la integración numérica mediante la fórmula de Gauss.
  % Sintaxys : pesos_X_gauss(n)
  % Inputs:
  %   n: número de puntos de integración
  %
  % Outputs:
  %   x: vector de nodos de integración
  %   w: vector de pesos de integración
  switch (n)
    case 2
      x=[-0.5773502691896257 0.5773502691896257];
      w=[1 1];
    case 3
      x=[0  -0.7745966692414834 0.7745966692414834];
      w=[0.8888888888888888 0.5555555555555556 0.5555555555555556];
    case 4
      x=[-0.3399810435848563 0.3399810435848563 -0.8611363115940526 0.8611363115940526];
      w=[0.6521451548625461 0.6521451548625461 0.3478548451374538 0.3478548451374538];
  endswitch
end

