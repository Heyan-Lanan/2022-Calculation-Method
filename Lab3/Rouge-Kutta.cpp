#include <cmath>
#include "iostream"

using namespace std;

double f(double x, double y){

    return y * sin(numbers::pi * x);
}
int main(){
    int n;
    double a, b, y[100], x[100], k1, k2;
    y[0] = 1.0;
    cin >> a >> b >> n;
    double h = (b - a)/double(n);
    for(int i = 0; i < n; i++){
        x[i] = i * h;
        k1 = f(x[i], y[i]);
        k2 = f(x[i] + h, y[i] + h * k1);
        y[i+1] = y[i] + h / 2.0 * (k1 + k2);
        cout << "y" << i+1 << " = " << y[i+1] << endl;
    }
    return 0;
}