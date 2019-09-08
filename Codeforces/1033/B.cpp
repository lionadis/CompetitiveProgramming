#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX_PR = 2000000;
bitset<MAX_PR> isprime;
vi eratosthenes_sieve(int lim=MAX_PR) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    vi primes = eratosthenes_sieve();
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        if(a - b != 1){
            cout << "NO\n";
            continue;
        }
        ll k = a + b;
        bool flag = true;
        trav(p, primes){
            if(p * p > k) break;
            if(k % p == 0) flag = false;
        }
        cout << (flag ? "YES\n" : "NO\n");
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}