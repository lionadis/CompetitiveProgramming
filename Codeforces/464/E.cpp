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

const int N = 500010;
int a[N], curr = 0;
ll sum[N];

double f(int l){
    return a[curr-1] - (double)(sum[l] + a[curr-1]) / (l+2.0);
}

int main(){
#ifndef ONLINE_JUDGE
    f_in
#else
    _
#endif
    int q = nxt()-1;
    int x = nxt();
    x = nxt();
    sum[curr] = a[curr++] = x;
    int l = 0;
    while(q--){
        int op = nxt();
        if(op == 1){
            x = nxt();
            a[curr] = x;
            sum[curr] = sum[curr-1] + a[curr++];
        }
        else {
            while(l < curr - 1 && f(l) < f(l+1)) l++;
            cout << fixed << setprecision(8)<< f(l) << '\n';
        }
    }
}
