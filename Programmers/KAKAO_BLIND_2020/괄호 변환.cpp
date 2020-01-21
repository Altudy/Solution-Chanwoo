// #lev2 #문자열처리
#include <string>
#include <vector>

using namespace std;

string solution(string p) {
    if (p.empty()) return "";

    string ret; int p_size = p.length();
    char R = ')', L = '(';
    int r(0), l(0), u_size(0);
    bool u_complete(true);
    
    for (int i = 0; i < p_size; i++) {
        if (p[i] == R) r++;
        else l++;

        if (l - r < 0) u_complete = false;

        if (r > 0 && r == l) {
            u_size = i+1;
            break;
        }
    }
    string u = p.substr(0, u_size);
    //cout << "u : " << u << endl;
    string v = p.substr(u_size);
    //cout << "v : " << v << endl;
    if (u_complete)
        return u + solution(v);
    else {
        string ret = L + solution(v) + R;
        for (int i = 1; i < u_size - 1; i++)
            if (p[i] == L)    ret += R;
            else                ret += L;
        return ret;
    }

}
