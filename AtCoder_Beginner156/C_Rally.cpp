// #lev1 #허무하네 #BF

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

using namespace std;
using LL = long long;

int main(){
    int n;
    int xi;
    cin >> n;
    vector<int> x;
    for(int i=0; i<n; i++){
        cin >> xi;
        x.push_back(xi);
    }

    int sum;
    int ans = 10000000;
    for(int p=1; p<101; p++){
        sum = 0;
        for(int i=0; i<n; i++){
            sum += (x[i]-p)*(x[i]-p);
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;
}
