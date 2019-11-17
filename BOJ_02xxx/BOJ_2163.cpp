#include <iostream>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    if(N == 1)
        cout << M-1 <<'\n';
    else if(M == 1)
        cout << N-1 << '\n';
    else
        cout << (N-1) + (M-1)*N << '\n';
    // N과 M이 1일 때 예외를 처리해준건데, N*M-1 로 짧게 정리 할 수 있었다.
    
    
    return 0;
}
