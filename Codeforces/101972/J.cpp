#include <iostream>
using namespace std;
int T;
unsigned long long int n;
unsigned long long int any_cnk_even(unsigned long long int n, int msb){
	int n0 = 0, n1 = 0;
	for(int i = msb; i >= 0; i--){
		if((n & (1ULL << i)))n1++;
		else n0 ++;
	}
	return (1ULL << n1) * ((1ULL << n0) - 1);
}
unsigned long long int smaller_cnk_even(unsigned long long int n, int msb){
	if(msb < 0)return 0ULL;
	if((n & (1ULL << msb)) == 0)return smaller_cnk_even(n, msb - 1);
	else{
		return smaller_cnk_even(n, msb - 1) + any_cnk_even(n, msb - 1);
	}
}
/*
unsigned long long int brute(unsigned long long int n){
	unsigned long long int res = 0;
	for(unsigned long long m = 0; m <= n; m++){
		for(int i = 63; i >= 0; i--){
			if(((1ULL << i) & n) == 0 && ((1ULL << i) & m) != 0){
				res++;
				break;
			}
		}
	}
	return res;
}
*/
int main(){
	/*
	for(int n = 0; n < 1000; n++){
		cout << n << " : ";
		long long int res1 = brute(n), res2;
		for(int msb = 63; msb >= 0; msb--){
			if((n & (1LL << msb))){
				res2 = smaller_cnk_even(n, msb);
				break;
			}
		}
		if(res1 != res2){
			cout << res1 << " " << res2 << '\n';
		}
		else cout << '\n';
	}
	*/
	//freopen("test.in", "r+", stdin);
	cin >> T;
	while(T--){
		cin >> n;
		bool found = false;
		for(int msb = 62; msb >= 0; msb--){
			if((n & (1ULL << msb))){
				found = true;
				cout << smaller_cnk_even(n, msb) << '\n';
				break;
			}
		}
		if(!found) cout << "0\n";
	}
}
