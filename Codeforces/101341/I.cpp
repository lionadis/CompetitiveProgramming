#include <bits/stdc++.h>
using namespace std;
using ll = long long;
pair<ll, ll> dp[200123];
int n;
struct I{
  ll start, end, value, idx;
};
vector<I> a;
vector<int> chosen;
pair<ll, ll> solve(int idx){
  if(idx >= n) return {0, 0};
  pair<ll, ll> &res = dp[idx];
  if(~(res.first)) return res;
  res = {0, 0};
  int next_idx = lower_bound(a.begin() + idx + 1, a.end(), (I){a[idx].end, -1 , -1, -1}, [&](I x, I y){
    return x.start < y.start;
  }) - a.begin();
  pair<ll, ll> ans1 = solve(idx + 1), ans2 = solve(next_idx);
  ans2 = {a[idx].value + ans2.first, a[idx].end- a[idx].start + ans2.second};
  if(ans1.first == ans2.first){
    if(ans1.second < ans2.second){
      chosen[idx] = -1;
	  return res = ans1;
    }
    else{
      chosen[idx] = next_idx;
      return res = ans2;
    }	
  }
  if (ans1.first > ans2.first){
	  chosen[idx] = -1;
	  return res = ans1;
  }
  else {
	  chosen[idx] = next_idx;
	  return res = ans2;
  }
}
int main(){
  cin >> n;
  a.resize(n);
  chosen.resize(n);
  for(int i = 0; i < n; ++ i) dp[i] = {-1, -1};
  for(int i = 0; i < n; ++ i) cin >> a[i].start >> a[i].end >> a[i].value, a[i].idx = i;
  sort(a.begin(), a.end(), [&](I x, I y){
    return x.start < y.start;
  });
  pair<ll, ll> ans = solve(0);
  vector<int> ans_idx;
  int start = 0;
  while(start != n){
    if(chosen[start] == -1) start ++;
    else ans_idx.push_back(a[start].idx + 1), start = chosen[start];
  }
  cout << ans_idx.size() << " " << ans.first << " " << ans.second << '\n';
  sort(ans_idx.begin(), ans_idx.end());
  for(auto x:ans_idx) cout << x << " ";
}
