#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
	freopen("test.in", "r", stdin);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.length();
		string ss = s;
		sort(ss.begin(), ss.end());
		ss.erase(unique(ss.begin(), ss.end()), ss.end());
		int base = ss.size();
		base = max(base, 2);
		int count = 0;
		map<char, int> m;
		for(int i = 0; i < n; ++ i){
			if(i == 0) m[s[i]] = 1, count++;
			if(m.find(s[i]) == m.end()){
				if(count == 1) m[s[i]] = 0;
				else m[s[i]] = count;
				count ++;
			}
		}
		ll ans = 0;
		for(int i = 0; i < n; ++ i){
			ans += m[s[i]];
			if(i < n - 1) ans *= base;
		}
		cout << ans << '\n';
	}
}
