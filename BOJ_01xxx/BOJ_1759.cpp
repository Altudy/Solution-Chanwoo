#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<char> vchar;

int L, C, cnt(0);
char alp[15];
bool V[15];	//V[i] is true,if alp[i] is a **vowel**. 
			//3<=L<=C<=15 && At least 1 vowel, 2 consonants.
int Vs(0), Cs(0), Vp(0), Cp(0);
vchar ans;

void input();
//입력을 받으면서 모음인지 자음인지를 판별해 alp, V배열을 채운다.
void BackTracking(int index);
//사전순으로 정렬된 [0..C-1]을 각각 index 0..C-1로 생각하여 넣은경우, 제외하는 경우로 나누어 내려간다.
bool promising(int index);
//다음 index로 넘어가서 조합을 완성시킬 가능성이 있는지 판단한다.

int main() {
	ios::sync_with_stdio(false);
	cin.tie();	cout.tie();

	input();
	BackTracking(0);

	return 0;
}


void input() {
	cin >> L >> C;
	for (int i=0; i < C; i++)
		cin >> alp[i];
	sort(alp, alp + C);

	for (int i = 0; i < C; i++) {
		if (alp[i] == 'a' || alp[i] == 'e' || alp[i] == 'i'
			|| alp[i] == 'o' || alp[i] == 'u') {
			V[i] = true; Vs++;
		}
		else {
			V[i] = false; Cs++;
		}
	}
}

void BackTracking(int index) {
	if (cnt == L) {
		if (Vp >= 1 && Cp >= 2); //check for Constraints.
		else return;

		for (int i = 0; i < L; i++)
			cout << ans[i];
		cout << "\n";
	}

	if (index == C)
		return;

	if (promising(index)) {
		if (V[index] == true) { Vs--; Vp++; }
		else { Cs--; Cp++; }
		cnt++; ans.push_back(alp[index]);
		BackTracking(index + 1);

		if (V[index] == true) Vp--; 
		else Cp--;
		cnt--; ans.pop_back();
		BackTracking(index + 1);

		if (V[index] == true) Vs++;
		else Cs++;
	}

}

bool promising(int index) {
	if (Vp < 1 && Vs < (1 - Vp))//남은 모음이 충분치 않으면 false.
		return false;
	if (Cp < 2 && Cs < (2 - Cp)) //남은 자음이 충분치 않으면 false.
		return false;

	//남아있는 문자를 모두 골라도 L이 안되거나 cnt가 L을 넘어섰으면 false.
	if ((cnt + C - index >= L) && (cnt < L))
		return true;
	else 
		return false;
}
