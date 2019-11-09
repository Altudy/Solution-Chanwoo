#include <iostream>

//TDEF
using namespace std;
typedef unsigned long long ll;

//GLOB
ll n, m, a; //n*m직사각형, a*a크기의 타일

//FUNC
void input() {
	cin >> n >> m >> a;
}

ll sol() {
	ll n2, m2;

	if (n%a == 0) 
		n2 = n / a;
	else 
		n2 = n / a + 1;

	if (m%a == 0) 
		m2 = m / a;
	else 
		m2 = m / a + 1;

	return n2 * m2;
}

//MAIN
int main() {
	ios::sync_with_stdio(false);
	input();
	cout << sol();

	return 0;
}
