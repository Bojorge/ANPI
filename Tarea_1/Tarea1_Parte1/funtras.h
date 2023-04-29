#ifndef FUNTRAS_H
#define FUNTRAS_H
#pragma once
#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <limits>
#include <cmath>
using namespace boost::multiprecision;
using namespace std;
class funtras{
public:
    const cpp_bin_float_double_extended pi_t = 3.14159265358979323846;
    funtras();
    cpp_bin_float_double_extended test_t();
    cpp_bin_float_double_extended factorial(int n);
    cpp_bin_float_double_extended divi_t(cpp_bin_float_double_extended x);
    cpp_bin_float_double_extended inverso_de_x(long double x);
    cpp_bin_float_double_extended indice_y_raiz_x(double x, double y);
    cpp_bin_float_double_extended x_elevado_a_y(double x, double y);
    cpp_bin_float_double_extended sin_t(double x);
    cpp_bin_float_double_extended tan_t(double x);
    cpp_bin_float_double_extended log_t(double x);
    cpp_bin_float_double_extended sinh_t(double x);
    cpp_bin_float_double_extended tanh_t(double x);
    cpp_bin_float_double_extended root_t(double x);
    cpp_bin_float_double_extended atan_t(double x);
    cpp_bin_float_double_extended sec_t(double x);
    cpp_bin_float_double_extended exp_t(double x);
    cpp_bin_float_double_extended cos_t(double x);
    cpp_bin_float_double_extended ln_t(double x);
    cpp_bin_float_double_extended log10_t(double x);
    cpp_bin_float_double_extended power_t(double x);
    cpp_bin_float_double_extended cosh_t(double x);
    cpp_bin_float_double_extended sqrt_t(double x);
    cpp_bin_float_double_extended asin_t(double x);
    cpp_bin_float_double_extended acos_t(double x);
    cpp_bin_float_double_extended csc_t(double x);
    cpp_bin_float_double_extended cot_t(double x);
    cpp_bin_float_double_extended log_y_t(double x, double y);
};
#endif // FUNTRAS_H
