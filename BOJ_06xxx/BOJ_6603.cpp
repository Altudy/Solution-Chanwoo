#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, in, s) for(int i= in; i < s; i++) //To ease distinguish index.

typedef vector<int> v_int;

void pick_six(const v_int S);

int main() {
    ios::sync_with_stdio(false);
	int k;
	cin >> k;
	while (k > 0) {
		v_int S(k, 0);
		for (int i = 0; i < k; i++)
			cin >> S[i];
		pick_six(S);

		cin >> k;
		if(k > 0)
			cout << "\n";
	}
	


	return 0;
}

void pick_six(const v_int S) {
	int s = S.size();

	FOR(i1, 0, s - 5)
		FOR(i2, i1+1, s - 4)
		FOR(i3, i2+1, s - 3)
		FOR(i4, i3+1, s - 2)
		FOR(i5, i4+1, s - 1)
		FOR(i6, i5+1, s)
		cout << S[i1] << " " << S[i2] << " " << S[i3] << " " << S[i4] << " " << S[i5] << " " << S[i6] << "\n";
}
