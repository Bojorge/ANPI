#include "funtras.h"
funtras::funtras(){}

/*
 * Funcion test_t: funcion de prueba.
 *
 */
cpp_bin_float_double_extended funtras::test_t(){
    cpp_bin_float_double_extended radicando = cos_t(3.0/7.0) + ln_t(2.0);
    cpp_bin_float_double_extended numerador = indice_y_raiz_x(static_cast<double>(radicando),3.0);

    cpp_bin_float_double_extended raiz = root_t(2.0);
    cpp_bin_float_double_extended denominador = sinh_t(static_cast<double>(raiz));

    double e = exp(1.0);
    cpp_bin_float_double_extended inv_euler = inverso_de_x(e);
    cpp_bin_float_double_extended termino2 = atan_t(static_cast<double>(inv_euler));

    cpp_bin_float_double_extended termino1 = numerador * divi_t(denominador);

    cpp_bin_float_double_extended resultado = termino1 + termino2;

    return resultado;
}

/*
 * Funcion divi_t: Utiliza la función inverso_de_x para usarlo como division.
 * Input: x
 * Output: Xk
 */
cpp_bin_float_double_extended funtras::divi_t(cpp_bin_float_double_extended x){
    cpp_bin_float_double_extended result = inverso_de_x(x.convert_to<long double>());
    return result;
}
/*
 * Funcion sinh_t: Aproximacion de la funcion sinh_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente.
 * Input: x
 * Output: Sk
 */
cpp_bin_float_double_extended funtras::sinh_t(double x){
    int k = 0;
    int iterMax = 100;
    cpp_bin_float_double_extended Sk = 0.0;
    cpp_bin_float_double_extended Sk_next = 0.0;
    cpp_bin_float_double_extended tol = 1e-8;
    cpp_bin_float_double_extended error = tol+1;
    cpp_bin_float_double_extended factorial_termino;

    for(int i = k; iterMax > k && error > tol; i++){
        factorial_termino = factorial((((2*k)+1)));
        Sk_next = static_cast<cpp_bin_float_double_extended>(pow(x,((2*k)+1)))*divi_t(factorial_termino);
        error = abs(Sk_next-Sk).convert_to<cpp_bin_float_double_extended>();
        Sk = Sk+Sk_next;
        k++;
    }
    return Sk;
}
/*
 * Funcion cosh_t: Aproximacion de la funcion cosh_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente.
 * Input: x
 * Output: Sk
 */
cpp_bin_float_double_extended funtras::cosh_t(double x){
    int k = 0;
    int iterMax = 100;
    cpp_bin_float_double_extended Sk = 0.0;
    cpp_bin_float_double_extended Sk_next = 0.0;
    cpp_bin_float_double_extended tol = 1e-8;
    cpp_bin_float_double_extended error = tol+1;
    cpp_bin_float_double_extended factorial_termino;
    for(int i = k; iterMax > k && error > tol; i++){
        factorial_termino = factorial((2*k));
        Sk_next = static_cast<cpp_bin_float_double_extended>(pow(x,(2*k)))*divi_t(factorial_termino);
        error = abs(Sk_next-Sk).convert_to<cpp_bin_float_double_extended>();
        Sk = Sk+Sk_next;
        k++;
    }
    return Sk;
}
/*
 * Funcion tanh_t:Aproximacion de la funcion tanh_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente, en este caso se hizo uso
 * de la division de otras dos funciones trigonometricas.
 * Input: x
 * Output: Sk
 */
cpp_bin_float_double_extended funtras::tanh_t(double x){
    cpp_bin_float_double_extended senhX = sinh_t(x);
    cpp_bin_float_double_extended coshX = cosh_t(x);
    cpp_bin_float_double_extended tanhX = senhX*divi_t(coshX);
    return tanhX;
}
/*
 * Funcion asin_t: Aproximacion de la funcion asin_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente.
 * Input: x
 * Output: Sk
 */
cpp_bin_float_double_extended funtras::asin_t(double x){
    if((x<-1) || (x>1)){
        std::cout << "La función arcoseno asin(x) está definida en el intervalo cerrado [-1, 1]  " << std::endl;
        return 0;
    }
    int k = 0;
    int iterMax = 500;
    cpp_bin_float_double_extended Sk = 0;
    cpp_bin_float_double_extended Sk_next = 0;
    cpp_bin_float_double_extended tol = 1e-8;
    cpp_bin_float_double_extended error = tol+1;
    cpp_bin_float_double_extended numerador = 1;
    cpp_bin_float_double_extended denominador = 1;
    cpp_bin_float_double_extended factor = x;
    if(x >= -1 && x <= 1){
        for(int i = k; iterMax > k && error > tol; i++){
            numerador = factorial(2*k);
            denominador = x_elevado_a_y(4,k) * factorial(k) * factorial(k) * ((2*k)+1);
            factor = x_elevado_a_y(x,((2*k)+1));
            Sk_next = factor * (numerador*divi_t(denominador));
            error = (abs(Sk_next-Sk)).convert_to<cpp_bin_float_double_extended>();
            Sk = Sk+Sk_next;;
            k++;
        }
    }
    else{
        Sk = INFINITY;
    }

    cpp_bin_float_double_extended result_grades = Sk * (180.0/pi_t);
    return result_grades;
}
/*
 * Funcion acos_t: Aproximacion de la funcion acos_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente, se hizo uso de asin_t(x) para desarrollar.
 * Input: x
 * Output: Sk
 */
cpp_bin_float_double_extended funtras::acos_t(double x){
    if((x<-1) || (x>1)){
        std::cout << "La función arcocoseno acos_t(x) está definida en el intervalo cerrado [-1, 1]  " << std::endl;
        return 0;
    }
    cpp_bin_float_double_extended asen = asin_t(x) * (pi_t*divi_t(180.0)) ;
    cpp_bin_float_double_extended result = (pi_t*divi_t(2.0)) - asen;

    cpp_bin_float_double_extended result_grades = result * (180.0*divi_t(pi_t));
    return result_grades;
}
/*
 * Funcion atan_t: Aproximacion de la funcion atan_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente.
 * Input: x
 * Output: Sk
 */
cpp_bin_float_double_extended funtras::atan_t(double x){
    int k = 0;
    int iterMax = 500;
    cpp_bin_float_double_extended Sk = 0;
    cpp_bin_float_double_extended Sk_next = 0;
    cpp_bin_float_double_extended tol = 1e-8;
    cpp_bin_float_double_extended error = tol+1;
    cpp_bin_float_double_extended numerador = 1;
    cpp_bin_float_double_extended denominador = 1;
    cpp_bin_float_double_extended factor = 1;
    if(x >= -1 && x <= 1){
        Sk_next = 0;
        for(int i = k; iterMax > k && error > tol; i++){
            factor = x_elevado_a_y(-1,k);
            numerador = x_elevado_a_y(x,((2*k)+1));
            denominador = (2*k)+1;
            Sk_next = factor * (numerador*divi_t(denominador));
            error = (abs(Sk_next-Sk)).convert_to<cpp_bin_float_double_extended>();
            Sk = Sk+Sk_next;;
            k++;
        }
        cpp_bin_float_double_extended result_grades = Sk * (180.0/pi_t);
        return result_grades;
        //return Sk;
    }
    else if(x > 1){
        for(int i = k; iterMax > k && error > tol; i++){
            factor = x_elevado_a_y(-1,k);
            numerador = 1;
            denominador = ((2*k)+1) * (x_elevado_a_y(x,((2*k)+1)));
            Sk_next = (pi_t/2.0) - (factor * (numerador*divi_t(denominador)));
            error = (abs(Sk_next-Sk)).convert_to<cpp_bin_float_double_extended>();
            Sk = Sk + Sk_next;
            k++;
        }
        cpp_bin_float_double_extended result_rad = (pi_t/2.0) - Sk;
        cpp_bin_float_double_extended result_grades = result_rad * (180.0/pi_t);
        return result_grades;
        //return (pi_t/2.0) - Sk;
    }
    else if(x < 1){
        for(int i = k; iterMax > k && error > tol; i++){
            factor = x_elevado_a_y(-1,k);
            numerador = 1;
            denominador = ((2*k)+1) * (x_elevado_a_y(x,((2*k)+1)));
            Sk_next = -1* (pi_t/2.0) - (factor * (numerador*divi_t(denominador)));
            error = (abs(Sk_next-Sk)).convert_to<cpp_bin_float_double_extended>();
            Sk = Sk + Sk_next;
            k++;
        }
         return (-1 * (pi_t/2.0)) - Sk;
    }

    cpp_bin_float_double_extended result_grades = Sk * (180.0/pi_t);
    return result_grades;
    //return Sk;
}
/*
 * Funcion sec_t:Aproximacion de la funcion sec_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente, se hizo uso de la funcion cos_t(x) para su desarrollo.
 * Input: x
 * Output: Sk
 */
cpp_bin_float_double_extended funtras::sec_t(double x){
    cpp_bin_float_double_extended cosX = cos_t(x);
    if (cosX == 0) {
        std::cout << "La función secante sec_t(double x) está limitado a todos los valores x tales que cos_t(x) es diferente de cero  " << std::endl;
        return 0;
    }
    cpp_bin_float_double_extended secX = 1*divi_t(cosX);
    return secX;

}
/*
 * Funcion csc_t: Aproximacion de la funcion csc_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente, se hizo uso de la funcion sin_t(x) para su desarrollo
 * Input: x
 * Output: cscX
 */
cpp_bin_float_double_extended funtras::csc_t(double x){
    cpp_bin_float_double_extended senX = sin_t(x);
    if (senX == 0) {
        std::cout << "La función cosecante csc_t(double x) está limitado a todos los valores x tales que sin_t(x) es diferente de cero  " << std::endl;
        return 0;
    }
    cpp_bin_float_double_extended cscX = 1*divi_t(senX);
    return cscX;

}
/*
 * Funcion cot_t: Aproximacion de la funcion cot_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente, se hizo uso de la funcion tan_t para su desarrollo.
 * Input: x
 * Output: cotX
 */
cpp_bin_float_double_extended funtras::cot_t(double x){
    cpp_bin_float_double_extended tanX = tan_t(x);
    cpp_bin_float_double_extended senX = sin_t(x);
    if (senX == 0) {
        std::cout << "La función cotangente cot_t(double x) está limitado a todos los valores x tales que sin_t(x) es diferente de cero  " << std::endl;
        return 0;
    }
    cpp_bin_float_double_extended cotX = 1*divi_t(tanX);
    return cotX;

}
/*
 * Funcion sin_t: Aproximacion de la funcion sin_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente.
 * Input: x
 * Output: Sk
 */
cpp_bin_float_double_extended funtras::sin_t(double x){
    const int iterMax = 100;
    cpp_bin_float_double_extended Sk = 0.0;
    cpp_bin_float_double_extended Sk_next = 0.0;
    cpp_bin_float_double_extended tol = 1e-8;
    cpp_bin_float_double_extended error = tol+1;
    cpp_bin_float_double_extended numerador;
    cpp_bin_float_double_extended denominador;
    int iteration_count = 0;
    for(int i = iteration_count; iterMax > iteration_count && error > tol; i++){
        numerador = (pow(x,(2*iteration_count)+1));
        denominador = factorial((2*iteration_count)+1);
        Sk_next = static_cast<cpp_bin_float_double_extended>(pow(-1,iteration_count))*((numerador)*divi_t(denominador));
        error = abs(Sk_next-Sk).convert_to<cpp_bin_float_double_extended>();
        Sk += Sk_next;
        iteration_count++;
    }
    return Sk;
}
/*
 * Funcion cos_t: Aproximacion de la funcion cos_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente.
 * Input: x
 * Output: Sk
 */
cpp_bin_float_double_extended funtras::cos_t(double x){
    const int iterMax = 100;
    cpp_bin_float_double_extended Sk = 0.0;
    cpp_bin_float_double_extended Sk_next = 0.0;
    cpp_bin_float_double_extended tol = 1e-8;
    cpp_bin_float_double_extended error = tol+1;
    cpp_bin_float_double_extended factorial_termino;
    int k = 0;
    for(int i = k; iterMax > k && error > tol; i++){
        factorial_termino = factorial((2*k));
        Sk_next = static_cast<cpp_bin_float_double_extended>(pow(-1,k)*(pow(x,(2*k))))*divi_t(factorial_termino);
        error = abs(Sk_next-Sk).convert_to<cpp_bin_float_double_extended>();
        Sk = Sk +Sk_next;
        k++;
    }
    return Sk;
}

/*
 * Funcion tan_t: Aproximacion de la funcion tan_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente. Se hizo uso de las funciones sin_t(x) y cos_t(x) para su desarrollo.
 * Input: x
 * Output: Sk
 */
cpp_bin_float_double_extended funtras::tan_t(double x){
    cpp_bin_float_double_extended cosX = cos_t(x);
    if(cosX == 0){
        std::cout << "La función tangente tan_t(double x) está limitado a todos los números reales excepto los valores donde el cos x es igual a 0. " << std::endl;
        return 0;
    }
    cpp_bin_float_double_extended senX = sin_t(x);
    cpp_bin_float_double_extended tanX = senX*divi_t(cosX);
    return tanX;
}
/*
 * Funcion ln_t: Aproximacion de la funcion ln_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente.
 * Input: x
 * Output: Sk
 */
cpp_bin_float_double_extended funtras::ln_t(double x){
    int k = 0;
    int iterMax = 2500;
    cpp_bin_float_double_extended Sk = 0;
    cpp_bin_float_double_extended Sk_next = 0;
    cpp_bin_float_double_extended tol = 1e-8;
    cpp_bin_float_double_extended error = tol+1;
    cpp_bin_float_double_extended Sk_factor = (x-1) / (x+1);
    cpp_bin_float_double_extended Sk_series = 0;
    while(error > tol && k < iterMax){
        Sk_series += (cpp_bin_float_double_extended(1)*divi_t((2*cpp_bin_float_double_extended(k))+1)) * ((pow(Sk_factor, 2.0*k)).convert_to<cpp_bin_float_double_extended>());
        Sk_next = 2 * Sk_factor * Sk_series;
        error = abs(Sk - Sk_next).convert_to<cpp_bin_float_double_extended>();
        Sk = Sk_next;
        k++;
    }
    return Sk;
}
/*
 * Funcion log_t: Aproximacion de la funcion log_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente. Se hace uso de ln_t(x) dividido por ln_t(10).
 * Input: x
 * Output: result
 */
cpp_bin_float_double_extended funtras::log10_t(double x){
    cpp_bin_float_double_extended result = ln_t(x)*divi_t(ln_t(10));
    return result;
}
/*
 * Funcion log_y_t: Aproximacion de la funcion log_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente. Se hace uso de ln_t(x).
 * Input: x, y
 * Output: result
 */
cpp_bin_float_double_extended funtras::log_y_t(double x, double y){
    cpp_bin_float_double_extended result = ln_t(x) *divi_t(ln_t(y));
    return result;
}
/*
 * Funcion inverso_de_x: Aproximacion de la funcion 1/x por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente, solo involucra las operaciones de resta y multiplicacion.
 * Input: x
 * Output: Xk_nuevo
 */
cpp_bin_float_double_extended funtras::inverso_de_x(long double x){
    if(x == 0){
        std::cout << "El valor de entrada x debe ser diferente a cero" << std::endl;
        return 1;
    }
    cpp_bin_float_double_extended Xk = 0.0;
    cpp_bin_float_double_extended Xk_nuevo = 0.0;
    cpp_bin_float_double_extended tol = 1e-8;
    cpp_bin_float_double_extended eps = 2.2204 * 0.0000000000000001;
    int max_iter = 2500;
    int iter = 0;
    if (factorial(0) <= x && x <= factorial(20)) {
        Xk = static_cast<cpp_bin_float_double_extended>(pow(eps,2));
    }
    else if (x <= factorial(40)) {
        Xk = static_cast<cpp_bin_float_double_extended>(pow(eps,4));
    }
    else if (x <= factorial(60)) {
        Xk = static_cast<cpp_bin_float_double_extended>(pow(eps,8));
    }
    else if (x <= factorial(80)) {
        Xk = static_cast<cpp_bin_float_double_extended>(pow(eps,11));
    }
    else if (x < factorial(100)) {
        Xk = static_cast<cpp_bin_float_double_extended>(pow(eps,15));
    }
    else if (x >= (factorial(100))) {
        Xk = static_cast<cpp_bin_float_double_extended>(0);
    }
    for(int i = 0; i<max_iter; ++i ){
        Xk_nuevo = Xk*(2-(x*Xk));
        if(abs(Xk_nuevo-Xk) < tol*abs(Xk_nuevo)){
            break;
        }else{
            Xk = Xk_nuevo;
        }
    }
    if (iter >= max_iter) {
        std::cout << "La iteracion no ha convergido despues de " << max_iter << " iteraciones." << std::endl;
    }
    return Xk_nuevo;
}
/*
 * Funcion root_t: Aproximacion de la funcion root_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion trascendente, se hizo uso de indice_y_raiz_x(x, 2) para su desarrollo.
 * Input: x
 * Output: Sk
 */
cpp_bin_float_double_extended funtras::root_t(double x){
    cpp_bin_float_double_extended raiz = indice_y_raiz_x(x, 2);
    return raiz;
}
/*
 * Funcion indice_y_raiz_x: Aproximacion de la funcion indice_y_raiz_x por medio de la sucesion
 * que aproxima el valor numerico de la funcion.
 * Input: x, y
 * Output: Sk
 */
cpp_bin_float_double_extended funtras::indice_y_raiz_x(double x, double y){
    int k = 0;
    int iterMax = 80;
    cpp_bin_float_double_extended Sk = x/2;
    cpp_bin_float_double_extended Sk_next = 0.0;
    cpp_bin_float_double_extended tol = 1e-8;
    cpp_bin_float_double_extended error = tol+1;
    if(y < 2 && y*divi_t(2)!=0){
         std::cout << "El elemento " << y << " no es valido pues debe ser mayor a 2 y par." << std::endl;
         return 0;
    }
    if(y >= 0){
        for(int i = k; iterMax > k && error > tol; i++){
            Sk_next = Sk - ((x_elevado_a_y(static_cast<double>(Sk), y) - x)* divi_t(y * (x_elevado_a_y(static_cast<double>(Sk), y-1))));
            error = abs(Sk_next-Sk).convert_to<cpp_bin_float_double_extended>();
            Sk = Sk_next;
            k++;
        }
        return Sk;
    }else{
        return pow(cpp_bin_float_double_extended(x), cpp_bin_float_double_extended(y));
    }
}
/*
 * Funcion exp_t: Aproximacion de la funcion exp_t por medio de la sucesion
 * que aproxima el valor numerico de la funcion.
 * Input: x
 * Output: Sk
 */
cpp_bin_float_double_extended funtras::exp_t(double x){
    int k = 0;
    int iterMax = 100;
    cpp_bin_float_double_extended Sk = 0.0;
    cpp_bin_float_double_extended Sk_next = 0.0;
    cpp_bin_float_double_extended tol = 1e-8;
    cpp_bin_float_double_extended error = tol+1;
    cpp_bin_float_double_extended factorial_termino;
    cpp_bin_float_double_extended numerador = 1;
    cpp_bin_float_double_extended denominador = 1;
    for(int i = k; iterMax > k && error > tol && denominador > -INFINITY; i++){
        cpp_bin_float_double_extended base(x);
        cpp_bin_float_double_extended exponent(k);
        factorial_termino = factorial(k);
        numerador = boost::multiprecision::pow(base,exponent);
        Sk_next = numerador*divi_t(factorial_termino);
        error = abs(Sk_next-Sk).convert_to<cpp_bin_float_double_extended>();
        Sk = Sk+Sk_next;
        k++;
    }
    return Sk;
}
/*
 * Funcion x_elevado_a_y: Multiplica 'y' veces el valor de 'x'
 * Input: x, y
 * Output: result
 */
cpp_bin_float_double_extended funtras::x_elevado_a_y(double x, double y){
    cpp_bin_float_double_extended result = 1;
    for(int i=0; i<y; i++){
        result *= x;
    }
    return result;
}
/*
 * Funcion factorial: Producto de todos los números 1 hasta n.
 * Input: n
 * Output: resultado
 */
cpp_bin_float_double_extended funtras::factorial(int n) {
    cpp_bin_float_double_extended resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}
