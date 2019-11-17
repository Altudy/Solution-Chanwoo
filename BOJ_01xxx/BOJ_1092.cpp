#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> v_int;

bool crainwork(v_int& crain_box, int crain_n);
//func: 들 수 있는 짐을 하나 옮긴다. crain_box[crain_n]에 할당된 남아있는 box가 없으면 crain_box[crain_n - 1]로 재귀한다.
//return: 옮겼으면 true 반환. 들 수 있는 남아있는 상자가 하나도 없으면 false반환

int main() {
	int N, M;
	cin >> N;
	v_int crain(N), crain_box(N, 0);
	for (int i = 0; i < N; i++)
		cin >> crain[i];

	cin >> M;
	v_int  box(M);
	for (int i = 0; i < M; i++)
		cin >> box[i];
	
	//오름차순 정렬
	sort(crain.begin(), crain.end());
	sort(box.begin(), box.end());

	//제일 센 크레인이 옮길수 없는 물건이 있을때.
	if (box.back() > crain.back()) {
		cout << -1;
		return 0;
	}

  //각 crain에 box 수 할당
	for (int i = 0, j = 0; i < M; i++) {
		if(box[i] <= crain[j])
			crain_box[j]++;
		else {
			while (box[i] > crain[j])
				j++;
			crain_box[j]++;
		}
	}

	bool done = false;
	int count = 0;
	while (!done) {
		for (int i = N - 1; i >= 0; i--) {
			if (!crainwork(crain_box, i) && (i == N - 1)) {
				cout << count;
				done = true;
			}
		}
		count++;
	}


	return 0;
}

bool crainwork(v_int& crain_box, int crain_n) {
	if (crain_box[crain_n] > 0)
		--crain_box[crain_n];
	else if (crain_n == 0)// crain_0 has 0
		return false;
	else
		return crainwork(crain_box, crain_n - 1);

	return true;
}	
