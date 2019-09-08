/*
    binary search the answer
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;


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

int cnt[3], n[3], p[3];
ll r;
bool can(ll x){
    ll cost = 0;
    rep(i,0,3){
        cost += p[i] * max(0LL, cnt[i] * x - n[i]);
    }
    return cost <= r;
}

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    string s;
    cin >> s;
    trav(c, s){
        if(c == 'B') cnt[0] ++;
        if(c == 'S') cnt[1] ++;
        if(c == 'C') cnt[2] ++;
    }
    rep(i,0,3) cin >> n[i];
    rep(i,0,3) cin >> p[i];
    cin >> r;
    ll l = 0, r = 1e13;
    while(l < r){
        ll mid = (l + r + 1) / 2;
        if(can(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l;


#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}