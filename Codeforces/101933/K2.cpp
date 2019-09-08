#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long int dp[3000][3000];
int n, k, p;
long long int solve(long long x){
	long long lo = 0 , hi = 1e9 + 2 ;
	while(lo <= hi){
		long long mid = (lo + hi) >> 1 ;
		if(mid * (mid - 1) / 2 == x)
			return mid;
		if(mid * (mid - 1) / 2 > x)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	return -1;
}

int a, b , c , d;
bool util(long long int x , long long int y){
	if(x * y != b + c || x == -1 || y == -1 || x * (x - 1)/2 != a || y * (y - 1) / 2 != d) return false;
	int front_ones = 0 , back_ones = y ;
	front_ones = c / x ;
	back_ones -= front_ones;
	c %= x ;
	back_ones -= (c > 0);
	for(int i = 0 ; i < front_ones ; ++i)
		cout << 1 ;
	for(int i = 0 ; i < x - c ; ++i)
		cout << 0 ;
	if(c)
		cout << 1 ;
	for(int i = 0 ; i < c ; ++i)
		cout << 0 ;
	for(int i = 0 ; i < back_ones ; ++i)
		cout << 1 ;
	
	
	return true;
	
}

int main(){
	cin >> a >> b >> c >> d;
	int x = solve(a);
	int y = solve(d);
	if(a == 0 && d == 0){
		if(b == 0 && c == 0)return 0;
		if((b > 0 && c > 0) || b + c > 1) return cout << "impossible\n", 0;
		if(b)
			cout << "01\n";
		else
			cout << "10\n";
		return 0;
	}
	if(a == 0){
		if( a + b + c + d == d){
			int y = solve(d);
		if( b + c > 0 || y == -1) return cout << "impossible\n", 0;
		for(int i = 0 ; i < y ; ++i)
			cout << 1 ;
		}
		else 
			if( util(x + 1 , y) ) return 0;
			 
		
		return cout << "impossible\n", 0;
	}
	
		

	
	if(util(x,y) || util(x + 1 , y) || util(x, y + 1) || util(x + 1 , y + 1)) return 0;
	cout << "impossible\n";
	
}
