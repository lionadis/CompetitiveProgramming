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


const int N = 10123;
bool vis[N];


struct point{
    ll x, y;
    point(){};
    point(ll x, ll y):x(x), y(y){};
};

struct segment{
    point start, end;
    segment(){};
    segment(point a, point b):start(a), end(b){};
}seg[N];

point operator-(const point &p1, const point &p2){
    return point{p1.x - p2.x, p1.y - p2.y};
}

ll cross(const segment &a, const segment &b){
    point u = a.end - a.start, v = b.end - b.start;
    return u.x * v.y - u.y * v.x;
}

ll dot(const segment &a, const segment &b){
    point u = a.end - a.start, v = b.end - b.start;
    return u.x * v.x + u.y * v.y;
}

ll len(const point &v){
    return v.x * v.x + v.y * v.y;
}

bool contained(const segment &s, const point & x){
    segment u(s.start, x);
    if(cross(u, s) == 0 && dot(u, s) >= 0 && dot(u, s) <= len(s.end - s.start)) return true;
    return false;
}


struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
	}
};


int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n;
    while(cin >> n, n){
        rep(i,0,n){
            double x, y;
            cin >> x >>  y;
            x *= 100, x += 0.1;
            y *= 100, y += 0.1;
            point a(floor(x), floor(y));
            cin >> x >>  y;
            x *= 100, x += 0.1;
            y *= 100, y += 0.1;
            point b(floor(x), floor(y));
            if(a.x > b.x) swap(a, b);
            seg[i] = {a, b};   
        }
        sort(seg, seg + n, [&](const segment &u, const segment& v){
                        ll angle = cross(u, v);
                        if(angle) return angle > 0;
                        else {
                            point v1 = u.end - u.start, v2  = v.end - v.start;
                            return len(v1) > len(v2);
                        }                    
        });
        //rep(i,0,n) cout << seg[i].start.x << "," << seg[i].start.y << " " << seg[i].end.x << "," << seg[i].end.y << '\n';
        memset(vis, 0, sizeof vis);
        UF uf(n);
        rep(i,0,n){
            rep(j,i+1,n){
                if(cross(seg[i], seg[j]) == 0 && (contained(seg[i], seg[j].start) || contained(seg[i], seg[j].end))) uf.join(i, j);
            }
        }
        set<int> ans;
        rep(i,0,n) ans.insert(uf.find(i));
        cout << sz(ans) << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}