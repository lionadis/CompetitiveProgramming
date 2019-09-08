#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int w, h, n;
int x[40404], y[40404];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	cin >> w >> h >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	x[n] = 0, x[n + 1] = w + 1;
	y[n] = 0, y[n + 1] = h + 1;
	sort(x, x + n + 2);
	sort(y, y + n + 2);

	int mx = 0;
	for(int i = 1; i < n + 2; i++)mx = max(mx, x[i] - x[i - 1] - 1);

	int my = 0;
	for(int i = 1; i < n + 2; i++)my = max(my, y[i] - y[i - 1] - 1);

	cout << mx * my << "\n";

	


}