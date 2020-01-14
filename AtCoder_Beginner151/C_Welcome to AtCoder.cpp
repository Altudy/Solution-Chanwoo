//#lev1
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;

int main() {
    cin >> N >>  M;
    vector<int> Problems;
    int Co(0), Pe(0);
    int a; string s;

    Problems.assign(N + 1, 0);

    for (int i = 0; i < M; i++) {
        cin >> a >> s;
        if (s == "WA") {
            if (Problems[a] <= 0)
                Problems[a]--;
        }
        else {
            if (Problems[a] <= 0) {
                //문제를 맞추었을 때만 그 문제에 해당하는 페널티 부여
                Pe -= Problems[a];  
                Co++;
                Problems[a] = 1;
            }
        }
    }

    cout << Co << " " << Pe;

    return 0;
}
