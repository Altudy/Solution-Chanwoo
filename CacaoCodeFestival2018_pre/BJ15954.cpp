#include <iostream>
#include <cmath>
using namespace std;

#define MIN(a,b) ((a)>(b)? (b):(a))

int N, K;
int a[500];
int sum[500][500];

int main() {
	ios::sync_with_stdio(false);
	cout.precision(11);
	cin >> N >> K;
	for (int i(0); i < N; ++i)
		cin >> a[i];

	for (int i = 0; i < N; i++)	sum[i][i] = a[i];
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			sum[i][j] = sum[i][j - 1] + a[j];
      
	double Min = 987654321;
  
	for (int i = 0; i < N - K + 1; ++i) {
		for (int k = K; k < N - i + 1; ++k) {
			double m = sum[i][i + k - 1] / (double)k;
			double dsum = 0;
			for (int j = i; j < i + k; ++j) {
				dsum += (a[j] - m)*(a[j] - m);
			}
			Min = MIN(Min, sqrt(dsum / (double)k));
		}
	}

	cout << Min;
	//printf("%.11lf\n", Min);
	return 0;
}
