#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(1 << n);
	for(int i = 0; i < (1 << n); ++ i) cin >> a[i];
	vector<pair<int, int> > f(1 << n);
	for(int i = 0; i < (1 << n); ++ i){
		f[i] = {i, - 1};
		for(int k = 0; k < n; ++ k){
			if(i & (1 << k)){
				vector<int> val(4);
				tie(val[0], val[1]) = f[i];
				tie(val[2], val[3]) = f[i ^ (1 << k)];
				val.erase(remove(val.begin(), val.end(), -1), val.end());
				sort(val.begin(), val.end(), [&](int x,int y){
					return a[x] > a[y];
				});
				val.erase(unique(val.begin(), val.end()), val.end());
				f[i] = {val[0], val[1]};
			}
		}
	}
	int ans = 0;
	for(int i = 1; i < (1 << n); ++ i){
		ans = max(ans, a[f[i].first] + a[f[i].second]);
		cout << ans << '\n';
	}
}
