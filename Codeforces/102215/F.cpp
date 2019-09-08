#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n), h(n), sa(n), sh(n);
	for(int i = 0; i < n; ++ i) cin >> a[i] >> h[i];
	itoa(sa.begin(), sa.end(), 0);
	itoa(sh.begin(), sh.end(), 0);
	sort(sa.begin(), sa.end(), [&](int x, int y){
		return a[x] < a[y];
	});
	sort(sh.begin(), sh.end(), [&](int x, int y){
		return h[x] < h[y];
	});
	int idx = 0;
	for(int i = 0; i < n; ++ i){
		while(idx < n && h[sh[idx]] <= a[sa[i]]){
			if
		}
	}
}
