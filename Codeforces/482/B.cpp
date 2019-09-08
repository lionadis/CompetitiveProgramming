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

const int MAXN = 321;
int cnt_kuro[MAXN], cnt_shiro[MAXN], cnt_katie[MAXN];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n, kuro = 0,  shiro = 0, katie = 0;
    string s;
    cin >> n;
    cin >> s;
	int l = sz(s);
    
	rep(i,0,l) cnt_kuro[s[i]]++, kuro = max(kuro, cnt_kuro[s[i]]);
	cin >> s;
	rep(i,0,l) cnt_shiro[s[i]]++, shiro = max(shiro, cnt_shiro[s[i]]);
	cin >> s;
	rep(i,0,l) cnt_katie[s[i]]++, katie = max(katie, cnt_katie[s[i]]);

	if (kuro == l && n == 1) kuro = l - 1;
	else kuro = min(kuro + n, l);
	if (shiro == l && n == 1) shiro = l - 1;
	else shiro = min(shiro + n, l);
	if (katie == l && n == 1) katie = l - 1;
	else katie = min(katie + n, l);
    cout << kuro << " " << shiro << " " << katie << '\n';
	if (kuro > shiro && kuro > katie) cout << "Kuro" << '\n';
	else if (shiro > kuro && shiro > katie) cout << "Shiro" << '\n';
	else if (katie > kuro && katie > shiro) cout << "Katie" << '\n';
	else cout << "Draw" << '\n';
	return 0;

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}