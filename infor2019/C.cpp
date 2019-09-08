#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<bool> ans;
	while(n--){
		string exp;
		cin >> exp;
		string b, c;
		stringstream ss(exp);
		getline(ss, b, ',');
		getline(ss, c, ',');
		bool a = (b == "true" || c == "true");
		ans.emplace_back(a);
	}
	reverse(ans.begin(), ans.end());
	for(bool a:ans) cout << "A is " << (a ? "true" : "false") << '\n';
}
