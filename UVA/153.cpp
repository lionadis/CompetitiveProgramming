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
#define dbg(x) cerr << #x << " : " << x << "\n";
#define _ cin.sync_with_stdio(0); cin.tie(0);


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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int MAX_PR = 5000000;
bitset<MAX_PR> isprime;
vi eratosthenes_sieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}

int cnt[30], factor[45][15], a[15], n;
ll ans;
vi p;
string s;

void solve(int idx){
    if(idx == n) return;
    rep(i,0,s[idx] - 'a'){
        memset(a, 0, sizeof a);
        if(cnt[i] == 0) continue;
        cnt[i]--;
        rep(k,2,n - idx){
            rep(j,0,15) a[j] += factor[k][j];
        }
        rep(c, 0, 30){
            rep(k, 2, cnt[c] + 1){
                rep(j,0,15) a[j] -= factor[k][j];
            }
        }
        ll curr_ans = 1;
        rep(j,0,15){
            rep(x,0,a[j]) curr_ans *= p[j];
        }
        ans += curr_ans;
        cnt[i]++;
    }
    cnt[s[idx] - 'a']--;
    solve(idx + 1);
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    p = eratosthenes_sieve(40);
    rep(i,2,40){
        int x = i, idx = 0;
        while(x != 1){
            while(x % p[idx] == 0) x /= p[idx], factor[i][idx]++; 
            idx++;
        }
    }
    while(cin >> s, s != "#"){
        memset(cnt, 0, sizeof cnt);
        n = sz(s);
        trav(c, s) cnt[c - 'a'] ++;
        ans = 0;
        solve(0);
        cout << setw(10) << ans + 1 << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}