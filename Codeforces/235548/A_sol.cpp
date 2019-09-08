#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define pb push_back
#define all(v) (v).begin(),(v).end()
const int MAX = 1e6 + 10;
const ll oo = 1e16;
const ll MOD = 1e9 + 7;
ll n  , k , ans , x ;string s;

bool gotd , gotr,gota;
ll res[102][102],ret[102][102],m[102][102],tmp[102][102];
void matrixMultiplyret(){


	for(int i(0); i < n; i++){
		for(int j(0); j < n; j++){
			tmp[i][j] = 0;
			for(int k(0); k < n; k++){
				tmp[i][j] += ret[i][k] * m[k][j];
				tmp[i][j] %= MOD;
			}
		}
	}
	for(int i(0); i < n; i++)
		for(int j(0); j < n; j++)
            ret[i][j] = tmp[i][j];

}

void matrixMultiplymat(){


	for(int i(0); i < n; i++){
		for(int j(0); j < n; j++){
			tmp[i][j] = 0;
			for(int k(0); k < n; k++){
				tmp[i][j] += m[i][k] * m[k][j];
				tmp[i][j] %= MOD;
			}
		}
	}

	for(int i(0); i < n; i++)
		for(int j(0); j < n; j++)
            m[i][j] = tmp[i][j];

}

void matrixPower(ll pow){


	for(int i(0); i < n; i++) ret[i][i] = 1;

	while (pow){
		if (pow & 1){
        matrixMultiplyret();
		}
		pow >>=1;
		matrixMultiplymat();
	}


}

ll pow(ll a, ll b) {
				    ll ret = 1;
				    while (b) {
					if (b & 1) ret = ret * a % MOD;
					a = a * a % MOD;
					b >>= 1;
				    }
				    return ret;
				}



long long inv(long long a, long long b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}

void print_matrix(long long x[][102]){
	for(int i(0); i < n; i++){
		for (int j = 0; j < n; j++)
		{
			cout << x[i][j] << " ";
		}
		cout << '\n';
	}
}

signed main(){
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int strt  ;
    ll pw;
    cin>>n>>strt>>pw;
    --strt;
    for(int i = 1 ; i < n - 1 ; i ++){
    m[i][i + 1] = m[i][i - 1] = inv(4ll,MOD);
    m[i][n] = inv(2ll,MOD);
    }
   // cout<<inv(1ll,MOD)<<' '<<inv(2ll,MOD)<<' '<<inv(4ll,MOD)<<'\n';
    m[0][1] = m[n - 1][n - 2] = m[0][n] = m[n - 1][n] = inv(2ll,MOD);
    m[n][n] = inv(1ll,MOD);
    /*for(int i = 0 ; i <=n ; ++i){
    for(int j = 0 ; j <=n ; ++j)
            cout<<m[i][j]<<' ';

    cout<<'\n';
    }*/
    n+=1;
    print_matrix(m);
    matrixPower(pw);
    print_matrix(ret);
    for(int i = 0 ; i < n ; ++i){
        cout<<ret[strt][i]<<' ';
    }

    cout<<'\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
