#include <iostream>
#include <string>
using namespace std;
 
int Koutsu(const string tile[3]); //The minimum number of tiles to make Koutsu
int Shuntsu(const string tile[3]);
 
int main() {
	string tile[3];
	cin >> tile[0] >> tile[1] >> tile[2];
 
	int n1 = Koutsu(tile);
	int n2 = Shuntsu(tile);
	if (n1 <= n2)
		cout << n1;
	else
		cout << n2;
 
	return 0;
}
 
int Koutsu(const string tile[3]) {
	int num = 2;
	if (tile[0].compare(tile[1]) == 0)
		num--;
	else if (tile[0].compare(tile[2]) == 0)
		num--;
	else if (tile[1].compare(tile[2]) == 0)
		num--;
 
	if (tile[0].compare(tile[1]) == 0 && tile[0].compare(tile[2]) == 0)
		num--;
 
	return num;
}
 
 
int Shuntsu(const string tile[3]) {
	if (tile[0].compare(tile[1]) == 0)
		return 1;
	if (tile[1].compare(tile[2]) == 0)
		return 1;
	if (tile[2].compare(tile[0]) == 0)
		return 1;
 
	int num(2);
	string temp;
	temp += (tile[0][0] + 1); temp += tile[0][1];
	if (tile[1].compare(temp) == 0) {
		//0 - 1 - 2 순서일때
		num--; temp.clear();
		temp += (tile[0][0] + 2); temp += tile[0][1];
		if (tile[2].compare(temp) == 0)
			return 0;
	}
	else if (tile[2].compare(temp) == 0) {
		//0 - 2 - 1 순서일때
		num--; temp.clear();
		temp += (tile[0][0] + 2); temp += tile[0][1];
		if (tile[1].compare(temp) == 0)
			return 0;
	}
 
	temp.clear();
	temp += (tile[1][0] + 1); temp += tile[1][1];
	if (tile[0].compare(temp) == 0) {
		//1 - 0 - 2 일때
		num--; temp.clear();
		temp += (tile[1][0] + 2); temp += tile[1][1];
		if (tile[2].compare(temp) == 0)
			return 0;
	}
	else if (tile[2].compare(temp) == 0) {
		//1 - 2 - 0 일때
		num--; temp.clear();
		temp += (tile[1][0] + 2); temp += tile[1][1];
		if (tile[0].compare(temp) == 0)
			return 0;
	}
 
	temp.clear();
	temp += (tile[2][0] + 1); temp += tile[2][1];
	if (tile[0].compare(temp) == 0) {
		//2 - 0 - 1 일때
		num--; temp.clear();
		temp += (tile[2][0] + 2); temp += tile[2][1];
		if (tile[1].compare(temp) == 0)
			return 0;
	}
	else if (tile[1].compare(temp) == 0) {
		//2 - 1 - 0 일때
		num--; temp.clear();
		temp += (tile[2][0] + 2); temp += tile[2][1];
		if (tile[0].compare(temp) == 0)
			return 0;
	}
 
	temp.clear();
	temp += (tile[0][0] + 2); temp += tile[0][1];
	if (tile[1].compare(temp) == 0)
		return 1;
	else if (tile[2].compare(temp) == 0)
		return 1;
 
	temp.clear();
	temp += (tile[1][0] + 2); temp += tile[1][1];
	if (tile[0].compare(temp) == 0)
		return 1;
	else if (tile[2].compare(temp) == 0)
		return 1;
 
	temp.clear();
	temp += (tile[2][0] + 2); temp += tile[2][1];
	if (tile[0].compare(temp) == 0)
		return 1;
	else if (tile[1].compare(temp) == 0)
		return 1;
 
	return num;
}
