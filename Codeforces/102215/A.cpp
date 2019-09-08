#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n), last(n + 1, 1e9), ans(n + 1);
	for(int i = 0; i < n; ++ i) cin >> a[i];
	for(int i = n - 1; i >= 0; --i){
		if(a[i] > 0) ans[i] = ans[i + 1] + 1, last[a[i]] = i;
		else ans[i] = min(ans[i + 1] + 1, last[-a[i]] - i);
	}
	for(int i = 0; i < n; ++ i) cout << ans[i] << " ";
	cout << '\n';
}
