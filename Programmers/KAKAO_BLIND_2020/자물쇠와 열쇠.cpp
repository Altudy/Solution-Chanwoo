// #lev3 #탐색
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;

vector<vector<int>> next_key(const vector<vector<int>>& key) {
    //key를 오른쪽으로 90도 회전
    vector<vector<int>> copy_key;
    copy_key.assign(M, vector<int>(M, 0));

    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            copy_key[j][M - 1 - i] = key[i][j];

    return copy_key;
}

bool check_key(const vector<vector<int>> &key, const vector<vector<int>>& lock, int row, int col) {
    vector<vector<int>> result = lock;
    int l_row = row, l_col = col;
    for (int k_row(0); k_row < M; k_row++, l_row++) {
        for (int k_col(0); k_col < M; k_col++, l_col++)
            if (l_col < 0 || l_row < 0 || l_col >= N || l_row >= N) continue;
            else
            {
                result[l_row][l_col] += key[k_row][k_col];  //겹치는 부분 더해서 누적 -> 모두 1이 되어야 만족.
            }
        l_col = col;
    }   l_row = row;
        


    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (result[i][j] != 1) return false;
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    N = lock.size();
    M = key.size();
    for (int i = 0; i < 4 && !answer; i++) {                    //key를 4번 돌려봄
        for (int row = 1 - M ; row < N && !answer; row++)       //key와 lock이 (0,0)만 걸칠 때부터
            for (int col = 1 - M; col < N && !answer; col++)    //(N-1, N-1)만 걸칠때까지 모두 검사.
                answer = check_key(key, lock, row, col);        //답 찾으면 종료.
        key = next_key(key);
    }
    return answer;
}

int main() {
    vector<vector<int>> key = { {0, 0, 0},{1, 0, 0},{0, 1, 1} };
    vector<vector<int>> lock = { {1, 1, 1},{1, 1, 0},{1, 0, 1} };
    cout << solution(key, lock);

    return 0;
}
