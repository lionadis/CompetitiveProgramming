#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	int n = s.size();
	bool not_possible = (s.back() != '0' || s[0] != '1');
	for(int i = 0; i < n - 1; ++ i){
		not_possible |= (s[i] != s[n - i - 2]);
	}
	if(not_possible) return cout << "-1\n", 0;
	int now = 0;
	for(int i = 1; i < n; ++ i){
		cout << now + 1 << " " << i + 1 << "\n";
		if(s[i - 1] == '1') now = i;
	}
	return 0;
}
