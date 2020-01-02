//#그리디 #lev3 #class
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>

#define Inf             987654321
using namespace std;

typedef long long int   ll;
typedef pair<ll, ll>    pii;
typedef vector<ll>      vi;
typedef vector<vi>      vii;

/*************************************************/
int N, C, M;
int D[2001][2001] = {};
int ans;

void sol() {
    int T(0);
    int truck[2001] = {};
    //truck[i] : i번째 마을에서 출발할때 트럭이 가지고 있는 상자개수
    for (int to = 2; to <= N; to++) {
        for (int from = 1; from < to; from++) {
            int* box = &D[from][to];
            if (*box == 0)  //보내는 상자가 없으면 넘김.
                continue;
            else {       
                //from에서 to로 보내는 상자 box개 있음
                // : 도착지까지 box만큼보낼수 있는지 검사
                // 보낼수 있는 만큼 ans에 추가하고, truck[i]갱신.
                int mx = truck[from];
                for (int i = from + 1; i < to; i++)
                    mx = mx < truck[i] ? truck[i] : mx;
                int nbox = C - mx >= *box ? *box : C - mx;
                ans += nbox;
                for (int i = from; i < to; i++)
                    truck[i] += nbox;
            }
        }
    }

    cout << ans;
}

void input() {
    int from, to, lugg;
    cin >> N >> C >> M;
    for (int i = 0; i < M; i++) { //2차원 배열로 맵핑.
        cin >> from >> to >> lugg;
        D[from][to] = lugg;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    input();
    sol();


    return 0;
}

/*
struct Schedule { int f, t, k; } sc[10000];     //f:from , t:to k:box

//도착지 오름차순 -> 출발지 오름차순 정렬 위한 compare 함수
bool cmp(const Schedule &a, const Schedule &b) {
	if(a.t<b.t) 
    return true; 
  else 
    if(a.t>b.t) return false;
	return a.f < b.f;
}

int main() {
	int n, c, m, min, ans=0, i, j; 
  static int stop[2000];
  
	cin >> n >> c >> m;
	for(i=0;i<m;i++) 
    cin >> sc[i].f >> sc[i].t >> sc[i].k, sc[i].f--;, sc[i].t--;
  std::sort(sc,sc+m,cmp);
	
  for(i=0;i<m;i++) {
		for(j=sc[i].f,min=sc[i].k;j<sc[i].t;j++) 
      min=c-stop[j]<min?c-stop[j]:min;
		for(j=sc[i].f;j<sc[i].t;j++) 
      stop[j]+=min;
		ans+=min;
	}
	printf("%d\n", ans);

}

*/
