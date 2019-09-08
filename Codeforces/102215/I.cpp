#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll a, b;
	cin >> a >> b;
	ll left = a % b;
	ll ans = a * a - b * b - left * left;
	cout << (ans + b - 1) / b + left << '\n';
}
