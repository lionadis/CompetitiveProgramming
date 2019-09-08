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

int main(){
#ifndef ONLINE_JUDGE
    f_in
    f_out
#else
    _
#endif
    srand(time(NULL));
    int n = 10, q = 10, m = 10;
    cout << n << " " << q << " " << m << '\n';
    rep(i,0,n) cout << (rand()<<16) + rand() << " ";
    cout << "\n";
    rep(i,0,q){
        int op = rand()%2 + 1, l = rand()%n + 1, r = rand()%n + 1;
        if(l>r) swap(l, r);
        cout << op << " " << l << " " << r << '\n';
    }
    rep(i,0,m) cout << rand()%n + 1 << " ";
}
