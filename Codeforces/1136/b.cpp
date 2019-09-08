#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int ans = 2 * n - 1;
	ans += min(k - 1, n - k);
	ans += n + 1;
	cout << ans << '\n';
}
	
