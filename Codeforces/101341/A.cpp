#include <bits/stdc++.h>
using namespace std;
struct I{
	int min_score, score, idx;
};
int main(){
	int n;
	cin >> n;
	vector<I> a(n);
	for(int i = 0; i < n; ++ i){
		string s;
		cin >> s;
		int curr = 0, curr_min = 1e9;
		for(auto c : s){
			if(c == '(') curr ++;
			else curr --;
			curr_min = min(curr, curr_min);
		}
		a[i] = {curr_min, curr, i + 1};
	}
	cout << '\n';
	sort(a.begin(), a.end(), [&](I x, I y){
		if(x.min_score != y.min_score) return x.min_score > y.min_score;
		return x.score > y.score;
	});
	for(int i = 0; i < n; ++ i) cout << a[i].min_score << " " << a[i].score << " " << a[i].idx << '\n';
	int curr_score = 0;
	for(int i = 0; i < n; ++ i){
		if(curr_score < -1 * a[i].min_score) return cout << "NO\n", 0;
		curr_score += a[i].score;
	}
	if(curr_score != 0) return cout << "NO\n", 0;
	cout << "YES\n";
	for(int i = 0; i < n; ++ i){
		cout << a[i].idx << " ";
	}
	
}
