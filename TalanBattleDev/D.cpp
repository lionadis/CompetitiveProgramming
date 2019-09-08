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

const int maxn = 12;
int a[maxn], b[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n;
	cin >> n;
	vi v;
	v.resize(n);
	rep(i,0,n){
		cin >> a[i] >> b[i], v[i] = i;
		if(a[i] > b[i]) swap(a[i], b[i]);
	}
	int ans = 0;
	do{
		int curr_time = 0;
		int curr_ans = 0;
		rep(i,0,n){
			if(a[v[i]] > curr_time) curr_time = a[v[i]] + 60, curr_ans++;
			else if(b[v[i]] > curr_time) curr_time = b[v[i]] + 60, curr_ans++;
		}
		ans = max(curr_ans, ans);
	}while(next_permutation(all(v)));
	cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
