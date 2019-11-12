// 양팀의 선수를 각각 0, 1로 나타내어 1줄의 문자열로 입력이 주어진다. 만약 7명 이상의 동팀의 선수가(0또는1) 나란히 서있으면 위험한 상황이므로
// "YES"를 출력하고 그렇지 않을 경우 "NO"출력한다.
#include <iostream>
#include <string>
#include <algorithm>

//TDEF
using namespace std;

//GLOB
string str;
int cnt; char temp('2');
//FUNC
void input() {
	cin >> str;
}

//MAIN
int main() {
	ios::sync_with_stdio(false);
	input();
	for (int i = 0; i < str.size(); i++) {
		if (temp == str[i]) {
			cnt++;
			if (cnt == 7) {
				cout << "YES";
				return 0;
			}
		}
		else {
			cnt = 1;
			temp = str[i];
		}
			
	}
	cout << "NO";

	return 0;
}
