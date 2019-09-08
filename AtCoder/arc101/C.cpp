#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++ i) cin >> a[i];
	int ans = 1e9; 
	for(int i = 0; i < n - k + 1; ++ i) ans = min(ans, abs(a[i]) + a[i + k - 1] - a[i]);
	for(int i = n - 1; i >= k - 1; -- i) ans = min(ans, abs(a[i]) + a[i] - a[i - k + 1]);
	cout << ans << '\n';
}
	
