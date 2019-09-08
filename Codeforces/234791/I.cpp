#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
#ifdef LOCAL_DEFINE
	freopen("test.in", "r", stdin);
#else
	cin.sync_with_stdio(0);
	cin.tie(0);
#endif
	int T;
	cin >> T;

	while (T--)
	{
		string s;
		cin >> s;
		int ano = 0.0;
		for (int i = 0; i < (int)s.length(); ++i)
			if ((s[i] == '#' && (s[i + 1] == '*' || s[i + 1] == '%'))|| (s[i] == '@' && (s[i + 1] == '%' || s[i + 1] == '*')))
				ano++;
		int len = (int)s.length();
		double prec = (double)ano / (double)len;
		cout << fixed << setprecision(6) << ano << ' ' << prec << ' ';
		if (ano * 10 <= len)
			cout << "ACCEPT\n";
		else
			cout << "REJECT\n";
	}
#ifdef LOCAL_DEFINE
	cerr << "Time elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
