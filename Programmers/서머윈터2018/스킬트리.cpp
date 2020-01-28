// #lev1

#include <string>
#include <vector>

using namespace std;

int isInTree[26]{};

bool possible(const string& ST){
    int order(0);
    for(auto& st: ST){
        int n = int(st - 'A');
        if(isInTree[n] == 0) continue;
        else{
            if(order < isInTree[n] && order + 1 == isInTree[n]) order = isInTree[n];
            else return false;
        }
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int cnt(0);
    for(auto& s : skill)
        isInTree[int(s - 'A')] = (++cnt);

    for(auto& tree : skill_trees){
        if(possible(tree)) answer++;
    }

    return answer;
}
