#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>

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

const int maxn = 100123;
const int lgn = 17;
int n, a[maxn];
pii f1[lgn][maxn], f2[lgn][maxn];

void build_rmq(){
    int on = 1, dep = 1;
    while(on < n) on *= 2, dep++;
    rep(i,0,n) f1[0][i] = f2[0][i] = {a[i], i};
    rep(k,0,dep - 1){
        rep(i,0,n){
            f1[k + 1][i] = min(f1[k][i], f1[k][min(i + (1 << k), n - 1)]);
            f2[k + 1][i] = max(f2[k][i], f2[k][min(i + (1 << k), n - 1)]);
        }
    }
}

int rmq1(int l, int r){
    int dep = 31 - __builtin_clz(r - l);
    return min(f1[dep][l], f1[dep][r - (1 << dep)]).S;
}

int rmq2(int l, int r){
    int dep = 31 - __builtin_clz(r - l);
    return max(f2[dep][l], f2[dep][r - (1 << dep)]).S;
}

int bin(int x, int l, int r){
    //cout << x << " " << l << " " << r << ' ';
    while(l <= r){
        if(l == r) return l;
        int m = (l + r ) / 2;
        if(a[x] < a[rmq1(l, m)]) l = m + 1;
        else r = m;
    }
}

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    while(cin >> n){
        rep(i,0,n) cin >> a[i];
        //a[n++] = 0;
        build_rmq();
        int ans = 0;
        rep(i,0,n){
            int k1 = bin(i, i + 1, n);
            int k2 = rmq2(i, k1);
            if(a[k2] > a[i]) ans = max(ans,  k2 - i);
        }
        cout << (ans == 0 ? -1 : ans) << '\n';
    }

#ifdef LOCAL_DEFINE
    //cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}