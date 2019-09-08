#include <bits/stdc++.h>
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define _ cin.sync_with_stdio(0);cin.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define ii pair<int,int>
#define hell 1000000007
#define rep(i, a, b) for (int i = a; i<(int)b; i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define in freopen("test.in","rt",stdin)
#define out freopen("test.out","wt",stdout)
#define fi first
#define se second
#define endl "\n"
#define MOD ((ll)(1e9+7))
#define PI (double)acos(-1)
using namespace std;

string t,p; // T = text, P = pattern
vi b;
int n, m; // b = back table, n = length of T, m = length of P
vi idx;
void kmpPreprocess() { // call this before calling kmpSearch()
    int i = 0, j = -1; b[0] = -1; // starting values
    while (i < m) { // pre-process the pattern string P
        while (j >= 0 && p[i] != p[j]) j = b[j]; // different, reset j using b
        i++; j++; // if same, advance both pointers
        b[i] = j; // observe i = 8, 9, 10, 11, 12, 13 with j = 0, 1, 2, 3, 4, 5
    }
} // in the example of P = "SEVENTY SEVEN" above
void kmpSearch() { // this is similar as kmpPreprocess(), but on string T
    int i = 0, j = 0; // starting values
    while (i < n) { // search through string T
        while (j >= 0 && t[i] != p[j]) j = b[j]; // different, reset j using b
        i++; j++; // if same, advance both pointers
        if (j == m) { // a match found when j == m
            //printf("P is found at index %d in T\n", i - j);
            idx.pb(i-j);
            j = b[j]; // prepare j for the next possible match
        }
    }
}

int main(){
    
    cout << fixed;
    setprecision(4);
#ifdef LOCAL_DEFINE

    freopen("test.in", "r", stdin);
#else
    freopen("floor.in", "r", stdin);
    cin.sync_with_stdio(0); cin.tie(0);
    //cin.exceptions(cin.failbit);
#endif
    int tc;
    scanf("%d", &tc);

    double a,w,h;
    while(tc--){
//        scanf("%f %f %f\n",&a,&w,&h);
        scanf("%lf %lf %lf", &w, &h, &a);
        a=(a*PI)/180.0;
        double r=h*tan(a);
        double total=PI*r*r;
        double H=w/2;
        if(2*r<=w){
            cout<<total<<endl;
        }
        else{
            double arcs=2*(r*r*acos((H/r))-H*sqrt(r*r-H*H));
            cout<<total-arcs<<endl;
        }
    }
    return 0;
}

