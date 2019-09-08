#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, x, y;
		cin >> n >> x >> y;
		cout << ((x >= n / 2 + 1 && y >= n / 2) ? "YES":"NO") << '\n';
	}
}
