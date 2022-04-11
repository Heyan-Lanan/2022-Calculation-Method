#include <bits/stdc++.h>
using namespace std;
int n = 6, m = 2;
double newton(double a[10][10], int n, double x){
    int i,j,k;
    double y = a[1][0], sum;
    for (i = 2; i <= n; i++)
        for (j = i - 1, k = 0; j < n; j++, k++)
            a[i][j] = (a[i-1][j] - a[i-1][j-1]) / (a[0][j] - a[0][k]);
    for (i = 2; i <= n; i++){
        sum = 1;
        for (j = i-2; j >= 0; j--)
            sum = (x - a[0][j]) * sum;
        //cout << a[i][i-1] << endl;
        sum = sum * a[i][i-1];
        y = sum + y;
    }
    return y;
}

int main(){

    string from = R"(E:\code_test\Newton\in.txt)";
    string dest = R"(E:\code_test\Newton\out.txt)";
    ifstream file_in;
    ofstream file_out;
    file_in.open(from);
    file_out.open(dest);

    double a[10][10], x;
    memset(a,0,sizeof(a));
    for(auto i = 0; i < n; i++)
        file_in >> a[0][i] >> a[1][i];
    for(auto i = 0; i < m; i++){
        file_in >> x;
        file_out << x << " "<< newton(a,n,x) << endl;
    }
    return 0;
}

