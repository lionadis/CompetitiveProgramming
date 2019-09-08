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
#define debug(x) cerr << #x << " : " << x << "\n";
#define _ cin.sync_with_stdio(0); cin.tie(0);
#define tl cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n"
#define Func {ans += solve(i); ++i;}


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
    for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc()); x*=f;
    return x;
}

const int N = 200100;
int a[N];

int main(){
#ifndef ONLINE_JUDGE
    f_in
#else
    _
#endif
    int n = nxt();
    rep(i,0,n) a[i] = nxt();
    rep(i,n,2*n) a[i] = a[i-n];
    int start = 1, ans = 0, curr_ans = 0, s = nxt(), f = nxt(), level = f - s;
    rep(i,n,n+level) curr_ans += a[i];
    ans = curr_ans;
    for(int i=n-1;i>0;--i){
        curr_ans = curr_ans + a[i] - a[i+level];
        int curr_start = s-i;
        if(curr_start < 1) curr_start += n;
        if(curr_ans == ans) start = min(curr_start, start);
        if(curr_ans > ans){
            ans = curr_ans;
            start = curr_start;
        }
    }
    cout << start << '\n';
}
