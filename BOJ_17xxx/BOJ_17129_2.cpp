/* # */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <deque>
#include <Map>
#include <iomanip>
#include <functional>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cstring>
//#pragma warning(disable:4996)

using namespace std;


/** Type Define **/
typedef long long int           ll;
typedef pair<int, int>          pii;
typedef pair<ll, ll>            pll;
typedef vector<string>          vs;
typedef vector<bool>            vb;
typedef vector<int>             vi;
typedef vector<long long>		vl;
typedef vector<vi>              vvi;
typedef vector<vl>				vvl;
typedef vector<char>            vch;
#define		it(x)  x.begin() 
#define		all(x)  x.begin(), x.end()
#define		pb(x)   push_back(x)
constexpr int           inf = 0x3f3f3f3f;
constexpr long long 	INF = 9123456789123456789;
constexpr long long     MOD = 1000000007LL;
/*************************************************/
///////////////////////////
constexpr int MAXNM = 3000;
constexpr char SPC = '0';
constexpr char WALL = '1';
constexpr char ME = '2';
constexpr char YES[5] = "TAK\n";
constexpr char NO[5] = "NIE\n";

int N, M;
char Map[MAXNM + 2][MAXNM + 2];

////////////////////////////
int que[0xffffu];
unsigned short que_in = 0, que_out = 0;

inline void init_que(void) { que_in = que_out = 0; }
inline void push_que(int a) { que[que_in++] = a; }
inline int pop_que(void) { return que[que_out++]; }
inline bool isEmpty_que(void) { return (que_in == que_out); }

#define PUSHS( a, b, c)	{ push_que(a); push_que(b);  push_que(c);	Map[a][b] = WALL;}
#define POPS( a, b, c)	{ a = pop_que(); b = pop_que(); c = pop_que();}
//////////////////////////////

void readData(void)
{
	cin >> N >> M;
	for (int n = 1; n <= N; n++)
	{
		cin >> (Map[n] + 1);
		Map[n][0] = Map[n][N + 1] = WALL;
	}
	for (int m = 1; m <= M; m++)
	{
		Map[0][m] = Map[N + 1][m] = WALL;
	}
}

int findWay(void)
{
	init_que();

	for (int n = 1; n <= N; n++)
		for (int m = 1; m <= M; m++)
		{
			if (Map[n][m] == ME)
			{
				PUSHS(n, m, 0);
				Map[n][m] = WALL;
				n = N; break;
			}
		}

	int n, m, d;
	while (!isEmpty_que())
	{
		POPS(n, m, d);
		d++;

		if (Map[n - 1][m] > WALL || Map[n][m - 1] > WALL
			|| Map[n + 1][m] > WALL || Map[n][m + 1] > WALL)	return d;

		if (Map[n - 1][m] == SPC)	PUSHS(n - 1, m, d);
		if (Map[n + 1][m] == SPC)	PUSHS(n + 1, m, d);
		if (Map[n][m - 1] == SPC)	PUSHS(n, m - 1, d);
		if (Map[n][m + 1] == SPC)	PUSHS(n, m + 1, d);
	}

	return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(nullptr);

	readData();
	int res = findWay();
	if (res == -1) cout << "NIE\n";
	else cout << "TAK\n" << res << endl;


    return 0;
}
