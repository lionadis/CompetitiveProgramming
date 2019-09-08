#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++ i){
		string s;
		cin >> s;
		if(s == "mumble") continue;
		if(atoi(s.c_str()) != i + 1) return cout << "something is fishy\n", 0;
	}
	cout << "makes sense\n";
}
