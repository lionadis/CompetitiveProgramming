#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int n, R;

const double PI = acos(-1);

double f(double x){
	return 4 * x * x - 2 * (R + x) * (R + x) *  (1 - cos(2 * PI / n));
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	cout.precision(10);
	cout << fixed;
	cin >> n >> R;
	double l = 0, r = 10000000;
	rep(i,0,60){
		double mid = (l + r) / 2;
		if(f(mid) > 0) r = mid;
		else l = mid;
	}
	cout << l << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
