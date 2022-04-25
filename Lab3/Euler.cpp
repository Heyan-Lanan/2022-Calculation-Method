#include <cmath>
#include "iostream"

using namespace std;

double f(double u, double v){
    return 0.09 * u * (1 - u / 20.0) - 0.45 * u * v;
}

double g(double u, double v){
    return 0.06 * v * (1 - v / 15.0) - 0.001 * u * v;
}

int main(){
    double u[100], v[100], u_[100], v_[100], a, b;
    int n;
    u[0] = 1.6;
    v[0] = 1.2;
    cin >> a >> b >> n;
    double h = (b - a)/double(n);
    for(int i = 0; i < n; i++){
        u_[i+1] = u[i] + h * f(u[i], v[i]);
        v_[i+1] = v[i] + h * g(u[i], v[i]);
        u[i+1] = u[i] + h / 2.0 * (f(u[i], v[i]) + f(u_[i+1], v_[i+1]));
        v[i+1] = v[i] + h / 2.0 * (g(u[i], v[i]) + g(u_[i+1], v_[i+1]));
        cout << "u" << i+1 << " = " << u[i+1] << " " << "v" << i+1 << " = " << v[i+1] << endl;
    }

    return 0;
}