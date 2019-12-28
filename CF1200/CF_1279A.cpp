#include <iostream> 
#include <algorithm>
using namespace std;
typedef long long int ll;

int t;

// int v[3];
// void sol() {
//     int largest = r;
//     if (largest < g)
//         largest = g;
//     if (largest < b)
//         largest = b;

//     int res = r + g + b - largest;
//     if (largest > res + 1)
//         cout << "NO\n";
//     else
//         cout << "YES\n";
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;

    // for (int t_case = 1; t_case <= t; t_case++) {
    //     cin >> r >> g >> b;
    //     sol();
    // }

    while(t--){
        int v[3]; //지역변수로 처리할 수 있는 경우엔 마다하지 말자.
        cin >> v[0] >> v[1] >> v[2];
        sort(v, v+3);
        if(v[2] - 1 > v[1] + v[0])
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
