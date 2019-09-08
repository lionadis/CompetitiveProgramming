#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

const int maxn = 100123;
int a[maxn], cnt[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n, m;
	cin >> n >> m;
	rep(i,0,m) cin >> a[i], a[i]--;
	int left = n;
	rep(i,0,m){
		cnt[a[i]]++;
		if(cnt[a[i]] == 1){
			left--;
			if(!left){
				left = n;
				rep(j,0,n){
					cnt[j]--;
					if(cnt[j]) left--;
				}
				cout << '1';
			}
			else cout << '0';
		}
		else cout << '0';
	}
	cout << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
