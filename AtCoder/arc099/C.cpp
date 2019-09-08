#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	if((n - k) % (k - 1) == 0) cout << (n - k) / (k - 1) + 1 << '\n';
	else {
		k-- ;
		cout << (n + k - 1) / k << '\n';
	}
}
