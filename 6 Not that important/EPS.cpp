#include <cmath>
const double EPS = 1e-9;

bool eq(double a, double b) {
    return fabs(a - b) < EPS;
}

bool lt(double a, double b) {
    return a < b - EPS;
}

bool le(double a, double b) {
    return a < b + EPS;
}