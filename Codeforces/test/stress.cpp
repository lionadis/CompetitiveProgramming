#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 59
#define MAXM 900009
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x=1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x=int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x=(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define mset(x,y) memset(&x, (y), sizeof(x));
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

bool dp[MAXN][MAXN];
ll a[MAXN];
int n, K;

bool check(ll mask) {
	FOR(i, n+1) FOR(k, K+1) {
		if (i == 0) {
			dp[i][k] = (k == 0);
		}
		else if (k == 0) {
			dp[i][k] = (i == 0);
		}
		else {
			dp[i][k] = false;
			if (k > i) continue;
			ll sum = 0;
			for(int j = i; j > 0; j--) {
				sum += a[j];
				if ((sum & mask) == mask && dp[j-1][k-1]) dp[i][k] = true;
			}
		}
	}
	return dp[n][K];
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    _
#endif
    int T;
    scanf("%d", &T);
    while(T--){
        memset(dp, 0, sizeof dp);
        int ID;
        scanf("%d %d %d", &n, &K, &ID);
        printf("%d\n", ID);
        FOR1(i, n) scanf("%lld", &a[i]);
        ll mask = 0;
        REP(i, 60) {
            mask ^= (1LL<<i);
            if (!check(mask)) mask ^= (1LL<<i);
        }
        printf("%lld\n", mask);
    }
    #ifdef LOCAL_DEFINE
        cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
    #endif
}
