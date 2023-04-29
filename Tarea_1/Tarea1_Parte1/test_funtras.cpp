#include "funtras.h"
#include <iostream>
#include <cmath>
using namespace std;

cpp_bin_float_double_extended test_funtras() {
    cpp_bin_float_double_extended radicando = funtras.cos_t(3.0/7.0) + funtras.ln_t(2.0);
    cpp_bin_float_double_extended numerador = funtras.indice_y_raiz_x(radicando,3.0);

    cpp_bin_float_double_extended raiz = funtras.root_t(2.0);
    cpp_bin_float_double_extended denominador = funtras.sinh_t(raiz);

    double e = exp(1.0);
    cpp_bin_float_double_extended inv_euler = funtras.inverso_de_x(e);
    cpp_bin_float_double_extended termino2 = funtras.atan_t(inv_euler);

    cpp_bin_float_double_extended termino1 = numerador * funtras.divi_t(denominador);
    
    cpp_bin_float_double_extended resultado = termino1 + termino2;

    std::cout << "El resultado es: " << std::endl;
    std::cout << resultado << std::endl;
    return resultado;
}
