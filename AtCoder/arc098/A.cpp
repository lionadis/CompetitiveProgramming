#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> cnt_w(n), cnt_e(n);
	string s;
	cin >> s;
	for(int i = 0; i < n; ++ i){
		if(s[i] == 'W') cnt_w[i] = 1;
		else cnt_e[i] = 1;
	}
	for(int i = 1; i < n; ++ i){
		cnt_w[i] += cnt_w[i - 1];
		cnt_e[i] += cnt_e[i - 1];
	}
	int ans = n;
	for(int i = 0; i < n; ++ i){
		int curr = 0;
		if(i > 0) curr += cnt_w[i - 1];
		if(i < n - 1) curr += cnt_e[n - 1] - cnt_e[i];
		ans = min(ans, curr);
	}
	cout << ans << '\n';
}
