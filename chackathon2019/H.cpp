#include <bits/stdc++.h>
#pragma GCC optimize ("trapv")

using namespace std;
using ll = long long;

struct item{
	string name;
	ll q, v, cnt = 0;
};

int main(){
	freopen("test.in", "r", stdin);
	int n;
	ll m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<item> a;
	while(s != "END"){
		stringstream ss(s);
		string name, sq, sv;
		getline(ss, name, ',');
		getline(ss, sq, ',');
		getline(ss, sv, ',');
		ll q = stoi(sq), v = stoi(sv);
		a.push_back({name, q, v});
		cin >> s;
	}
	sort(a.begin(), a.end(), [&](item a, item b){
		if(a.v * b.q == b.v / a.q) return a.name <= b.name;
		return a.v * b.q >= b.v * a.q;
	});
	// for(auto it:a) cout << it.name << " " << 1.0 * it.v / it.q << '\n';
	ll remaining_weight = n * m;
	for(int i = 0; i < (int)a.size(); ++i){
		ll cnt = remaining_weight / a[i].q;
		a[i].cnt = cnt;
		remaining_weight -= cnt * a[i].q;
	}
	sort(a.begin(), a.end(), [&](item a, item b){
		return a.name < b.name;
	});
	ll total_value = 0, total_weight = 0;
	for(int i = 0; i < (int)a.size(); ++i){
		if(a[i].cnt == 0) continue;
		ll w = a[i].cnt * a[i].q, v = a[i].cnt * a[i].v;
		cout << a[i].name << "," << a[i].cnt << "," << w << "," << v << "\n";
		total_weight += w;
		total_value += v;
	}
	cout << total_weight << "," << total_value << '\n';
	cout << setprecision(2) << fixed << 1.0 * total_value / n << '\n';
}
