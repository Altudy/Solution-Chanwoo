#include <iostream>
#include <string>		//1의자리에 붙여나가면 소수인지 아닌지 좀 더 빠르게 구분 가능.
#include <vector>
#include <set>
using namespace std;

vector<int> Checked;
string strNum;
bool Select[7];
int len, cnt;

vector<char> selected;
set<int> Visit;

void find_prime(int n);
int Sum();
bool isPrime(int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cnt = 0; 
		selected.clear();
		Visit.clear();
		cin >> strNum;
		len = strNum.length();
		find_prime(0);
		cout << cnt << endl;
	}


	return 0;
}

void find_prime(int n) {
	if (selected.size() != 0) {
		int Val = Sum();
		if (Visit.find(Val) == Visit.end()) {
			Visit.insert(Val);
			if (isPrime(Val) == true) cnt++;
		}
	}

	if (n == len) return;

	for (int i = 0; i < len; i++) {
		if (Select[i] == true) continue;
		Select[i] = true;
		selected.push_back(strNum[i]);
		find_prime(n + 1);

		Select[i] = false;
		selected.pop_back();
	}

}

int Sum() {
	int sum = 0, sSize = selected.size();

	for (int i = 0; i < sSize; i++) {
		sum = sum + (selected[i] - '0');
		if (i != sSize - 1) sum = sum * 10;
	}
	return sum;
}



bool isPrime(int num)    // 소수인지 판단하는 함수
{
	if (num < 2) return false;
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0) return false;
	}
	return true;
}
