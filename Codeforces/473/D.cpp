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

const int N = 100123, MAXN=(int)1e7 + 123;
int a[N], d[MAXN];
bool vis[N];
vi primes;
set<int> primes_so_far;
 
void sieve(){
    d[1] = 1;
    rep(i,2,MAXN){
        if(d[i] == 0){
            primes.push_back(i);
            for(int j=i;j<MAXN;j+=i) d[j] = i;
        }
    }
}

vi factorize(int x){
    vi ans;
    while(x > 1){
        int p = d[x];
        while(x % p == 0) x /= p;
        ans.push_back(p);
    }
    return ans;
}

bool check(int x){
    if(x == 1) return true;
    vi factors = factorize(x);
    trav(p, factors){
        if(primes_so_far.find(p) != primes_so_far.end()) return true;
    }
    trav(p, factors) primes_so_far.insert(p);
    return false;
}


int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n = nxt();
    sieve();
    rep(i,0,n) a[i] = nxt();
    bool bigger = false;
    int last_idx = -1;
    rep(i,0,n){
        while(check(a[i])) a[i]++, bigger = true;
        if(bigger){
            last_idx = i + 1;
            break;
        }
    }
    if(last_idx != -1){
        int idx = 0;
        set<int>::iterator it = primes_so_far.begin();
        while(it != primes_so_far.end()){
                if(*it == primes[idx]){
                    vis[idx] = true;
                    ++it;
                }
                idx++;
        }
        idx = 0;
        rep(i,last_idx,n){
            while(vis[idx]) ++idx;
            a[i] = primes[idx];
            ++idx;
        }
    }
    rep(i,0,n) cout << a[i] << " ";
            

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}