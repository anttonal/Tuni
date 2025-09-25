// Note that there is no need for "using namespace std",
// since no C++ standard libraries are used.

double addition(double left, double right) {
    return left + right;
}


double subtraction(double left, double right) {
    return left - right;
}


double multiplication(double left, double right) {
    return left * right;
}


double division(double left, double right) {
    return left / right;
}

double exponentiation(double base, double exponent) {
    double result = base;
    for (int i = 1; i < exponent; ++i) {
        result = result*base;
    }
    return result;
}
