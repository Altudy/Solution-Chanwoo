// [Tag]
// #lev1
 
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <deque>
#include <map>
using namespace std;
 
#define fi     	first    
#define se     	second  
 
/** Type Define **/
typedef long long int           ll;
typedef pair<ll, ll>            p_ll;
typedef vector<string>          vs;
typedef vector<bool>            vb;
typedef vector<int>             vi;
typedef vector<long long>		vl;
typedef vector<vi>              vvi;
typedef vector<vl>				vvl;
typedef vector<char>            vch;
typedef unsigned char           uchar;
typedef unsigned int            ui;
typedef unsigned long long int  ull;
 
constexpr int               inf =   	2123456789;
constexpr long long 		INF = 		9123456789123456789;
constexpr long long         MOD =       1000000007LL;
 
template<class T>
using MaxHeap = priority_queue<T>;
template<class T>
using MinHeap = priority_queue<T,vector<T>,greater<T> >;
 
 
template<class T>
ostream& operator << (ostream &os,const vector<T> &vec){
  for(int i=0;i<vec.size();i++){
    os << vec[i];
    if(i+1<vec.size())os << ' ';
  }
  return os;
}
template<class T>
istream& operator >> (istream &is,vector<T>& vec){
  for(int i=0;i<vec.size();i++)is >> vec[i];
  return is;
}
 
 
/*************************************************/
 
int N, M;
void sol() {
	if( N == M)
      cout << "Yes\n";
  	else
      cout << "No\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    /*INPUT*/
	cin >> N >> M;
    /*Get_Answer*/
    sol();
    return 0;
}
