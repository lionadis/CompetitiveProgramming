#include <bits/stdc++.h>

using namespace std;

struct piece{
	int p, h, id;
};

int main(){
	freopen("test.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<int> p(n), h(n);
	vector<piece> back(n), front(n);
	for(int i = 0; i < n; ++ i) cin >> p[i];
	for(int i = 0; i < n; ++ i) cin >> h[i];
	for(int i = 0; i < n; ++ i) back[i] = {p[i], h[i], i + 1};
	for(int i = 0; i < n; ++ i) cin >> p[i];
	for(int i = 0; i < n; ++ i) cin >> h[i];
	for(int i = 0; i < n; ++ i) front[i] = {p[i], h[i], i + 1};
	sort(back.begin(), back.end(), [&](piece &a, piece &b){
		if(a.p == b.p) return a.h < b.h;
		return a.p < b.p;
	});
	sort(front.begin(), front.end(), [&](piece &a, piece &b){
		if(a.p == b.p) return a.h < b.h;
		return a.p < b.p;
	});
	for(piece p:back) cout << p.p << "," << p.h << " ";
	cout << '\n';
	for(piece p:front) cout << p.p << "," << p.h << " ";
	cout << '\n';
	bool check = false;
	for(int i = 0; i < n; ++ i) check |= (front[i].h >= back[i].h);
	if(check) return cout << "impossible\n", 0;
	for(int i = 0; i < n; ++ i) cout << back[i].id << " ";
	cout << '\n';
	for(int i = 0; i < n; ++ i) cout << front[i].id << " ";
	cout << '\n';
}
