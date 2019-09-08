#include <bits/stdc++.h>
using namespace std;
bool vis[123][2];
int main(){
	freopen("boolean.in", "rt", stdin);
	freopen("boolean.out", "wt", stdout);
	string s;
	cin >> s;
	int a = 0, b = 0;
	for(int i = 0; i < (int)s.size(); ++i){
		if(s[i] == '|') continue;
		int neg = 0;
		if(s[i] == '~') neg = 1, i++;
		if(!vis[(int)s[i]][neg] && !vis[(int)s[i]][!neg]) a ++;
		if(!vis[(int)s[i]][neg] && vis[(int)s[i]][!neg]) a --, b ++;
		vis[(int)s[i]][neg] = 1;
	}
	if(b != 0) cout << (1LL << (a + b)) << '\n';
	else cout << ((1LL << a) - 1) << '\n';
}
