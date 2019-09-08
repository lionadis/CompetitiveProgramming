#include <bits/stdc++.h>
using namespace std;
int main(){
	// freopen("test.in", "r", stdin);
	string s, b="happiness";
	cin >> s;
	vector<size_t> a;
	size_t pos = s.find(b, 0);
	while(pos != string::npos){
		a.push_back(pos);
		pos = s.find(b, pos + 1);
	}
	if(a.size() == 0){
		size_t pos_h = s.find("h", 0);
		if(pos_h == string::npos || pos_h != 1 || s.size() < b.size()) cout << "YES\n1 2\n", swap(s[0], s[1]);
		else {
			cout << "YES\n2 3\n";
		}
	}
	else if (a.size() == 1) cout << "YES\n" << a[0] + 1 << " " << a[0] + 2 << '\n', swap(s[a[0]], s[a[0] + 1]);
	else if (a.size() == 2) cout << "YES\n" << a[0] + 1 << " " << a[1] + 2 << '\n', swap(s[a[0]], s[a[1] + 1]);
	else cout << "NO\n";
}

// happinessformeforyouhappinessforeverybodyfreeandletnoonebeleftbehind
