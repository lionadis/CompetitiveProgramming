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

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	ll n;
	cin >> n;
	if(n % 2 == 0 && n != 2) cout << "2\n";
	else {
		bool is_prime = true;
		for(ll i=2;i*i<=n;++i){
			if(n % i == 0){
				is_prime = false;
				break;
			}
		}
		if(is_prime) return cout << "1\n", 0;
		n -= 2;
		is_prime = true;
		for(ll i=2;i*i<=n;++i){
			if(n % i == 0){
				is_prime = false;
				break;
			}
		}
		cout << (is_prime ? "2\n" : "3\n");
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
