/*
    Constraints too low, straight full space search
*/

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

int dx[] = {1, -1, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0};

int h, w, n;
string s[20];
bool vis[20000123];

bool check(int x, int y){
    return x >= 0 && x < h && y >= 0 && y < w && s[x][y] != '#';
}

struct G1{
    int encode(int x, int y){
        return x * w + y;
    }
    pii decode(int x){
        return {x / w, x % w};
    }
    int solve(){
        int start = -1, end = -1;
        rep(i,0,h){
            rep(j,0,w){
                if(isalpha(s[i][j])){
                    if(tolower(s[i][j]) == s[i][j]) start = encode(i, j), s[i][j] = ' ';
                    else end = encode(i, j), s[i][j] = ' ';
                }
            }
        }
        queue<pii> Q;
        Q.push({start, 0});
        while(!Q.empty()){
            int state = Q.front().F, cost = Q.front().S;
            Q.pop();
            if(state == end) return cost;
            if(vis[state]) continue;
            vis[state] = 1;
            int x, y;
            tie(x, y) = decode(state);
            rep(i,0,4){
                int xx = x + dx[i], yy = y + dy[i];
                if(check(xx, yy)){
                    Q.push({encode(xx, yy), cost + 1});
                }
            }
        }
        return -1;
    }
};

struct G2{

    int encode(int x, int y){
        return x * w + y;
    }

    pii decode(int x){
        return {x / w, x % w};
    }

    int enc(int x1, int x2){
        return x1 * h * w + x2;
    }

    pii dec(int x){
        return {x / (h * w), x % (w * h)};
    }

    int solve(){
        int start = -1, end = -1, start_g1 = -1, start_g2 = -1, end_g1 = -1, end_g2 = -1;
        char g1 = ' ', g2 = ' ';
        rep(i,0,h){
            rep(j,0,w){
                if(isalpha(s[i][j]) && tolower(s[i][j]) == s[i][j]){
                    if(g1 == ' ') g1 = s[i][j], start_g1 = encode(i, j), s[i][j] = ' ';
                    else{
                        g2 = s[i][j];
                        s[i][j] = ' ';
                        start_g2 = encode(i, j);
                        break;
                    }
                }
            }
        }
        rep(i,0,h){
            rep(j,0,w){
                if(s[i][j] == toupper(g1)) end_g1 = encode(i, j), s[i][j] = ' ';
                if(s[i][j] == toupper(g2)) end_g2 = encode(i, j), s[i][j] = ' ';
            }
        }
        start = enc(start_g1, start_g2);
        end = enc(end_g1, end_g2);
        queue<pii> Q;
        Q.push({start, 0});
        while(!Q.empty()){
            int state = Q.front().F, cost = Q.front().S;
            Q.pop();
            if(state == end) return cost;
            if(vis[state]) continue;
            vis[state] = 1;
            int g1, g2;
            tie(g1, g2) = dec(state);
            int x1, x2, y1, y2;
            tie(x1, y1) = decode(g1), tie(x2, y2) = decode(g2);
            // A -> B
            rep(i,0,5){
                int xx1 = x1 + dx[i], yy1 = y1 + dy[i];
                if(check(xx1, yy1) && encode(xx1, yy1) != g2){
                    rep(j,0,5){
                        int xx2 = x2 + dx[j], yy2 = y2 + dy[j];
                        if(check(xx2, yy2) && encode(xx1, yy1) != encode(xx2, yy2) ){
                            Q.push({enc(encode(xx1, yy1), encode(xx2, yy2)), cost + 1});
                        }
                    }
                }
            }
            // B -> A
            rep(i,0,5){
                int xx2 = x2 + dx[i], yy2 = y2 + dy[i];
                if(check(xx2, yy2) && encode(xx2, yy2) != g1){
                    rep(j,0,5){
                        int xx1 = x1 + dx[j], yy1 = y1 + dy[j];
                        if(check(xx1, yy1) && encode(xx1, yy1) != encode(xx2, yy2) ){
                            Q.push({enc(encode(xx1, yy1), encode(xx2, yy2)), cost + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};

struct G3{

    int encode(int x, int y){
        return x * w + y;
    }

    pii decode(int x){
        return {x / w, x % w};
    }

    int enc(int x, int y, int z){
        return x * (h * h * w * w) + y * (h * w) + z; 
    }

    tuple<int, int, int> dec(int x){
        int x1, x2, x3;
        x1 = x / (h * h * w * w);
        x %= (h * h * w * w);
        x2 = x / (h * w);
        x3 = x % (h * w);
        return {x1, x2, x3};
    }

    int solve(){
        int start = -1, end = -1, start_g1 = -1, start_g2 = -1, start_g3 = -1, end_g1 = -1, end_g2 = -1, end_g3 = -1;
        char g1 = ' ', g2 = ' ', g3 = ' ';
        rep(i,0,h){
            rep(j,0,w){
                if(isalpha(s[i][j]) && tolower(s[i][j]) == s[i][j]){
                    if(start_g2 != -1){
                        start_g3 = encode(i, j);
                        g3 = s[i][j];
                        s[i][j] = ' ';
                        break;
                    }
                    else if( start_g1 != -1){
                        start_g2 = encode(i ,j);
                        g2 = s[i][j];
                        s[i][j] = ' ';
                    } else {
                        start_g1 = encode(i, j);
                        g1 = s[i][j];
                        s[i][j] = ' ';
                    }
                }
            }
        }
        rep(i,0,h){
            rep(j,0,w){
                if(toupper(g1) == s[i][j]) end_g1 = encode(i, j), s[i][j] = ' ';
                if(toupper(g2) == s[i][j]) end_g2 = encode(i, j), s[i][j] = ' ';
                if(toupper(g3) == s[i][j]) end_g3 = encode(i, j), s[i][j] = ' ';
            }
        }
        start = enc(start_g1, start_g2, start_g3);
        end = enc(end_g1, end_g2, end_g3);
        queue<pii> Q;
        Q.push({start, 0});
        while(!Q.empty()){
            int state = Q.front().F, cost = Q.front().S;
            if(state == end) return cost;
            Q.pop();
            if(vis[state]) continue;
            vis[state] = 1;
            int g1, g2, g3;
            tie(g1, g2, g3) = dec(state);
            int x1, y1, x2, y2, x3, y3;
            tie(x1, y1) = decode(g1);
            tie(x2, y2) = decode(g2);
            tie(x3, y3) = decode(g3);
            // cout << "c :" << x1 << "," << y1 << '\n';
            // cout << "b :" << x2 << "," << y2 << '\n';
            // cout << "a :" << x3 << "," << y3 << '\n';
            // cout << state << '\n';
            // A -> B -> C
            rep(i,0,5){
                int xx1 = x1 + dx[i], yy1 = y1 + dy[i];
                if(check(xx1, yy1)){
                    rep(j,0,5){
                        int xx2 = x2 + dx[j], yy2 = y2 + dy[j];
                        if(check(xx2, yy2)){
                            rep(k,0,5){
                                int xx3 = x3 + dx[k], yy3 = y3 + dy[k];
                                if(check(xx3, yy3)){ 
                                    if( encode(xx1, yy1) == encode(xx2, yy2) || (encode(xx1, yy1) == g2 && encode(xx2, yy2) == g1)) continue;
                                    if( encode(xx3, yy3) == encode(xx2, yy2) || (encode(xx3, yy3) == g2 && encode(xx2, yy2) == g3)) continue; 
                                    if( encode(xx1, yy1) == encode(xx3, yy3) || (encode(xx1, yy1) == g3 && encode(xx3, yy3) == g1)) continue; 
                                    Q.push({enc(encode(xx1, yy1), encode(xx2, yy2), encode(xx3, yy3)), cost + 1});
                                }
                            }
                        }
                    }
                }
            }
            /*
            // A -> C -> B
            rep(i,0,5){
                int xx1 = x1 + dx[i], yy1 = y1 + dy[i];
                if(check(xx1, yy1) && encode(xx1, yy1) != g2 && encode(xx1, yy1) != g3){
                    rep(j,0,5){
                        int xx3 = x3 + dx[j], yy3 = y3 + dy[j];
                        if(check(xx3, yy3) && encode(xx3, yy3) != encode(xx1, yy1) && encode(xx3, yy3) != g2){
                            rep(k,0,5){
                                int xx2 = x2 + dx[k], yy2 = y2 + dy[k];
                                if(check(xx2, yy2) && encode(xx2, yy2) != encode(xx1, yy1) && encode(xx3, yy3) != encode(xx2, yy2)){
                                    Q.push({enc(encode(xx1, yy1), encode(xx2, yy2), encode(xx3, yy3)), cost + 1});
                                }
                            }
                        }
                    }
                }
            }
            
            // B -> A -> C
            rep(i,0,5){
                int xx2 = x2 + dx[i], yy2 = y2 + dy[i];
                if(check(xx2, yy2) && encode(xx2, yy2) != g1 && encode(xx2, yy2) != g3){
                    rep(j,0,5){
                        int xx1 = x1 + dx[j], yy1 = y1 + dy[j];
                        if(check(xx1, yy1) && encode(xx2, yy2) != encode(xx1, yy1) && encode(xx1, yy1) != g3){
                            rep(k,0,5){
                                int xx3 = x3 + dx[k], yy3 = y3 + dy[k];
                                if(check(xx3, yy3) && encode(xx3, yy3) != encode(xx1, yy1) && encode(xx3, yy3) != encode(xx2, yy2)){
                                    Q.push({enc(encode(xx1, yy1), encode(xx2, yy2), encode(xx3, yy3)), cost + 1});
                                }
                            }
                        }
                    }
                }
            }
            
            // B -> C -> A
            rep(i,0,5){
                int xx2 = x2 + dx[i], yy2 = y2 + dy[i];
                if(check(xx2, yy2) && encode(xx2, yy2) != g1 && encode(xx2, yy2) != g3){
                    rep(j,0,5){
                        int xx3 = x3 + dx[j], yy3 = y3 + dy[j];
                        if(check(xx3, yy3) && encode(xx3, yy3) != encode(xx2, yy2) && encode(xx3, yy3) != g1){
                            rep(k,0,5){
                                int xx1 = x1 + dx[k], yy1 = y1 + dy[k];
                                if(check(xx1, yy1) && encode(xx2, yy2) != encode(xx1, yy1) && encode(xx3, yy3) != encode(xx1, yy1)){
                                    Q.push({enc(encode(xx1, yy1), encode(xx2, yy2), encode(xx3, yy3)), cost + 1});
                                }
                            }
                        }
                    }
                }
            }
            
            // C -> A -> B
            rep(i,0,5){
                int xx3 = x3 + dx[i], yy3 = y3 + dy[i];
                if(check(xx3, yy3) && encode(xx3, yy3) != g1 && encode(xx3, yy3) != g2){
                    rep(j,0,5){
                        int xx1 = x1 + dx[j], yy1 = y1 + dy[j];
                        if(check(xx1, yy1) && encode(xx3, yy3) != encode(xx1, yy1) && encode(xx1, yy1) != g2){
                            rep(k,0,5){
                                int xx2 = x2 + dx[k], yy2 = y2 + dy[k];
                                if(check(xx2, yy2) && encode(xx2, yy2) != encode(xx1, yy1) && encode(xx3, yy3) != encode(xx2, yy2)){
                                    Q.push({enc(encode(xx1, yy1), encode(xx2, yy2), encode(xx3, yy3)), cost + 1});
                                }
                            }
                        }
                    }
                }
            }
            
            // C -> B -> A
            rep(i,0,5){
                int xx3 = x3 + dx[i], yy3 = y3 + dy[i];
                if(check(xx3, yy3) && encode(xx3, yy3) != g2 && encode(xx3, yy3) != g1){
                    rep(j,0,5){
                        int xx2 = x2 + dx[j], yy2 = y2 + dy[j];
                        if(check(xx2, yy2) && encode(xx2, yy2) != encode(xx3, yy3) && encode(xx2, yy2) != g1){
                            rep(k,0,5){
                                int xx1 = x1 + dx[k], yy1 = y1 + dy[k];
                                if(check(xx1, yy1) && encode(xx3, yy3) != encode(xx1, yy1) && encode(xx1, yy1) != encode(xx2, yy2)){
                                    Q.push({enc(encode(xx1, yy1), encode(xx2, yy2), encode(xx3, yy3)), cost + 1});
                                }
                            }
                        }
                    }
                }
            }
            */
        }
        return -1;
    }
};

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    while(cin >> w >> h >> n, w){
        cin.ignore();
        memset(vis, 0, sizeof vis);
        rep(i,0,h) getline(cin, s[i]);
        if(n == 1) cout << G1().solve() << '\n';
        if(n == 2) cout << G2().solve() << '\n';
        if(n == 3) cout << G3().solve() << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}