#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mod = 1e9 + 7, maxn = 123;
int n, s, k;
ll a[maxn][maxn], b[maxn][maxn];

ll bin_pow(ll x, int p){
	ll a = 1, b = x;
	while(p){
		if(p&1) a *= b, a %= mod;
		b *= b, b %= mod;
		p /= 2;
	}
	return a;
}

void matrix_mul(ll a[][maxn], ll b[][maxn]){
	ll res[maxn][maxn] = {};
	rep(i,0,n + 1) rep(j,0,n + 1) rep(k,0,n + 1) res[i][j] += a[i][k] * b[k][j], res[i][j] %= mod;
	rep(i,0,n + 1) rep(j,0,n + 1) a[i][j] = res[i][j];
}

void matrix_pow(ll x[][maxn], int p){
	ll a[maxn][maxn] = {}, b[maxn][maxn] = {};
	rep(i,0,n + 1) a[i][i] = 1;
	rep(i,0,n + 1) rep(j,0,n + 1) b[i][j] = x[i][j];
	while(p){
		if(p&1) matrix_mul(a, b);
		matrix_mul(b, b);
		p /= 2;
	}
	rep(i,0,n + 1) rep(j,0,n + 1) x[i][j] = a[i][j];
}

void print_matrix(ll a[][maxn]){
	rep(i,0,n + 1){
		rep(j,0,n + 1) cout << a[i][j] << " ";
		cout << '\n';
	}
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	cin >> n >> s >> k;
	rep(i,0,n){
		if(i && i < n - 1) a[i][i - 1] = a[i][i + 1] = bin_pow(4, mod - 2);
		else if(!i) a[i][i + 1] = bin_pow(2, mod - 2);
		else if(i == n - 1) a[i][i - 1] = bin_pow(2, mod - 2);
		a[i][n] = bin_pow(2, mod - 2);
	}
	a[n][n] = 1;
	matrix_pow(a, k);
	rep(i,0,n + 1) cout << a[s - 1][i] << " ";
	cout << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
