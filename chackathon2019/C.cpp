#include <bits/stdc++.h>

using namespace std;
int C[1012][1012], T[1012][1012];

int main(){
	int n = 500;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= min(i, n); j++)
		{
			if (j == 0 || j == i){
				C[i][j] = 1;
				continue;
			}
			C[i][j] = (C[i - 1][j - 1]%100003 + C[i - 1][j]%100003)%100003;
		}
	}
	for(int n = 0; n < 10; ++ n){
		for(int k = 0; k < 10; ++ k){
			for(int j = 0; j <= n - k; ++ j) T[n][k] += C[n - k][j] * C[k][j];
		}
	}
	for(int i = 0; i < 10; ++ i){
		for(int j = 0; j < 10; ++ j){
			cout << T[i][j] << " ";
		}
		cout << '\n';
	}
}



