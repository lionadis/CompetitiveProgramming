#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
const int maxn = 1000123;
int cnt = 0;
rope<char> v[maxn];
void Init();
void TypeLetter(char L){
	v[cnt + 1].insert(v[cnt + 1].mutable_begin(), v[cnt]);
	v[cnt + 1].push_back(L);
	cnt ++;
}
void UndoCommands(int U){
	v[cnt + 1].insert(v[cnt + 1].mutable_begin(), v[cnt - U]);
	cnt ++;
}
char GetLetter(int P){
	return v[cnt][P];
}

int main(){
	int n;
	cin >> n;
	while(n--){
		char op;
		cin >> op;
		if(op == 'T'){
			char c;
			cin >> c;
			TypeLetter(c);
		}
		if(op == 'U'){
			int k;
			cin >> k;
			UndoCommands(k);
		}
		if(op == 'P'){
			int k;
			cin >> k;
			cout << GetLetter(k) << '\n';
		}
	}
}
	
