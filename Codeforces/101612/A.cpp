#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("auxiliary.in ", "rt", stdin);
	freopen("auxiliary.out ", "wt", stdout);
	int n;
	cin >> n;
	if(n % 3 == 0) cout << n / 3 * 7 << '\n';
	if(n % 3 == 1) cout << (n / 3 - 1) * 7  + 4 << '\n';
	if(n % 3 == 2) cout << n / 3 * 7 + 1 << '\n';
}
