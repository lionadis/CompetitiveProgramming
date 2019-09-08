#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("equal.in", "r+", stdin);
	// freopen("equal.out", "w+", stdout);
	int n, maxn = 1000123, tot = 0, cum = 0;
	cin >> n;
	vector<int> cnt(maxn), a, b, ans(n + 1);
	for(int i = 0; i < n; ++ i){
		int x;
		cin >> x;
		cnt[x] ++;
	}
	for(int i = 1; i < maxn; ++ i){
		if(cnt[i]){
			a.push_back(cnt[i]), tot++;
			for(int j = i + i; j < maxn; j += i){
				if(cnt[j]){
					b.push_back(cnt[i]);
					break;
				}
			}
		}
	}
	sort(b.begin(), b.end());
	sort(a.begin(), a.end());
	for(int i = 0; i < (int)b.size(); ++ i){
		cum += b[i];
		ans[cum] = i + 1;
	}
	cum = 0;
	for(int i = 0; i < (int)a.size(); ++ i){
		cum += a[i];
		ans[cum] = max(ans[cum], i);
	}
	for(int i = 1; i <= n; ++ i) ans[i] = max(ans[i - 1], ans[i]);
	for(int i = 0; i <= n; ++ i) cout << tot - ans[i] << " ";
	cout << '\n';
}
