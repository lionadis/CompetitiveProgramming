#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	int n;
	cin >> n;
	vector<vector<int> > a(22, vector<int>(n));
	for(int i = 0; i < n; ++ i){
		int x;
		cin >> x;
		for(int k = 0; k < 22; ++ k) a[k][i] = ((x >> k) & 1);
	}
	for(int i = 1; i < n; ++ i){
		for(int k = 0; k < 22; ++ k) a[k][i] += a[k][i - 1];
	}
	ll ans = 0;
	for(int i = 0; i < n; ++ i){
		int curr = n - 1;
		for(int k = 0; k < 22; ++ k){
			int l = i, r = n - 1;
			while(l < r){
				int mid = (l + r + 1) / 2;
				if(a[k][mid] - (i ? a[k][i - 1] : 0) < 2) l = mid;
				else r = mid - 1;
			}
			curr = min(curr, l);
		}
		ans += curr - i + 1;
	}
	cout << ans << '\n';
}
