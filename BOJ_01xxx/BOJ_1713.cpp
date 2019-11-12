#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
typedef set<int>::iterator set_it;

int when[101] = {};
int voted[101] = {};
set<int> inFrame;
int maxF; //사진틀 갯수
int nowF(0);
int vote; //추천 횟수

void input() {
	cin >> maxF;
	cin >> vote;
}

int del_student() {
	set_it it = inFrame.begin();
	int bye = *it; ++it;
	while (it != inFrame.end()) {
		if (voted[*it] < voted[bye])
			bye = *it;
		else if (voted[*it] == voted[bye] && when[*it] < when[bye])
			bye = *it;
		++it;
	}
	return bye;
}

void sol() {
	int student;
	for (int i = 1; i <= vote; i++) {
		cin >> student;

		if (when[student] != 0)		//student가 사진틀에 올라와 있는 상태.
			voted[student]++;
		else {						//사진틀에 없는 상태.		
			if (maxF == nowF) {
				int bye = del_student();
				inFrame.erase(bye);
				when[bye] = 0;
				voted[bye] = 0;
			}
			else if (maxF > nowF) nowF++;

			inFrame.insert(student);
			when[student] = i;
			voted[student] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	input();
	sol();

	for (set_it it = inFrame.begin(); it != inFrame.end(); ++it)
		cout << *it << " ";

	return 0;
}
