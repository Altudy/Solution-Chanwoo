// #lev1 #구현
#include <string>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
pair<int, int> bot;

bool range(int nx, int ny){
    return (nx >= -5 && nx <= 5 && ny <= 5 && ny >= -5);    
}

pii move(char c){
    if(c == 'U') return pii{0, 1};
    else if(c == 'L') return pii{-1, 0};
    else if(c == 'R') return pii{1, 0};
    else return pii{0, -1};
}

int solution(string dirs) {
    int answer = 0; bot = {0, 0};
    bool chk[242]{};
    // (-5, -5) = ((y-5)*22 + (x-5)*2 + rest); rest0:세로. rest1:가로.
    for(auto& d : dirs){
        pii mov = move(d);
        int nx = bot.first + mov.first;
        int ny = bot.second + mov.second;
        if(range(nx, ny)){
            if(d == 'U' || d == 'D'){
                int rest = 0; //세로축
                int x_ = nx, y_ = ny > bot.second ? bot.second : ny; //검사 좌표
                int idx = (y_ + 5) * 22 + (x_ + 5) * 2 + rest;
                if(chk[idx] == 0) {chk[idx] = 1; answer++;}
            }
            else{
                int rest = 1; //가로축
                int y_ = ny, x_ = nx > bot.first ? bot.first : nx; //검사 좌표
                int idx = (y_ + 5) * 22 + (x_ + 5) * 2 + rest;
                if(chk[idx] == 0) {chk[idx] = 1; answer++;}
            }
            bot.first = nx; bot.second = ny;
        }
        else continue;
    }
    return answer;
}
