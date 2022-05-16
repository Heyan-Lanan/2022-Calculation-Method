#include <iostream>
#include <cmath>
using namespace std;

long double f(long double x){
    //long double pi = 3.1415926535897932384626433;
    return numbers::pi * numbers::pi * sin(numbers::pi * x);
}

long double check(long double x){
    return sin(numbers::pi * x);
}

int main(){
    long double u0[200], u1[200];
    for(long double & i : u0){
        i = 0.0000000000;
    }
    int n = 160;
    long double h = 1.0 / n;
    int cnt = 0;
    long double eps = 1E-10;
    cout << eps << endl;
    while(true){
        cnt++;
//        if(cnt % 100 == 0)
//            cout << cnt << endl;
        int i = cnt % 2;
        if(i == 1){
            u1[1] = (u0[2] + f(h) * h * h) / 2.0;
            for(auto j = 2; j < n - 1; j++){
                u1[j] = (u0[j+1] + u0[j-1] + f((j) * h) * h * h) / 2.0;
            }
            u1[n-1] = (u0[n-2] + f((n-1)*h) * h * h) / 2.0;

            long double max = 0.0;
            for(auto j = 1; j < n; j++){
                //cout << u1[j] << " ";
                auto distance = fabs(u1[j] - u0[j]);
                if(distance > max)
                    max = distance;
            }
            //cout << endl;
            if(max < eps){
                long double eh = 0.0;
                for(auto j = 1; j < n; j++)
                    eh += (u1[j] - check(j * h)) * (u1[j] - check(j * h));
                eh = sqrt(eh);
                cout << "count = " << cnt << endl;
                cout << "eh = " << eh << endl;
                break;
            }
        }
        else{
            u0[1] = (u1[2] + f(h) * h * h) / 2.0;
            for(auto j = 2; j < n - 1; j++){
                u0[j] = (u1[j+1] + u1[j-1] + f((j) * h) * h * h) / 2.0;
            }
            u0[n-1] = (u1[n-2] + f((n-1)*h) * h * h) / 2.0;

            long double max = 0.0;
            for(auto j = 1; j < n; j++){
                //cout << u0[j] << " ";
                auto distance = fabs(u0[j] - u1[j]);
                if(distance > max)
                    max = distance;
            }
            //cout << endl;
            if(max < eps){
                long double eh = 0.0;
                for(auto j = 1; j < n; j++)
                    eh += (u0[j] - check(j * h)) * (u0[j] - check(j * h));
                eh = sqrt(eh);
                cout << "count = " << cnt << endl;
                cout << "eh = " << eh << endl;
                break;
            }

        }

    }


    return 0;
}