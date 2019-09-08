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

const int N = 100123;
vi a, b;
unordered_map<int, int> idxs;
pii s[N];

int can(int x){
    int l = 0, r = sz(b) - 1;
    int mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(b[mid] == x) break;
        if(b[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return mid;
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int t = nxt();
    while(t--){
        int n = nxt(), q = nxt();
        a.resize(n);
        rep(i,0,n) a[i] = nxt(), idxs[a[i]] = i;
        while(q--){
            int cnt = 0;
            int ans = 10;
            rep(i,0,n) rep(j,i + 1,n) s[cnt++] = {i, j};
            int x = nxt();
            //no swap
            b = a;
            if(can(x) == idxs[x]) ans = 0;
            //one swap
            rep(i,0,cnt){
                if(s[i].F != idxs[x] && s[i].S != idxs[x]){
                    b = a;
                    swap(b[s[i].F], b[s[i].S]);
                    if(can(x) == idxs[x]) ans = min(ans, 1);
                }
            }
            //two swaps
            rep(i,0,cnt){
                if(s[i].F != idxs[x] && s[i].S != idxs[x]){
                    rep(j,i+1,cnt){
                        if(s[j].F != idxs[x] && s[j].S != idxs[x]){
                            b = a;
                            swap(b[s[i].F], b[s[i].S]);
                            swap(b[s[j].F], b[s[j].S]);
                            if(can(x) == idxs[x]) ans = min(ans, 2);
                        }
                    }
                }
            }
            //three swaps
            rep(i,0,cnt){
                if(s[i].F != idxs[x] && s[i].S != idxs[x]){
                    rep(j,i+1,cnt){
                        if(s[j].F != idxs[x] && s[j].S != idxs[x]){
                            rep(k,j+1,cnt){
                                if(s[k].F != idxs[x] && s[k].S != idxs[x]){
                                    b = a;
                                    swap(b[s[i].F], b[s[i].S]);
                                    swap(b[s[j].F], b[s[j].S]);
                                    swap(b[s[k].F], b[s[k].S]);
                                    if(can(x) == idxs[x]) ans = min(ans, 3);
                                }
                            }
                        }
                    }
                }
            }
            cout << (ans != 10 ? ans : -1) << '\n';
        }

    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}