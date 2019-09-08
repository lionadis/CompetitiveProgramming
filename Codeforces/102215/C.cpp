#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll p, n;
	cin >> p >> n;
	vector<bool> vis(p);
	ll curr_pos = 0;
	for(int i = 0; i <= min(p, n); ++ i){
		curr_pos += i;
		curr_pos %= p;
		vis[curr_pos] = 1;
	}
	int ans = 0;
	for(int i = 0; i < p; ++ i) ans += vis[i];
	cout << ans << '\n';
}
