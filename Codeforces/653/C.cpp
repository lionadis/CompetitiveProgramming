#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n;
	cin >> n;
	rep(i,0,n) cin >> a[i];
	int ans = 0, bad_idx = -1;
	rep(i,0,n - 1){
		if(i % 2){
			if(a[i] > a[i + 1]){
				if(bad_idx != -1) return cout << "0\n", 0;
				else bad_idx = i;
			}
		} else {
			if(a[i] < a[i + 1]){
				if(bad_idx != -1) return cout << "0\n", 0;
				else bad_idx = i;
			}
		}
	}
	if(bad_idx % 2){
		rep(i,0,n - 1){
			if(i % 2){
				if(
			
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
