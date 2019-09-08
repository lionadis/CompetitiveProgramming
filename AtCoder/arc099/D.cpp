#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

int s(ll x){
	int res = 0;
	while(x) res += x % 10, x /= 10;
	return res;
}

int main(){
	ll k, step = 1, curr = 1;
	cin >> k;
	for(int i = 1; i <= k; ++ i){
		while((curr + 10 * step) * s(curr + step) <= (curr + step) * s(curr + 10 * step)){
			step *= 10;
		}
		cout << curr << '\n';
		curr += step;
	}
}
