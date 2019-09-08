#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++ t){
		int n;
		cin >> n;
		string s;
		cin >> s;
		cout << "Case #" << t << ": ";
		for(char c:s) cout << (c == 'E' ? 'S' : 'E');
		cout << '\n';
	}
}
