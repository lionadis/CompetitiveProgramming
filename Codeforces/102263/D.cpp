#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n, k, x, gcd_b = 0;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++ i) cin >> a[i];
	for(int i = 0; i < k; ++ i) cin >> x, gcd_b = __gcd(x, gcd_b);
	for(int i = 1; i < n; ++ i){
		int diff = abs(a[0] - a[i]);
		if(diff % gcd_b) return cout << "No\n", 0;
	}
	cout << "Yes\n";
}
