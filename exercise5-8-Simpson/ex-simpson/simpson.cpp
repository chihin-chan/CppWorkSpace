/*
 * High-performance Computing
 *
 * Solution to Exercise 5.8.
 *
 * Integrates x*x*exp(x*x) on [-1,1] using Simpson's rule.
 *
 */
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const double a = -1.0;      // Bounds of integration
    const double b =  1.0;
    const int    n = 10000;     // Pick how many intervals to use
    const double h = (b-a)/n;   // Size of interval
    double       I = 0.0;       // Result variable
    double       x;

    // First summation in approximation
    for (int i = 1; i < n/2.0; ++i) {
        x = a + (2.0*i - 1.0)*h;
        I += 4.0*x*x*exp(x*x);
    }

    // Second summation in approximation
    for (int i = 1; i < n/2.0 - 1; ++i) {
        x = a + 2.0 * i * h;
        I += 2.0*x*x*exp(x*x);
    }

    // Add in the upper and lower bounds
    I += a*a*exp(a*a) + b*b*exp(b*b);

    // Scaling term
    I *= (b-a)/(3*n);

    // Print result
    cout << "Integral is: " << I << endl;

    return 0;
}
