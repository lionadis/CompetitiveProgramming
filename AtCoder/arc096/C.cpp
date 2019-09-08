#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	ll ans = x * a + y * b;
	if(x > y) ans = min(ans, min(2 * y * c + a * (x - y), 2 * x * c));
	else ans = min(ans, min(2 * x * c + b * (y - x), 2 * y * c));
	cout << ans << '\n';
}
