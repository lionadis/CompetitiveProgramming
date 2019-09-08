#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		string op = (1ll * a * b < 0 ? "-":"");
		a = abs(a), b = abs(b);
		string sa = to_string(a), sb = to_string(b), cum_a = "", cum_b = "";
		reverse(sa.begin(), sa.end());
		reverse(sb.begin(), sb.end());
		for(int i = 0; i < (int)sa.size(); ++ i){
			cum_b = "";
			if(sa[i] != '0'){
				for(int j = 0; j < (int)sb.size(); ++ j){
					if(sb[j] != '0'){
						cout << op << sa[i] << cum_a << " x " << sb[j] << cum_b << (i == (int)sa.size() - 1 && j == (int)sb.size() - 1 ? "\n" : " + ");
					}
					cum_b += "0";
				}
			}
			cum_a += "0";
		}
	}
}
