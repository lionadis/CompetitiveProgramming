#include <bits/stdc++.h>
using namespace std;
int cnt[30], sb[30][30];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		memset(cnt, 0, sizeof cnt);
		memset(sb, 0, sizeof sb);
		int n, m, k;
		string a, b;
		cin >> n >> m >> k >> a >> b;
		for(int i = 0; i < n - k + 1; ++ i){
			sb[a[i] - 'a'][a[i + k - 1] - 'a'] = 1;
		}
		long long ans = 0;
		for(int i = 0; i < m; ++ i){
			cnt[b[i] - 'a'] ++;
			for(int j = 0; j < 26; ++ j){
				ans += cnt[j] * sb[j][b[i] - 'a'];
			}
		}
		cout << ans << '\n';
	}
}
