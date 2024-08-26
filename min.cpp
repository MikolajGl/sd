#include <iostream>
#include <cmath>

using namespace std;

long double f(long double x) {
    const long double a = 7.11;
    const long double b = 5.27;

    return exp(x) + 2 * sqrt(x) - 3;
}

long double F_(long double x) {
    if (x <= 0)
    return exp(x) + (1 / sqrt(x));
}

long double u(long double x) {
    return f(x) / F_(x);
}

long double G(long double x) {
    return x - ((u(x) + (f(x) / F_(x - u(x)))) / 2);
}

long double N(long double eps, long double x) {
    int iter = 0;
    long double d ;
    cout << "Newton" << endl;
    cout<<x<<endl;

    do {
        long double fx = f(x);
        long double Fx = F_(x);
        d = -u(x);
        x = x+d;
        ++iter;

    } while (abs(d) >= eps);

    cout << "Liczba przebytych iteracji: " << iter << endl;
    cout << "EPS: " << eps << endl;
    cout << "Wartoœæ x: " << x << endl;

    return x;
}

long double W(long double eps, long double x) {
    int iter = 0;
    cout << "Wielopunkt" << endl;
    cout<<x<<endl;
    long double d;

    do {
        long double fx = f(x);
        long double Fx = F_(x);
        d=-u(x);
        x = x-d;
        ++iter;

    } while (abs(d) >= eps);

    cout << "Liczba przebytych iteracji: " << iter << endl;
    cout << "Wartoœæ x: " << x << endl;

    return x;
}

int main() {
    cout.precision(20);
    for (long double x = 10; x <= 10000; x = x*10) {
        for (long double eps = 0.1; eps > 1e-11; eps = eps/10) {
            N(eps, x);
            W(eps, x);
        }
    }

    for (long double x = 10; x <= 10000; x = x*10) {
        for (long double eps = 0.1; eps > 1e-12; eps = eps/10) {
            N(eps, -x);
            W(eps, -x);
        }
    }

    return 0;
}
