#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const double pi = std::acos(-1);
int n;

void sol(){
    cin >> n;
    
    //풀이는 README.md를 참조
    double a = pi / (2*n);
    double r = 1 / sin(a);
    a /= 2;
    cout << r * cos(a) << '\n';
}

int main()
{
    int t; cin >> t;
    while(t--)
        sol();
        
    return 0;
}
