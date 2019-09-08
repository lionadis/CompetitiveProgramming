#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	for(int a = 0; a < k; ++ a){
		int b = (k - a) % k;
		if((2 * b) % k == 0){
			ll cnt = n / k + (b && ((n % k) >= b));
			ans += cnt * cnt * cnt;
		}
	}
	cout << ans << '\n';
}
