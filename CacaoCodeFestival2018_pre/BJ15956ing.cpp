/*
1. 입력 받은 조건문을 파싱하는데 ==과 !=을 구분하여 파싱합니다.

2. ==인 요소끼리 merge 함수를 이용하여 한 그룹에 합칩니다.

3. 각각의 그룹끼리 나눕니다.

4. 각 그룹을 순회하면서 답을 구성하는데 모순이 발생하는 경우 바로 거짓이면서 제일 짧은 조건문(길이: 4)을 출력하고 프로그램을 끝냅니다.

-> 모순이 아니라면 그룹 내 제일 짧은 요소를 찾고 해당 요소가 답에 꼭 포함되도록 합니다.

5. !=로 연결되는 쌍을 저장하는데 STL set을 이용하여 중복이 없도록 합니다.

-> 마찬가지로 모순이 발생하면 4번처럼 길이가 4인 조건문을 출력하고 프로그램을 끝냅니다.

6. 모든 절이 참이라면 답이 빈칸이 되는데 이를 방지하기 위해 답이 빈칸이라면 참이면서 제일 짧은 조건문(길이: 4)를 출력하도록 합니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1000000; //조건문의 길이가 최대10^6까지로 주어짐

string input;
int parent[MAX]; //Initialize to -1.
vector<string> group[MAX];
bool hasNumber[MAX];

//Union Find개념 집합
int find(int num) {
	if (parent[num] < 0)
		return num;
	else//path compression을 적용한 union find
		return parent[num] = find(parent[num]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b)
		return; //같은 집합안의 요소면 합칠필요없음
	if (parent[a] < parent[b]) {
		parent[a] += parent[b];
		parent[b] = a;
	}
	else {
		parent[b] += parent[a];
		parent[a] = b;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	memset(parent, -1, sizeof(parent));
	cin >> input;
	input += "&&";
	//끊는 조건을 &&로 할것이라 input의 마지막에 넣어주는듯

	map<string, int> str2int; //변수에 임의의 번호 부여
	vector<string> int2str; //번호를 변수로

	vector<pair<int, int>> same; //==으로 연결된 변수들
	vector<pair<int, int>> diff; //!=으로 연결된 변수들

	string tempS[2]; //파싱중인 절에 들어가는 두 변수를 임의로 저장.
	bool usingSpos = 0; //현재 파싱중인 절의 앞/뒤를 표시
	bool isDifferent;	//현재 파싱중인 절이 ==인지 !=인지 표시

	for (int i = 0; i < input.size(); i++) {
		//
		if (input[i] != '=' && input[i] != '&' && input[i] != '!')
			tempS[usingSpos].push_back(input[i]);
		//절의 첫번째 변수가 완성되었을 경우.
		else if (usingSpos == 0) {
			isDifferent = (input[i] == '!');
			usingSpos = 1;
			i++; //Jump one more char.
		}
		//절의 두번째 변수가 완성되었을 경우.
		else {
			int a, b;
			//변수에 해당하는 변호를 찾아내거나 새로 매긴다.
			if (str2int.count(tempS[0]))
				a = str2int[tempS[0]];
			else {
				str2int[tempS[0]] = int2str.size();
				a = int2str.size();
				int2str.push_back(tempS[0]);
			}

			if (str2int.count(tempS[1]))
				b = str2int[tempS[1]];
			else {
				str2int[tempS[1]] = int2str.size();
				b = int2str.size();
				int2str.push_back(tempS[1]);
			}

			// If == -> same, != -> diff
			if (!isDifferent)
				same.push_back({ a, b });
			else
				diff.push_back({ a, b });

			//Initialize
			tempS[0] = tempS[1] = "";
			usingSpos = 0;
			i++; //Jump one more char.
		}
	}

	string answer;

	// Merge all == component;
	for (int i = 0; i < same.size(); i++)
		merge(same[i].first, same[i].second);

	//Store vaiable whose parent is i in group;
	//int2str gaurantees there're no same variable in group.
	for (int i = 0; i < int2str.size(); i++)
		group[find(i)].push_back(int2str[i]);

	//Organize answers by traversing each group
	for (int i = 0; i < int2str.size(); i++) {
		//이 그룹에 상수가 2개 이상 있다면 항상  거짓.
		int cntNumber = 0;
		for (int j = 0; j < group[i].size(); j++)
			cntNumber _ - (isdigit(group[i][j][0]) || (group[i][j][0] == '-'));
		if (cntNumber >= 2) {
			cout << "0==1";
			return 0;
		}
		//상수가 있는 절은 나중에 필요
		if (cntNumber == 1)
			hasNumber[i] = true;

		//그룹의 원소가 3이상이면, 답에 포함되어야한다.
		if (group[i].size() < 2)
			continue;

		//이 그룹에서 가장 길이가 짧은 변수를 찾아낸다.
		int minLength = group[i][0].size(), minIdx = 0;
		for (int j = 1; j < group[i].size(); j++) {
			if (group[i][j].size() < minLength) {
				minLength = group[i][j].size();
				minIdx = j;
			}
		}

		string temp = group[i][minIdx];
		for (int j = 0; j < group[i].size(); j++) {
			if (j == minIdx)
				continue;
			answer += group[i][j] + "==" + temp + "&&";
		}
		//길이가 가장 짧은 원소는 맨 앞에 놔둔다.
		swap(group[i][0], group[i][minIdx]);
	}

	//Store != group
	set<pair<int, int>> diffZip;
	for (int i = 0; i < diff.size(); i++) {
		int a = find(diff[i].first);
		int b = find(diff[i].second);
		
		if (a == b)	return 2;
		if (hasNumber[a] && hasNumber[b]) continue;
		diffZip.insert({ min(a,b), max(a, b) }); //Prevent duplicate
	}

	for (set<pair<int, int>>::iterator it = diffZip.begin(); it != diffZip.end(); it++) {
		int a = (*it).first;
		int b = (*it).second;

		answer += group[(*it).first][0] + "!=" + group[(*it).second][0] + "&&";
	}



	//If answer's empty
	if (answer.empty()) {
		cout << "1 == 1";
		return 0;
	}

	for (int i = 0; i < 2; i++)
		answer.pop_back();
	cout << answer << "\n";
	return 0;
}
