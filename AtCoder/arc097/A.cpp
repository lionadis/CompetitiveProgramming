#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	string curr;
	vector<string> a;
	for(int i = 0; i < n; ++ i){
		for(int j = i; j < min(n, i + 5); ++ j){
			curr += s[j];
			a.push_back(curr);
		}
		curr = "";
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	cout << a[k - 1] << '\n';
}
