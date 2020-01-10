//#lev1 #비트연산
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    int temp = pow(2, n - 1); //n자리 이면서 가장왼쪽이 1인 이진수를 표현.
    vector<string> ans;
    ans.resize(n);

    for (int row = 0; row < n; row++) {
        int pow_2 = temp;
        for (int col = 0; col < n; col++) {
            if (arr1[row] & pow_2 || arr2[row] & pow_2) ans[row] += "#";
            else ans[row] += " ";
            pow_2 >>= 1;    //각 자리의 이진수를 검사하여 벽을 도출
        }
    }
    return ans;
}
