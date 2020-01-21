// #BFS #lev4 #구현 #개같

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct pos { 
    int y[2], x[2];  // 위치와 방향 정보. y : row, x : column
    int dir[2];      // 두 좌표가 바라보는 방향을 담아서 중복된 좌표 구별 & chk로 저장.
};

int n;
int dy[] = { 0,1,0,-1 }; //오아왼위 0123.
int dx[] = { 1,0,-1,0 };
bool chk[101][101][4]; // 각 좌표에서 4방향으로 들렀는지 체크.

//좌표가 맵 범위 안에 있고, 해당 좌표에 벽이 없는지 검사.
bool range(int y1, int x1, int y2, int x2, vector<vector<int>>& mp) {
    return !(y1 < 0 || y1 >= n || x1 < 0 || x1 >= n || y2 < 0 || y2 >= n || x2 < 0 || x2 >= n || mp[y1][x1] || mp[y2][x2]);
}

int solution(vector<vector<int>> mp) {
    n = mp.size();
    queue<pos> q;

    //chk[][][0..3] 오른, 아래, 왼, 위
    chk[0][0][0] = chk[0][1][2] = true;
    q.push({ 0,0,0,1,0,2 });
    int ans(0);

    while (!q.empty()) {
        int len = q.size(); //이동 정보를 가지고 있지 않고, 한 바퀴돌릴때마다 ans++;
        while (len--) {
            pos f = q.front();
            q.pop();

            // 좌표 [n-1][n-1]에 도착했으면 종료.
            if ((f.y[0] == n - 1 && f.x[0] == n - 1) || (f.y[1] == n - 1 && f.x[1] == n - 1)) return ans;


            //각 방향으로 평행이동.
            for (int dir = 0; dir < 4; dir++) {
                int ny1 = f.y[0] + dy[dir], nx1 = f.x[0] + dx[dir];
                int ny2 = f.y[1] + dy[dir], nx2 = f.x[1] + dx[dir];
                int dir1 = f.dir[0], dir2 = f.dir[1];

                if (!range(ny1, nx1, ny2, nx2, mp) || chk[ny1][nx1][dir1] || chk[ny2][nx2][dir2]) continue;
                chk[ny1][nx1][dir1] = chk[ny2][nx2][dir2] = true;
                q.push({ ny1, ny2, nx1, nx2, dir1, dir2 });
            }

            // 회전 
            for (int i = -1; i <= 1; i++) { //돌리는 방향
                if (i == 0) continue;
                for (int j = 0; j < 2; j++) {
                    // 1번째 칸을 기준으로 돌릴건지 2번째 칸을 기준으로 돌릴건지.
                    int y = f.y[j], x = f.x[j]; 

                    int dir = (f.dir[j] + i + 4) % 4; //+4 : 음수 방지
                    int prev_dir = (dir - i + 4) % 4;
                    int oppo_dir = (dir + 2) % 4;

                    int ny2 = y + dy[dir], nx2 = x + dx[dir];
                    int ny3 = y + dy[dir] + dy[prev_dir], nx3 = x + dx[dir] + dx[prev_dir]; //회전하기 위해서 대각선 방향 비어있어야함.
                    //옮겨진 기준점에서 나머지 블록을 바라보는 방향으로 좌표 설정.

                    if (!range(ny2, nx2, ny3, nx3, mp) || chk[y][x][dir] || chk[ny2][nx2][oppo_dir]) continue;
                    chk[y][x][dir] = chk[ny2][nx2][oppo_dir] = true; // y, x가 돌려진 방향(dir)으로 바라보고 
                    q.push({ y, ny2, x, nx2, dir, oppo_dir });       // ny, nx에서 dir방향에서 만들어진 ny2, ny3에서 oppo_dir로 바라봄
                }                                                  
            }
        }
        ans++;
    }
}
