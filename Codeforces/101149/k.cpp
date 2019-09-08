#include <bits/stdc++.h>

using namespace std;

int grid[10][10];
pair<int, int> p = {0, 0}, d = {0, 10};

bool check(pair<int, int> a){
	return 4 * ((a.first - p.first) * (a.first - p.first)  + (a.second - p.second) * (a.second - p.second)) >= (a.first - d.first) * (a.first - d.first) + (a.second - d.second) * (a.second - d.second);
}

int main(){
	// nikni ....
	int xp, yp, xd, yd;
	cin >> xp >> yp >> xd >> yd;
	long long d = (xp - xd) * (xp - xd) + (yp - yd) * (yp - yd);
	cout << fixed << setprecision(12) <<  d * 0.916297857297023 << '\n';
}
