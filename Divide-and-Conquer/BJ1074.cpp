#include <iostream>
#include <cmath>
using namespace std;

int to_rc(int N, int r, int c);
//N -- N >= 1, integer.// return required minimum distance to (r, c)

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;	//We'll get (2^N*2^N)-D array.
				//=> According to size, there are N kinds of Z.
	int r, c; 
	cin >> r >> c;

	cout << to_rc(N, r, c);

	return 0;
}

int to_rc(int N, int r, int c) {
	if (N == 1)
		return 2 * r + c;

	int width(1);
	for (int i = 0; i < N; i++) width *= 2;

	int w = width / 2; //next generation's width
	if ((r < w) && (c < w)) //upper, left square.
		return to_rc(N - 1, r, c);
	else if ((r < w) && (c >= w))
		return w * w + to_rc(N - 1, r, c - w);
	else if ((r >= w) && (c < w))
		return 2 * w * w + to_rc(N - 1, r - w, c);
	else if ((r >= w) && (c >= w))
		return 3 * w * w + to_rc(N - 1, r - w, c - w);
	
	// If error, return large negative int.
	return -100000;
}
