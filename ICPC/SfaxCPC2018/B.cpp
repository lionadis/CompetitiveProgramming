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

int a[110], b[110];

string ord(int x){
    if(x % 10 == 1 && x != 11) return "st";
    if(x % 10 == 2 && x != 12) return "nd";
    if(x % 10 == 3 && x != 13) return "rd";
    return "th";
}

void print(int idx, int x, int y){
    cout << "team " << idx << " ";
    if(x == y){
        cout << "stayed at " << x << ord(x) << " position\n";
        return;
    }
    else {
        cout << "moved from " << x << ord(x) << " position to " << y << ord(y) << " position\n";
    }
}

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    freopen("scoreboard.in", "r", stdin);
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t = nxt();
    while(t--){
        int n = nxt();
        rep(i,0,n) a[nxt()] = i + 1;
        rep(i,0,n) b[nxt()] = i + 1;
        rep(i,1,n + 1){
            print(i, a[i], b[i]);
        }
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}