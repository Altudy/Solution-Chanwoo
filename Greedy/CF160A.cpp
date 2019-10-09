//Greedy Algorithm

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
#define pb push_back;

int main() {
	int N; //the number of coins
	cin >> N;
	vi Coins(N, 0);
	for (int i(0); i < N; i++)
		cin >> Coins[i];

	sort(Coins.begin(), Coins.end()); //Sort coins in ascending order

	int sum(0);
	for (int i = 0; i < N; i++)
		sum += Coins[i];
	int th = sum / 2 + 1;//th(Threshold): either sum is even or odd, myCoin should be bigger than sum/2; 

	int myCoin(0), count(0);
	while (myCoin < th) {
		myCoin += Coins.back();
		Coins.pop_back();
		count++;
	}

	cout << count;


	return 0;
}
