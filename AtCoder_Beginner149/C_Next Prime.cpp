#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
 
#define Inf             987654321
using namespace std;
 
typedef long long int   ll;
typedef pair<ll, ll>    pii;
typedef vector<ll>      vi;
typedef vector<vi>      vii;
/*************************************************/
 
bool isPrime(int num)
{
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) return false;

    return true;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int X;
    cin >> X;
 
    while (!isPrime(X)) X++;
  
    cout << X << '\n';
 
    return 0;
}   //#lev1 #소수..
