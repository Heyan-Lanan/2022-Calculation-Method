#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return log(x);
}


double DI(int n, double a, double width) {
    double s = 0.0;
    width /= n;
    for (int i = 0; i < n; ++i) {
        double x1 = a + (i) * width;
        double x2 = a + (i + 1) * width;
        s += (x2 - x1) / 6.0 * (f(x1) + 4.0 * f(0.5 * (x1 + x2)) + f(x2));
    }
    return s;
}

double Simpson(double a, double b, double eps) {
    double width = (b - a);
    double simpson_integral;
    int counter = 1;
    while (fabs(DI(counter, a, width) - DI(counter * 2, a, width)) > eps) {
        counter++;
        //cout << DI(counter, a, width) << endl;
    }
    simpson_integral = DI(counter * 2, a, width);
    return simpson_integral;
}

int main() {
    double a;
    double b, eps;
    int n;
    //cin >> a >> b >> eps;
    a = 1;
    b = 2;
    eps = 0.0001;
    cout << Simpson(a, b, eps);
    return 0;
}
