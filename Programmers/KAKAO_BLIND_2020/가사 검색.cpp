//Tag : #
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <map>

#define Inf                     1001001001
using namespace std;

typedef long long int           ll;
typedef pair<ll, ll>            p_ll;
typedef vector<int>             vi;
typedef vector<long long>		vl;
typedef vector<vi>              vvi;
typedef vector<vl>				vvl;
typedef vector<char>            vch;
typedef unsigned char           uchar;
typedef unsigned int            ui;
typedef unsigned long long int  ull;
/*************************************************/


int find_match(const string& queries, const vector<string> &words, int q_size) {
    int num_words = words.size();
    if (num_words == 0) return 0;

    int num_match(0);
    if (queries.front() == '?') {
        for (auto word : words) {
            bool match = true;
            for (int i = q_size - 1; i >= 0; i--) {
                if (queries[i] == '?') break;
                else {
                    if (queries[i] != word[i]) {
                        match = false; break;
                    }
                }
            }
            if (match) num_match++;
        }
    }
    else if (queries.back() == '?') {
        for (auto word : words) {
            bool match = true;
            for (int i = 0 ; i < q_size; i++) {
                if (queries[i] == '?') break;
                else {
                    if (queries[i] != word[i]) {
                        match = false; break;
                    }
                }
            }
            if (match) num_match++;
        }
    }
    return num_match;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector< vector<string> > words_per_length;
    map <string, int> q_map;
    words_per_length.resize(10001);
    for (auto word : words) {
        int w_size = word.size();
        words_per_length[w_size].push_back(word);
    }

    for (auto query : queries) {
        int q_size = query.size();
        auto q_key = q_map.find(query);

        if (q_key == q_map.end())
            q_map[query] = find_match(query, words_per_length[q_size], q_size);
        answer.push_back(q_map[query]);
    }

    return answer;
}

int main() {
    vector<string> queries = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
    vector<string> words = { "fro??", "????o", "fr???", "fro???", "pro?" };
    vector<int> ans = solution(words, queries);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ', ';
    return 0;
}
