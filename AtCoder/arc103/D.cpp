#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool check(pair<ll, ll> a, ll lim){
	return abs(a.first) + abs(a.second) <= lim;
}

int main(){
	int n;
	cin >> n;
	vector<pair<int, int> > a(n);
	int parity = -1;
	for(int i = 0; i < n; ++ i){
		int x, y;
		cin >> x >> y;
		if(parity == -1) parity = abs(x + y) % 2;
		else {
			if(parity != abs(x + y) % 2) return cout << "-1\n", 0;
		}
		a[i] = {x, y};
	}
	int m = 31;
	vector<int> d(m);
	d[0] = 1;
	for(int i = 1; i < m; ++ i) d[i] = 2 * d[i - 1];
	if(parity == 0) d.push_back(1), sort(d.begin(), d.end()), m++;
	reverse(d.begin(), d.end());
	cout << m << '\n';
	for(int i = 0; i < m; ++ i) cout << d[i] << " ";
	cout << '\n';
	for(int i = 0; i < n; ++ i){
		for(int j = 0; j < m; ++ j){
			int lim = d[j] - parity;
			if(check(make_pair(a[i].first - d[j], a[i].second), lim)) cout << "R", a[i].first -= d[j];
			else if(check(make_pair(a[i].first + d[j], a[i].second), lim)) cout << "L", a[i].first += d[j];
			else if(check(make_pair(a[i].first, a[i].second - d[j]), lim)) cout << "U", a[i].second -= d[j];
			else if(check(make_pair(a[i].first, a[i].second + d[j]), lim)) cout << "D", a[i].second += d[j];
		}
		cout << '\n';
	}
}
			
	
	
