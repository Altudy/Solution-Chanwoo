// [Tag]
// #lev4 #Trie

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <deque>
#include <map>
using namespace std;

#define fi     	first    
#define se     	second  

/** Type Define **/
typedef long long int           ll;
typedef pair<int, int>          pii;
typedef pair<ll, ll>            pll;
typedef vector<string>          vs;
typedef vector<bool>            vb;
typedef vector<int>             vi;
typedef vector<long long>		vl;
typedef vector<vi>              vvi;
typedef vector<vl>				vvl;
typedef vector<char>            vch;
typedef unsigned char           uchar;
typedef unsigned int            ui;
typedef unsigned long long int  ull;

constexpr int               inf = 0x3f3f3f3f;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;

typedef pair<int, string> pis;

template<class T>
ostream& operator << (ostream& os, const vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i];
        if (i + 1 < vec.size())os << ' ';
    }
    return os;
}
template<class T>
istream& operator >> (istream& is, vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++)is >> vec[i];
    return is;
}


/*************************************************/
/*
    1. ifTab이란 member var : too large if save string. -> give different numbers each string
    2. Implement a function to update the ifTab information.
*/
/**********TRIE*********TRIE*********TRIE********TRIE*****/

//다루고 싶은 문자 종류에 따라 변경하여 사용.

const int BRANCH_SIZE = 26;


class TrieNode {
public:
    TrieNode* children[BRANCH_SIZE];
    int numOfWord; // 없으면 -1로.
    int toNumber(const char& ch) { return ch - 'A'; }

    // Constructor
    TrieNode() : numOfWord(-1) {
        // 다음 TrieNode를 가리키는 children 초기값은 
        // 모두 NULL로 비어있음을 보장하도록 합니다.
        for (int i = 0; i < BRANCH_SIZE; i++)
            children[i] = 0;
    }
    // Destructor
    ~TrieNode() {
        for (int i = 0; i < BRANCH_SIZE; ++i)
            if (children[i])
                delete children[i];
    }

    void insert(const string& key, const int& numOfS) {
        TrieNode* here = this;
        int len = key.length();
        // INSERT OPERATION 
        for (int i = 0; i < len; i++) {
            int next = toNumber(key[i]);
            if (here->children[next] == 0) //자식 노드가 없다면 생성.
                here->children[next] = new TrieNode();
            here = here->children[next]; //다음 문자로 재귀 호출.
            if (here->numOfWord == -1) here->numOfWord = numOfS;
        }
    }

    bool find(const string& key) {
        TrieNode* here = this;
        int len = key.length();
        if (len == 0) return false;         // Choose for empty strings.

        for (int i = 0; i < len; i++) {     //If isEndOfWord == true, return here.
            int next = toNumber(key[i]);    //If not, search next character.
            if (here->children[i] == 0)
                return false;
            here = here->children[i];
        }

        return here->numOfWord;     // Recursive
    }

    int requiredType(const string& key, const int& id) {
        TrieNode* here = this;
        int len = key.length();
        int type(0);

        for (int i = 0; i < len; i++) {
            int next = toNumber(key[i]);
            if (here->children[next] == NULL)
                return len;
            here = here->children[next];
            type++;
            if (here->numOfWord == id) break;
        }
        if (type == len)    return len;
        else                return type + 1;
    }

};

/**********TRIE***********END**********TRIE**********END************/
int T, N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    /*INPUT*/
    cin >> T;

    /*Get_Answer*/
    while (T--) {
        cin >> N >> M;
        string s; int f; // 출현 문자열, 빈도.
        TrieNode* Root = new TrieNode();
        vector<pis> Input(N);
        map<string, int> Mp;

        auto compare = [](pis left, pis right) -> bool {
            if (left.first == right.first)
                return left.second < right.second;
            else
                return left.first > right.first;
        };

        for (int i = 0; i < N; i++) {
            cin >> s >> f;
            Input[i] = { f, s };
        }

        sort(Input.begin(), Input.end(), compare);

        int idx(N);
        for (int i = 0; i < N; i++) {
            Root->insert(Input[i].second, idx);
            Mp[Input[i].second] = idx;
            idx--;
        }


        int ans(0);
        for (int i = 0; i < M; i++) {
            cin >> s; int id = Mp[s];
            ans += Root->requiredType(s, id);
        }
        cout << ans + M - 1 << '\n';
    }
    
    return 0;
}
