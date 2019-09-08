#include <bits/stdc++.h>
using namespace std;
const int N = 10;
map<int, set<int> > m;
int main(){
	for(int k = 0; k < 1 << N; ++ k){
		bitset<N> b(k);
		for(int i = 1; i < N; ++ i){
			auto curr = (b >> i | b << (N - i)) ^ b;
			m[curr.to_ulong()].insert(i);
			// cout << ((b >> i | b << (N - i)) ^ b) << " ";
		}
		// cout << '\n';
	}
	int l = 0, d = 1000;
	for(int k = l; k < d + l; ++k){
		cout << k << " " << bitset<N>(k) << " " << m[k].size() << " " << __builtin_popcount(k) << '\n';
	}
}
