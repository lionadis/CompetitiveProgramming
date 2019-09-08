#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++ t){
		string n, a, b;
		cin >> n;
		for(char c:n){
			if(c == '4') a += '3', b += '1';
			else a += c, b += '0';
		}
		int idx = 0;
		while(b[idx] == '0') idx++;
		cout << "Case #" << t << ": " << a << " ";
		for(int i = idx; i < (int)b.size(); ++ i) cout << b[i];
		cout << '\n';
	}
}
