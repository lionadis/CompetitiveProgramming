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
	int n, m;
	string last, text, cipher_key, plain_text;
	cin >> n >> m >> last >> text;
	rep(i,m - n - 1,m) cipher_key += 'a' + (text[i] - last[i - (m - n - 1)] + 26) % 26;
	cout << cipher_key << '\n';
	cipher_key = cipher_key.substr(n - m % n + 1) + cipher_key.substr(0, n - m % n + 1);
	cout << cipher_key << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
