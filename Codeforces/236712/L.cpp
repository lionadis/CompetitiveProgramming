#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

const double PI = 3.1415;

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int t;
	cout.precision(10);
	cout << fixed;
	cin >> t;
	while(t--){
		double h, w, l, rc, hc, f, k, m, c, n, s;
		cin >> h >> w >> l >> rc >> hc >> f >> k >> m >> c >> n >> s;
		double curr = 0, v_pyramide = l * w * h / 3, v_cylindre = rc * rc * PI * hc, ans = 0;
		if(k > f && c < v_pyramide){
			cout << "impossible\n";
			continue;
		}	
		double T_full = c / f + (v_pyramide  - c) / (f - k);
		double Q_reached = max(c, v_pyramide - k * n / 2);
		cout << v_pyramide << " " << c << '\n';
		cout << T_full << '\n';
		cout << Q_reached << '\n';
		cout << (T_full + n) * m << '\n';
		if(Q_reached - (T_full + n) * m <= 0 && Q_reached < v_cylindre){
			cout << "impossible\n";
			continue;
		}
		while(curr < v_cylindre){
			curr += Q_reached;
			ans += n/2 + T_full;
			if(curr > v_cylindre) break;
			curr -= (T_full + n) * m;
			ans += n/2;
		}
		cout << ans * s << '\n';
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
