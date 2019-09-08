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

const int maxn = 90123;
const int inf = (int) 1e9 + 7;
int add[maxn], SQRT;
pii a[maxn], aux[maxn];

void fix(int l, int r, int b){
    rep(i,b * SQRT, (b + 1) * SQRT){
        if(a[i].S >= l && a[i].S < r) a[i].F++;
    }
    sort(a + b * SQRT, a + (b + 1) * SQRT);
}

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    freopen("f.in", "r", stdin);
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int n, k;
    while(cin >> n >> k, n && k){
        SQRT = sqrt(n + .0) + 1;
        rep(i,0,n){
            cin >> a[i].F;
            a[i].S = i;
        }
        copy(a, a + n, aux);
        nth_element(aux, aux + n / 2, aux + n);
        int median = aux[n / 2].F;
        for(int i=n; i%SQRT;++i) a[i] = {inf, -1};
        rep(i,0,n / SQRT + 1){
            sort(a + i * SQRT, a + (i + 1)*SQRT);
            add[i] = 0;
        }
        while(k--){
            int l, r;
            cin >> l >> r;
            l--;
            int lb = l / SQRT, rb = r / SQRT;
            rep(i,lb+1,rb) add[i]++;
            fix(l, r, lb);
            if(lb != rb) fix(l, r, rb);
            int cnt = 0;
            rep(i,0,n / SQRT + 1){
                int x = median - add[i];
                if(a[i * SQRT].F > x) cnt += SQRT;
                else if(a[(i + 1) * SQRT - 1].F <= x) cnt += 0;
                else cnt += upper_bound(a + i * SQRT, a + (i + 1) * SQRT, make_pair(x, inf)) - (a + i * SQRT);
            }
            rep(i,0,n){
                if(i && (i % SQRT) == 0) cout << "-" ;
                cout << a[i].F + add[i / SQRT] << " ";
            }
            cout << '\n';
            if(cnt <= n / 2) median ++;
            cout << median << '\n';
        }

    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}