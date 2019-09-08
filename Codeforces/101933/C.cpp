#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> a(367);
	for(int i = 0; i < n; ++ i){
		int d;
		cin >> d;
		a[d] = 1;
	}
	int dirty = 0, ans = 0, cum_push = 0;
	for(int i = 1; i <= 365; ++ i){
		cum_push += a[i];
		if(dirty + cum_push >= 20) ans ++, dirty = cum_push = 0;
		dirty += cum_push;
	}
	if(cum_push) ans ++;
	cout << ans << '\n';
}
