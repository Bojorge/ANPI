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
      x = [-0.5773502691896257, 0.5773502691896257];
      w = [1, 1];
    case 3
      x = [0, -0.7745966692414834, 0.7745966692414834];
      w = [0.8888888888888888, 0.5555555555555556, 0.5555555555555556];
    case 4
      x = [-0.3399810435848563, 0.3399810435848563, -0.8611363115940526, 0.8611363115940526];
      w = [0.6521451548625461, 0.6521451548625461, 0.3478548451374538, 0.3478548451374538];
    case 5
      x = [0, -0.5384693101056831, 0.5384693101056831, -0.9061798459386640, 0.9061798459386640];
      w = [0.5688888888888889, 0.4786286704993665, 0.4786286704993665, 0.2369268850561891, 0.2369268850561891];
    case 6
      x = [0.6612093864662645, -0.6612093864662645, -0.2386191860831969, 0.2386191860831969, -0.9324695142031521, 0.9324695142031521];
      w = [0.3607615730481386, 0.3607615730481386, 0.4679139345726910, 0.4679139345726910, 0.1713244923791704, 0.1713244923791704];
    case 7
      x = [0, 0.4058451513773972, -0.4058451513773972, -0.7415311855993945, 0.7415311855993945, -0.9491079123427585, 0.9491079123427585];
      w = [0.4179591836734694, 0.3818300505051189, 0.3818300505051189, 0.2797053914892766, 0.2797053914892766, 0.1294849661688697, 0.1294849661688697];
    case 8
      x = [-0.1834346424956498, 0.1834346424956498, -0.5255324099163290, 0.5255324099163290, -0.7966664774136267, 0.7966664774136267, -0.9602898564975363, 0.9602898564975363];
      w = [0.3626837833783620, 0.3626837833783620, 0.3137066458778873, 0.3137066458778873, 0.2223810344533745, 0.2223810344533745, 0.1012285362903763, 0.1012285362903763];
    case 9
      x = [0, -0.8360311073266358, 0.8360311073266358, -0.9681602395076261, 0.9681602395076261, -0.3242534234038089, 0.3242534234038089, -0.6133714327005904, 0.6133714327005904];
      w = [0.3302393550012598, 0.1806481606948574, 0.1806481606948574, 0.0812743883615744, 0.0812743883615744, 0.3123470770400029, 0.3123470770400029, 0.2606106964029354, 0.2606106964029354];
    case 10
      x = [-0.1488743389816312, 0.1488743389816312, -0.4333953941292472, 0.4333953941292472, -0.6794095682990244, 0.6794095682990244, -0.8650633666889845, 0.8650633666889845, -0.9739065285171717, 0.9739065285171717];
      w = [0.2955242247147529, 0.2955242247147529, 0.2692667193099963, 0.2692667193099963, 0.2190863625159821, 0.2190863625159821, 0.1494513491505806, 0.1494513491505806, 0.0666713443086881, 0.0666713443086881];
    case 11
      x = [0, -0.8717401485096066, 0.8717401485096066, -0.5917001814331423, 0.5917001814331423, -0.2092992179024789, 0.2092992179024789, -0.9340014304080591, 0.9340014304080591, -0.8650633666889845, 0.8650633666889845];
      w = [0.2729250867779006, 0.1016667612931866, 0.1016667612931866, 0.2223810344533745, 0.2223810344533745, 0.3137066458778873, 0.3137066458778873, 0.0626720483341091, 0.0626720483341091, 0.1494513491505806, 0.1494513491505806];
    case 12
      x = [-0.1252334085114689, 0.1252334085114689, -0.3678314989981802, 0.3678314989981802, -0.5873179542866175, 0.5873179542866175, -0.7699026741943047, 0.7699026741943047, -0.9041172563704749, 0.9041172563704749, -0.9815606342467191, 0.9815606342467191];
      w = [0.2491470458134028, 0.2491470458134028, 0.2334925365383548, 0.2334925365383548, 0.2031674267230659, 0.2031674267230659, 0.1600783285433462, 0.1600783285433462, 0.1019301198172404, 0.1019301198172404, 0.0471753363865118, 0.0471753363865118];
    case 13
      x = [0, -0.8717401485096066, 0.8717401485096066, -0.5917001814331423, 0.5917001814331423, -0.2092992179024789, 0.2092992179024789, -0.9340014304080591, 0.9340014304080591, -0.8650633666889845, 0.8650633666889845, -0.9772599499837743, 0.9772599499837743];
      w = [0.2152638534631578, 0.0806612017894033, 0.0806612017894033, 0.1803807865240693, 0.1803807865240693, 0.2606106964029354, 0.2606106964029354, 0.0650830146121207, 0.0650830146121207, 0.1494513491505806, 0.1494513491505806, 0.0516079856157616, 0.0516079856157616];
    case 14
      x = [-0.1080549487073437, 0.1080549487073437, -0.3191123689278897, 0.3191123689278897, -0.5150834541676965, 0.5150834541676965, -0.6872929048116855, 0.6872929048116855, -0.8272013150697650, 0.8272013150697650, -0.9284348836635735, 0.9284348836635735, -0.9862838086968123, 0.9862838086968123];
      w = [0.2025782419255613, 0.2025782419255613, 0.1984314853271116, 0.1984314853271116, 0.1861610000155622, 0.1861610000155622, 0.1662692058169939, 0.1662692058169939, 0.1395706779261543, 0.1395706779261543, 0.1071592204671719, 0.1071592204671719, 0.0703660474881081, 0.0703660474881081];
    case 15
      x = [0, -0.8884592328722569, 0.8884592328722569, -0.6305995201619651, 0.6305995201619651, -0.2947505657736607, 0.2947505657736607, -0.9558239495713977, 0.9558239495713977, -0.8648644233597691, 0.8648644233597691, -0.9815606342467191, 0.9815606342467191, -0.9994844100504906, 0.9994844100504906];
      w = [0.1903505780647854, 0.0650830146121207, 0.0650830146121207, 0.1527533871307259, 0.1527533871307259, 0.2490955809880777, 0.2490955809880777, 0.0271524594117541, 0.0271524594117541, 0.1494513491505806, 0.1494513491505806, 0.0471753363865118, 0.0471753363865118, 0.0134442673751655, 0.0134442673751655];
    case 16
      x = [-0.0950125098376374, 0.0950125098376374, -0.2816035507792589, 0.2816035507792589, -0.4580167776572274, 0.4580167776572274, -0.6178762444026438, 0.6178762444026438, -0.7554044083550030, 0.7554044083550030, -0.8656312023878318, 0.8656312023878318, -0.9445750230732326, 0.9445750230732326, -0.9894009349916499, 0.9894009349916499];
      w = [0.1807395644453884, 0.1807395644453884, 0.1765966227514517, 0.1765966227514517, 0.1680041021564500, 0.1680041021564500, 0.1559945203362029, 0.1559945203362029, 0.1406532597155259, 0.1406532597155259, 0.1225552067114785, 0.1225552067114785, 0.1013336794463011, 0.1013336794463011, 0.0776847706531971, 0.0776847706531971];
    case 17
      x = [0, -0.8997579954114602, 0.8997579954114602, -0.6771862795107378, 0.6771862795107378, -0.3631174638261782, 0.3631174638261782, -0.9815606342467191, 0.9815606342467191, -0.8648644233597691, 0.8648644233597691, -0.9984362770874024, 0.9984362770874024, -0.9409193241962389, 0.9409193241962389, -0.9931285991850949, 0.9931285991850949];
      w = [0.1691423829631436, 0.0432970197865596, 0.0432970197865596, 0.1079388750320695, 0.1079388750320695, 0.1693953067668677, 0.1693953067668677, 0.0241483028685479, 0.0241483028685479, 0.1494513491505806, 0.1494513491505806, 0.0065719872257931, 0.0065719872257931, 0.0933078120172818, 0.0933078120172818, 0.0278342835580867, 0.0278342835580867];
    case 18
      x = [-0.0847750130417353, 0.0847750130417353, -0.2518862256915055, 0.2518862256915055, -0.4117511614628426, 0.4117511614628426, -0.5597708310739475, 0.5597708310739475, -0.6916870430603532, 0.6916870430603532, -0.8037049589725231, 0.8037049589725231, -0.8926024664975557, 0.8926024664975557, -0.9558239495713977, 0.9558239495713977, -0.9915651684209309, 0.9915651684209309];
      w = [0.1610544498487837, 0.1610544498487837, 0.1589688433939543, 0.1589688433939543, 0.1527660420658597, 0.1527660420658597, 0.1434695458511227, 0.1434695458511227, 0.1317278461618158, 0.1317278461618158, 0.1172278751677703, 0.1172278751677703, 0.1004445714270563, 0.1004445714270563, 0.0812743883615744, 0.0812743883615744, 0.0597912140136344, 0.0597912140136344];
    case 19
      x = [0, -0.9090620585422277, 0.9090620585422277, -0.7170134737394237, 0.7170134737394237, -0.4505840482680847, 0.4505840482680847, -0.1566471677927832, 0.1566471677927832, -0.9815606342467191, 0.9815606342467191, -0.8648644233597691, 0.8648644233597691, -0.9981523221042193, 0.9981523221042193, -0.9471590666617142, 0.9471590666617142, -0.9915651684209309, 0.9915651684209309];
      w = [0.1533030106942389, 0.0286479161620783, 0.0286479161620783, 0.0805787673648175, 0.0805787673648175, 0.1216022700015072, 0.1216022700015072, 0.1578477356630820, 0.1578477356630820, 0.0178736205378085, 0.0178736205378085, 0.1494513491505806, 0.1494513491505806, 0.0053771708514269, 0.0053771708514269, 0.0914946475807040, 0.0914946475807040, 0.0264640946931904, 0.0264640946931904];
    case 20
      x = [-0.07652652113349733, 0.07652652113349733, -0.2277858511416451, 0.2277858511416451, -0.3737060887154196, 0.3737060887154196, -0.5150834541676965, 0.5150834541676965, -0.6513526226459512, 0.6513526226459512, -0.7815140038968014, 0.7815140038968014, -0.9041172563704749, 0.9041172563704749, -1.018185298230864, 1.018185298230864, -1.123069704445835, 1.123069704445835, -1.218282796030381, 1.218282796030381];
      w = [0.1527533871307259, 0.1527533871307259, 0.1491729864726037, 0.1491729864726037, 0.1420961093183820, 0.1420961093183820, 0.1316886384491766, 0.1316886384491766, 0.1181945319615184, 0.1181945319615184, 0.1019301198172404, 0.1019301198172404, 0.0832767415767048, 0.0832767415767048, 0.0626720483341091, 0.0626720483341091, 0.0406014298003869, 0.0406014298003869, 0.0176140071391521, 0.0176140071391521];
  endswitch
end

