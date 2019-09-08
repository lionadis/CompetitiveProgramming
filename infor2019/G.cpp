#include <bits/stdc++.h>

using namespace std;
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
int main(){
	freopen("test.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	unordered_map<string, int> ids;
	unordered_map<int, string> names;
	vector<vector<int> > G(2 * n);
	int id = 0;
	cin.ignore();
	string exp;
	getline(cin, exp);
	while(!is_number(exp)){
		string par, child;
		stringstream ss(exp);
		getline(ss, par, ',');
		getline(ss, child, ',');
		int u, v; 
		if(ids.count(par)) u = ids[par];
		else u = ids[par] = id++, names[u] = par;
		if(ids.count(child)) v = ids[child];
		else v = ids[child] = id++, names[v] = child;
		G[v].emplace_back(u);
		getline(cin, exp);
	}
	int q = stoi(exp);
	while(q--){
		vector<string> ans;
		string child;
		cin >> child;
		int child_id = ids[child];
		while(!G[child_id].empty()) ans.push_back(names[G[child_id][0]]), child_id = G[child_id][0];
		sort(ans.begin(), ans.end(), [&](string x, string y){
			string x_m(x), y_m(y);
			transform(x_m.begin(), x_m.end(), x_m.begin(),
               [](unsigned char c){ return std::toupper(c); });
			transform(y_m.begin(), y_m.end(), y_m.begin(),
               [](unsigned char c){ return std::toupper(c); });
            if(x_m == y_m) return x < y;
			return x_m < y_m;});
		for(string s:ans){
			while(s.back() == ' ') s.pop_back();
			cout << s << '\n';
		}
	}
}
