#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		int x;
		cin >> x >> a[i];
	}
	cin >> k;
	int read_chapters = lower_bound(a.begin(), a.end(), k) - a.begin();
	cout << n - read_chapters << '\n';
}
