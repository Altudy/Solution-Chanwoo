#include <iostream>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	int M; // Money Taro will pay.
	int Coin[] = { 500, 100, 50, 10, 5, 1 }; // 6 kinds of coin.
	cin >> M;

	int change = 1000 - M;
	int cnt(0);		//cnt	-- Number of coins
					//k		-- Index for coin value, 
	for(int k = 0; k<6; k++)
		if (change >= Coin[k]) {
			cnt += change/Coin[k];
			change %= Coin[k];
		}

	cout << cnt;

	return 0;
}
