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

const int maxn = 1000213;
int fib[40], f[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	fib[1] = 1;
	fib[2] = 1;
	rep(i,3,35) fib[i] = fib[i - 1] + fib[i - 2];
	f[0] = 0;
	rep(i,1,maxn){
		rep(j,1,35){
			if(fib[j] > i) break;
			f[i] = max(1 - f[i - fib[j]], f[i]);
		}
	}
	rep(i,1,100) if(!f[i]) cout << i << " ";
	cout << '\n';
	int n;
	cin >> n;
	cout << (f[n] ? "Omar\n" : "Helmi\n");
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
