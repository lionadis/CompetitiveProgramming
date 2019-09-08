#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>

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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int N = 10123;
int a[N];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        rep(i,0,n) cin >> a[i];
        if(n % 2) a[n++] = 0;
        sort(a, a + n);
        
        int ans = 0;
        for(int i=0;i<n;i+=2){
            ans ^= (a[i + 1] - a[i] - 1);
        }
        if(ans) cout << "Georgia will win\n";
        else cout << "Bob will win\n";
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}