// #lev4 #Trie #문자열처리

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <deque>
#include <map>
//#pragma warning(disable:4996)

using namespace std;

// 아름다운 이름 같은 경우는 순서에 따른 경우의 수만을 계산하면 되었기 때문에
// 트라이를 완전히 만들 필요가 없었지만, 문자열을 가지고 검색을 해야하는 이런 경우,
// 트라이 구조를 완전히 만드는 것이 좋다.

/**********Trie*********Trie*********Trie********Trie*****/

//change to suit your needs
const int BRANCH_SIZE = 26;

struct Trie {
public:
    Trie* children[BRANCH_SIZE];
    bool isEndOfWord;
    int cnt;
    inline int toNum(const char& ch) { return int(ch - 'a'); }
    // Constructor
    Trie() : isEndOfWord(false), cnt(0) {
        memset(children, 0, sizeof(children));
    }
    // Destructor
    ~Trie() {
        for (int i = 0; i < BRANCH_SIZE; ++i)
            if (children[i])
                delete children[i];
    }

    void insert(const char* key) {
        // INSERT OPERATION 
        cnt++;
        if (*key == 0)
            isEndOfWord = true;
        else {
            
            int next = toNum(*key);
            if (children[next] == 0)
                children[next] = new Trie();
            children[next]->insert(key + 1);
        }

    }

    Trie* find(const char* key) {
        if (*key == 0) return this;
        int next = toNum(*key);
        if (key[next] == 0) return 0;
        return children[next]->find(key + 1);
    }

    int getCnt(const char* key) {
        if (*key == '?') return cnt;

        int next = toNum(*key);
        if (children[next] == 0) return 0;
        return children[next]->getCnt(key + 1);
    }

};

/**********Trie***********END**********Trie**********END************/



vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie* F_trie[10001];
    Trie* R_trie[10001];
    for (int i = 0; i <= 10000; i++) {
        F_trie[i] = new Trie();
        R_trie[i] = new Trie();
    }

    for (auto str : words) {
        int len = str.length();
        F_trie[len]->insert(str.data());
        reverse(str.begin(), str.end());
        R_trie[len]->insert(str.data());
    }

    for (auto q : queries) {
        int len = q.length(); int a;
        if (q.back() == '?')
            a = F_trie[len]->getCnt(q.data());
        else {//if (q.front() == '?')
            reverse(q.begin(), q.end());
            a = R_trie[len]->getCnt(q.data());
        }
        answer.push_back(a);
    }

    return answer;
}
