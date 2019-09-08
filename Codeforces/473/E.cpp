#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define f_in freopen("test.in","r",stdin);
#define f_out freopen("test.in","w",stdout);
#define debug(x) cerr << #x << " : " << x << "\n";
#define _ cin.sync_with_stdio(0); cin.tie(0);


typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}

template<typename T = int>
inline T nxt(){
    char c=nc();T x=0; int f=1;
    for(;c>'9'||c<'0';c=nc())if(c=='-')f=-1;
    for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc());
    x*=f;
    return x;
}

struct edge {
  int src, dst;
  int weight;
};
struct graph {
  int n;
  vector<edge> edges;
  graph(int n = 0) : n(n) { }
  void add_edge(int src, int dst, int weight) {
    n = max(n, max(src, dst)+1);
    edges.push_back({src, dst, weight});
    edges.push_back({dst, src, weight});
  }
  vector<int> p; 
  int root(int i) { 
    return p[i] < 0 ? i : p[i] = root(p[i]); 
  }
  bool unite(int i, int j) {
    if ((i = root(i)) == (j = root(j))) return false;
    if (p[i] > p[j]) swap(i, j);
    p[i] += p[j]; p[j] = i;
    return true;
  }
  int kruskal() {
    p.assign(n, -1);
    sort(all(edges), [](edge x, edge y) {
        return x.weight < y.weight; 
    });
    int result = 0;
    for (auto e: edges) 
      if (unite(e.src, e.dst)) 
        result += e.weight;
    return result;
  }
};

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    ll n = nxt<ll>();
    n--;
    ll ans = (n + 1) >> 1;
    int k = 2;
    while(k <= 50){
        ll x = 1LL << k, y = 1LL << (k - 1);
        ans += y * (n / x);
        ll z = n % x;
        if(z >= y) ans += y;
        k++;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}