#include <cmath>
#include "iostream"

using namespace std;

double f(double x, double y){
    return x * x + y * y - 1;
}

double g(double x, double y){
    return x * x * x - y;
}

int main(){

    double eps = 1E-5, x[100], y[100], delta_x, delta_y;
    x[0] = 0.8;
    y[0] = 0.6;
    int i = 0;
    while(true){
        delta_x = (-f(x[i], y[i]) - g(x[i], y[i]) * 2 * y[i]) / (2 * x[i] + 6.0 * x[i] * x[i] * y[i]);
        delta_y = 3 * x[i] * x[i] * delta_x + g(x[i], y[i]);
        x[i+1] = x[i] + delta_x;
        y[i+1] = y[i] + delta_y;
        cout << "µÚ" << i+1 << "´Îµü´ú£º" << "(" << x[i+1] << ", " << y[i+1] << ")" << endl;
        i++;
        //cout << "max:" << max(delta_x, delta_y) << endl;
        if(max(fabs(delta_x), fabs(delta_y)) <= eps)
            break;
    }
    return 0;
}