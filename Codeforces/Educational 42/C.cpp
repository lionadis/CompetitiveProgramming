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
ll n, ans;
string s ;
vector < vector < ll > > g;
set < ll > sqr;
vector < string > res ;

void solve(int idx, const string& s, string& curr)
{
	if (idx == n)
	{
		if (curr == "") return;
		if (sqr.find(stoi(curr)) != sqr.end()) res.push_back(curr);
		return;
	}

	if (!curr.empty() || curr.empty() && s[idx] != '0') {
        curr += s[idx],solve(idx + 1, s, curr);
        curr.pop_back();
    }

	solve(idx+1,s,curr);
}

int main(){

#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    for (int i = 1; i*i <= 2000000000; i++) sqr.insert(i*i);
    ll nb = 100;
    cin >> s;
    n = s.length();
    string tmp ;
    solve(0,s,tmp);

		if (res.size()==0)
        {
            cout << -1 << "\n";
            return 0;
        }


		for (int i = 0; i < res.size(); i++) nb = min(nb, n - (int)res[i].length());

		cout << nb ;

    return 0;

}

