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
//    freopen("test.in","r",stdin);
#else
//    cin.sync_with_stdio(0); cin.tie(0);
#endif
	srand(time(NULL));
	ll n, k;
	cin >> n >> k;
	ll l = 1, r = n;
	string ans;
	while(true){
		l = max(1ll, l - k), r = min(n, r + k);
		if(r - l <= 5 * k){
			ll pos = rand() % (r - l + 1) + l;
			cout << pos << " " << pos << '\n';
			cout.flush();
			cin >> ans;
			if(ans == "Yes") return 0;
		}
		else {
			ll mid = (l + r) / 2;
			cout << l << " " << mid << '\n';
			cout.flush();
			cin >> ans;
			if(ans == "No") l = mid + 1;
			else r = mid;
		}
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
