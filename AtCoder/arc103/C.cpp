#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int> > a(2, vector<int>(100123));
	for(int i = 0; i < n; ++ i){
		int x;
		cin >> x;
		a[i % 2][x] ++;
	}
	int v0  = max_element(a[0].begin(), a[0].end()) - a[0].begin();
	int v1  = max_element(a[1].begin(), a[1].end()) - a[1].begin();
	if(v0 == v1){
		sort(a[0].begin(), a[0].end(), greater<int>());
		sort(a[1].begin(), a[1].end(), greater<int>());
		int ans1 = n - a[0][0] - a[1][1], ans2 = n - a[0][1] - a[1][0];
		cout << min(ans1, ans2) << '\n';
	}
	else {
		int ans = n - a[0][v0] - a[1][v1];
		cout << ans << '\n';
	}
}
	
