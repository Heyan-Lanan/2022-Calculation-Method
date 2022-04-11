#include <bits/stdc++.h>
using namespace std;
double n = 6, m = 3, x[100], y[100], l[100];
double lagrange(double test){
    double re = 0;
    for(double & i : l) i = 1;
    for(auto i = 0; i < n; i++){
        for(auto j = 0; j < n; j++){
            if(j != i)
                l[i] *=  (test - x[j]) / (x[i] - x[j]);
        }
        re += l[i] * y[i];
    }
    return re;
}

int main(){

    string from = R"(E:\code_test\Lagrange\in.txt)";
    string dest = R"(E:\code_test\Lagrange\out.txt)";
    ifstream file_in;
    ofstream file_out;
    file_in.open(from);
    file_out.open(dest);

    for(auto i = 0; i < n; i++)
        file_in >> x[i] >> y[i];
    double test;
    for(auto i = 0; i < m; i++){
        file_in >> test;
        double result = lagrange(test);
        file_out << test << " " << result <<endl;
    }
    return 0;
}
