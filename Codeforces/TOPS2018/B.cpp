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
#define tl cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n"
#define Func {ans += solve(i); ++i;}


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


double p, p_set, p_game, p_match;

double solve_game(int p1, int p2){
    if(p1 == 3 && p2 == 3) return (p * p) * ( 1.0 / (1.0 - 2*p * (1 - p))) ;
    if(p1 == 4) return 1;
    if(p2 == 4) return 0;
    return p * solve_game(p1 + 1, p2) + (1.0 - p) * solve_game(p1, p2 + 1);
}

double solve_tie_break(int p1, int p2){
    if(p1 == 6 && p2 == 6) return (p * p) * ( 1.0 / (1.0 - 2*p * (1 - p))) ;
    if(p1 >= 7 && p1 - p2 >= 2) return 1;
    if(p2 >= 7 && p2 - p1 >= 2) return 0;
    return p * solve_tie_break(p1 + 1, p2) + (1.0 - p) * solve_tie_break(p1, p2 + 1);
}

double solve_set(int s1, int s2){
    if(s1 == 6 && s2 == 6) return solve_tie_break(0,0);
    if(s1 >= 6 && s1 - s2 >= 2) return 1;
    if(s2 >= 6 && s2 - s1 >= 2) return 0;
    return p_game * solve_set(s1 + 1, s2) + (1 - p_game) * solve_set(s1, s2 + 1);
}

double solve_match(int m1, int m2){
    if(m1 == 2) return 1;
    if(m2 == 2) return 0;
    return p_set * solve_match(m1 + 1, m2) + (1 - p_set) * solve_match(m1, 1 + m2);
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    cin >> p;
    p_game = solve_game(0,0);
    p_set = solve_set(0,0);
    p_match = solve_match(0,0);
    cout << fixed << setprecision(12) << p_game << ' ' << p_set << ' ' << p_match << '\n';
}