#include <bits/stdc++.h>

using namespace std;

int s(int x){
	int res = 0;
	while(x) res += x % 10, x /= 10;
	return res;
}

int main(){
	int n = 1000000, cnt = 0, prev = 1, step_cnt = 0, prev_step = 0;
	for(int i = 1; i < n; ++ i){
		bool check = true;
		for(int j = i + 1; j < n; ++ j){
			if(!(s(i) * j >= s(j) * i)){
				check = false;
				break;
			}
		}
		if(check){
			int step = i - prev;
			cout << i << '\n';
			cnt++;
			// cout << i << ", step=" << step << '\n', cnt++;
			if(step != prev_step){
				prev_step = step;
				// cout << step_cnt << '\n';
				step_cnt = 0;
			}
			step_cnt++;
			prev = i;
			if(cnt % 10 == 9) cout << '\n';
			if(cnt == 100) break;
		}
	}
}
