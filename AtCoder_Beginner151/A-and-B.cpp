// A

#include <iostream>
using namespace std;
 
int main() {
 
    char a;
    cin >> a;
    cout << char(a + 1) << endl;
    return 0;
}

// B

#include <iostream>
using namespace std;
 
int N, K, M;
int A[101];
int main() {
    cin >> N >> K >> M;
    int sum = 0;
    for (int i = 1; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    int want = N * M;
    if (want - sum <= 0)
        cout << 0;
    else if (want - sum <= K)
        cout << want - sum;
    else
        cout << -1;
 
    return 0;
}
