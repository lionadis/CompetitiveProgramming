#include <bits/stdc++.h>
using namespace std;


#define f_in freopen("test.in","r",stdin);
#define f_out freopen("test.in","w",stdout);
#define _ cin.sync_with_stdio(0); cin.tie(0);

typedef unsigned long long ll;
ll n, m, k, a, y;

int main() {
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    cin >> n >> m >> k;
    if(k<n) {cout<<k+1<<" "<<1;return 0;}
else
{
    ll a, b;
    k-=n;
    a=k/(m-1);
    b=k%(m-1);
    if(a%2) cout<<n-a<<" "<<m-b;
    else cout<<n-a<<" "<<1+b+1;
}
    return 0;
}