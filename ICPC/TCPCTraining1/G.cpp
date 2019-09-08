#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define F first
#define S second
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


bool vis[17];
int a[6][6], b[6][6], ans[6][6];
pii pos[12];
int v[12];

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t = nxt();
    rep(T, 1, t + 1){
        int idx = 0;
        memset(vis, 0, sizeof vis);
        rep(i,0,4){
            rep(j,0,4){
                a[i][j] = nxt();
                if(a[i][j] != -1) vis[a[i][j]] = true;
                else pos[idx++] = {i, j};
            }
        }
        idx = 0;
        rep(i,1,17) if(!vis[i]) v[idx++] = i;
        do{
            rep(i,0,4){
                rep(j,0,4) b[i][j] = a[i][j];
            }
            rep(i,0,9){
                b[pos[i].F][pos[i].S] = v[i];
            }
            bool check = true;
            int sum = 0;
            rep(i,0,4) sum += b[0][i];
            rep(i,0,4){
                int curr_sum = 0;
                rep(j,0,4){
                    //cout << b[i][j] << " ";
                    curr_sum += b[i][j];
                }
                if(curr_sum != sum) check = false;
            }
            rep(j,0,4){
                int curr_sum = 0;
                rep(i,0,4){
                    curr_sum += b[i][j];
                }
                if(curr_sum != sum) check = false;
            }
            if(check){
                rep(i,0,4){
                    rep(j,0,4){
                        ans[i][j] = b[i][j];
                    }
                }
                break;
            }
            
        }while(next_permutation(v, v + 9));
        cout << "Case " << T << ":\n";
        rep(i,0,4){
            rep(j,0,4) cout << ans[i][j] << (j == 3 ? "" : " ");
            cout <<  '\n';
        }
    }
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}