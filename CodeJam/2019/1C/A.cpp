#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("test.in", "r", stdin);
	int t;
	cin >> t;
	for(int T = 1; T <= t; ++ T){
		int n;
		cin >> n;
		set<string> a;
		for(int i = 0; i < n; ++ i){
			string s;
			cin >> s;
			a.insert(s);
		}
		set<char> moves;
		map<char, char> win, loose;
		win['R'] = 'S', win['P'] = 'R', win['S'] = 'P';
		loose['R'] = 'P', loose['S'] = 'R', loose['P'] = 'S';
		string ans = "";
		bool impossible = false;
		for(int i = 0; i < 500 && a.size() != 0; ++ i){
			moves.insert('R');
			moves.insert('P');
			moves.insert('S');
			for(auto s: a){
				moves.erase(win[s[i % s.size()]]);
			}
			char move = '?';
			if(moves.size() == 0){
				impossible = true;
				break;
			}
			if(moves.size() == 1) move = *moves.begin();
			string s = *a.begin();
			if(moves.size() == 2) move = loose[s[i % s.size()]];
			vector<string>  to_erase;
			for(auto s: a){
				if(loose[s[i % s.size()]] == move) to_erase.push_back(s);
			}
			for(auto s : to_erase) a.erase(s);
			ans += move;
		}
		cout << "Case #" << T << ": " << (impossible || a.size() != 0 ? "IMPOSSIBLE" : ans) << '\n';
	}
}
