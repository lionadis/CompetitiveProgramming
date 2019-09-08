#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define f_in freopen("test.in","r",stdin);
#define f_out freopen("test.in","w",stdout);
#define dbg(x) cerr << #x << " : " << x << "\n";
#define _ cin.sync_with_stdio(0); cin.tie(0);


inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}

template<typename T = int>
inline T nxt(){
    char c=nc();T x=0; int f=1;
    for(;c>'9'||c<'0';c=nc())if(c=='-')f=-1;
    for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc());
    x*=f;
    return x;
}

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int N = 1000 * 100 + 5;
const int M = 1000 * 1000 * 3 + 5;

vector <int> ff;
int dp[M];

int go(int curr){
	//debug(curr);
	int &ret = dp[curr];
	if(ret != -1)
		return ret;
	

	ll r = 0ll;
	for(int i = 0; i < ff.size(); i++){
		if(curr - ff[i] < 0) break;
		r |= 1ll << (go(curr - ff[i]));
	}
	for(ll i = 0; i <= 34; i++){
		if( (r & (1ll << i)) == 0){
			return ret = i;
		}
	}
}


int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    
	ff.push_back(1);
	ff.push_back(1);
	while(ff[sz(ff) - 1] <= (3 * 1000000))
		ff.push_back(ff[sz(ff) - 1] + ff[sz(ff) - 2]);
    memset(dp, -1, sizeof(dp));
    rep(i,0,100) cout << go(i) << ' ';
    cout << '\n';
    cout << go(1902) << '\n';
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}