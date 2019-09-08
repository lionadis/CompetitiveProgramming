#include <bits/stdc++.h>
using namespace std;
int n;
double h, w;
double x[20], y[20];
double hamil[20][1 << 20];
double dist(int u, int v){
	return sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
}
double dist(double x1, double y1, double x2, double y2){
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double dist_b(int u, int v){
	double x_o_1 = (x[u] * y[v] + x[v] * y[u]) / (y[u] + y[v]);
	double x_o_2 = (x[u] * (h - y[v]) + x[v] * (h - y[u])) / (2 * h - y[u] - y[v]);
	double y_o_1 = (y[u] * x[v] + y[v] * x[u]) / (x[u] + x[v]);
	double y_o_2 = (y[u] * (w - x[v]) + y[v] * (w - x[u])) / (2 * w - x[u] - x[v]);


	double result = dist(x[u], y[u], x_o_1, 0.0) + dist(x[v], y[v], x_o_1, 0.0);
	result =  min(result, dist(x[u], y[u], x_o_2, h) + dist(x[v], y[v], x_o_2, h));
	result =  min(result, dist(x[u], y[u], 0, y_o_1) + dist(x[v], y[v], 0, y_o_1));
	result =  min(result, dist(x[u], y[u], w, y_o_2) + dist(x[v], y[v], w, y_o_2));
	return result;
}
//double ternary_border_uv(int u, int v, double x, )
double solve(int u, int mask){

	if(hamil[u][mask] != -1)
		return hamil[u][mask];
	if((mask & (1 << u)) == 0)
		return hamil[u][mask] = 100000000.0;
	if(__builtin_popcount(mask) == 0)
		return 0.0;
	if(__builtin_popcount(mask) == 1)
		return hamil[u][mask] = dist(u, n);

	hamil[u][mask] = 100000000.0;
	for(int i = 0; i < n; i++)
		if(i != u && mask & (1 << i))
			hamil[u][mask] = min(hamil[u][mask], solve(i, mask ^ (1 << u)) + dist_b(u, i));
	return hamil[u][mask];
}
double end(int u){

	double result = solve(u, (1 << n) - 1) + x[u];
	result = min(result, solve(u, (1 << n) - 1) + w - x[u]);
	result = min(result, solve(u, (1 << n) - 1) + h - y[u]);
	result = min(result, solve(u, (1 << n) - 1) + y[u]);
	return result;
}
int main(){
	freopen("kitchen.in", "r+", stdin);
	freopen("kitchen.out", "w+", stdout);
	for(int i = 0; i < 20; i++)
		for(int m = 0; m < (1 << 20); m++)
			hamil[i][m] = -1;


	cin >> w >> h >> n;
	for(int i = 0; i <= n; i++)
		cin >> x[i] >> y[i];
	double final_result = 100000000.0;
	for(int i = 0; i < n; i++)
		final_result = min(final_result, end(i));

	 cout << fixed << setprecision(10) << final_result << "\n";


}