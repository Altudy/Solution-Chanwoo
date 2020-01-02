using namespace std;
typedef long long int ll;
// W , H <= 100,000,000
ll solution(int w,int h)
{
    ll W(w), H(h);
    ll answer = W*H;
    for(int i=0; i<w; i++){
        ll from = (i*H) / W;
        ll to = ((i+1)*H) / W;
        if(((i+1)*H) % W == 0)
            answer -= (to - from);
        else
            answer -= (to - from + 1);
    }

    return answer;
}
