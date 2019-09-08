#include <bits/stdc++.h>

using namespace std;

int main(){
	int l;
	cin >> l;
	int r = 32 - __builtin_clz(l);
	cout << r << " " << 2 * (r - 1) + __builtin_popcount(l) - 1 << '\n';
	for(int i = 1; i < r; ++ i){
		cout << i << " " << i + 1 << " " << 0 << '\n';
		cout << i << " " << i + 1 << " " << (1 << (i - 1)) << '\n';
	}
	int e = 1 << (r - 1);
	int curr = r - 1;
	while(curr--){
		if(l & (1 << curr)){
			cout << curr + 1 << " " << r << " " << e << '\n';
			e |= (1 << curr);
		}
	}
}
