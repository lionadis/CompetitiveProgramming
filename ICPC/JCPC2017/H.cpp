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
int dist[2][N], gas_station[N], m = 0, n, gas_tmp[N];
string s;

int center_m(int x){
    string a = s;
    a[gas_station[x]] = '.';
    int l, r;
    if(m == 1) l = 0, r = n - 1;
    else l = gas_station[x - 1] + 1, r = gas_station[x + 1] - 1;
    int mid = (l + r) / 2;
    a[mid] = '+';
    int mm = 0;
    rep(i,0,n){
        if(a[i] == '+') gas_tmp[mm++] = i;
    }
    int ans = 0, curr_mm = 0;
    gas_tmp[mm] = (int) 1e9;
    rep(i,0,n){
        int x = abs(i - gas_tmp[curr_mm]), y = abs(i - gas_tmp[curr_mm + 1]);
        ans = max(ans, min(x, y));
        if(x > y) curr_mm++;
    }
    return ans;
}

int center_l(int x){
    string a = s;
    a[gas_station[x]] = '.';
    int l = 0, r = gas_station[x + 1] - 1;
    int mid = (l + r) / 3;
    a[mid] = '+';
    int mm = 0;
    rep(i,0,n){
        if(a[i] == '+') gas_tmp[mm++] = i;
    }
    int ans = 0, curr_mm = 0;
    gas_tmp[mm] = (int) 1e9;
    rep(i,0,n){
        int x = abs(i - gas_tmp[curr_mm]), y = abs(i - gas_tmp[curr_mm + 1]);
        ans = max(ans, min(x, y));
        if(x > y) curr_mm++;
    }
    return ans;
}

int center_r(int x){
    string a = s;
    a[gas_station[x]] = '.';
    int l = gas_station[x - 1] + 1, r = n - 1;
    int mid = (l + r) * 2 / 3;
    a[mid] = '+';
    int mm = 0;
    rep(i,0,n){
        if(a[i] == '+') gas_tmp[mm++] = i;
    }
    int ans = 0, curr_mm = 0;
    gas_tmp[mm] = (int) 1e9;
    rep(i,0,n){
        int x = abs(i - gas_tmp[curr_mm]), y = abs(i - gas_tmp[curr_mm + 1]);
        ans = max(ans, min(x, y));
        if(x > y) curr_mm++;
    }
    return ans;
}


int center(int x){
    if(m != 1){
        if(x == 0) return center_l(x);
        else if(x == m - 1) return center_r(x);
        else return center_m(x);
    }
    return center_m(x);
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
    freopen("main.out", "w", stdout);
#else
    _
#endif
    int t;
    cin >> t;
    while(t--){
        cin >> n >> s;
        m = 0;
        rep(i,0,n){
            if(s[i] == '+') gas_station[m++] = i;
        }
        int curr_m = 0;
        gas_station[m] = (int) 1e9;
        rep(i,0,n){
            int x = abs(i - gas_station[curr_m]), y = abs(i - gas_station[curr_m + 1]);
            if(x <= y) dist[0][i] = x, dist[1][i] = curr_m;
            else dist[0][i] = y, dist[1][i] = ++curr_m;
        }
        int max_idx = max_element(dist[0], dist[0] + n) - dist[0], ans = 0;
        if(dist[0][max_idx] <= 1){
            cout << dist[0][max_idx] << '\n';
            continue;
        }
        int gas_target = dist[1][max_idx];
        //cout << s << '\n';
        ans = center(gas_target);
        if(gas_target > 0) ans = min(ans, center(gas_target - 1));
        if(gas_target < m - 1) ans = min(ans, center(gas_target + 1));
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}