#include <bits/stdc++.h>
using namespace std;

bool is_in_square(pair<int, int> p1, pair<int, int> p2, pair<int, int> p){
	if(p.second == p2.second && p1.first <= p.first && p.first <= p2.first) return true;
	if(p.second == p1.second && p1.first <= p.first && p.first <= p2.first) return true;
	if(p.first == p2.first && p1.second <= p.second && p.second <= p2.second) return true;
	if(p.first == p1.first && p1.second <= p.second && p.second <= p2.second) return true;
	return false;
}

int main(){
	int n;
	cin >> n;
	n = 4 * n + 1;
	vector<pair<int, int> > a(n);
	for(int i = 0; i < n; ++ i) cin >> a[i].first >> a[i].second;
	for(int i = 0; i < n; ++ i){
		for(int j = 0; j < n; ++ j){
			if(a[i].first > a[j].first || a[i].second > a[j].second) continue;
			if(a[j].first - a[i].first != a[j].second - a[i].second) continue;
			int cnt = 0;
			for(int k = 0; k < n; ++ k){
				if(is_in_square(a[i], a[j], a[k]))
					continue;
				cnt ++;
			}
			if(cnt == 1){
				for(int k = 0; k < n; ++ k){
					if(!is_in_square(a[i], a[j], a[k]))
						return cout << a[k].first << " " << a[k].second << '\n', 0;
				}
			}
		}
	}
}
