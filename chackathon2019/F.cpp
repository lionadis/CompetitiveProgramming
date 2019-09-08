#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MOD = 1e9 + 7;
const ll dx[4] = { -1,1,0,0 };
const ll dy[4] = { 0,0,-1,1 };
const ll MAX = 2e5 + 50 ;
const ll oo = 1e16;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
long long gcd(long long  a, long long  b) { return (b == 0 ? a : gcd(b, a % b)); }
ll n , m , q , ans , sz , k , x , d; string s ;
vector < pair < ll , ll > > v ;


struct UF {
	vector<int> e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
	}
};

int main(){
	freopen("test.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, q;
		cin >> n >> q;
		UF uf(n);
		ll ans = 0, curr = 0;
		while(q--){
			int u, v;
			cin >> u >> v;
			--u, --v;
			if(uf.same_set(u, v)){
				ans += curr;
				continue;
			}
			curr -= 1ll * uf.size(u) * (uf.size(u) - 1);
			curr -= 1ll * uf.size(v) * (uf.size(v) - 1);
			uf.join(u, v);
			curr += 1ll * uf.size(u) * (uf.size(u) - 1);
			ans += curr;
		}
		cout << ans << '\n';
	}
    return 0;

}

/*
1 2 2
1 10
100 10

*/
