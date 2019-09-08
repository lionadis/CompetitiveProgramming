#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

const int maxn = 212;
map<string, int> m;
int cnt[maxn][752], id;
string s[maxn];

double f(int x, int y){
	double scalar = 0, norm_x = 0, norm_y = 0;
	rep(i,0,id) scalar += cnt[x][i] * cnt[y][i], norm_x += cnt[x][i] * cnt[x][i], norm_y += cnt[y][i] * cnt[y][i];
	norm_x = sqrt(norm_x), norm_y = sqrt(norm_y);
	return acos(scalar / (norm_x * norm_y));
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    freopen("cheater.in","r",stdin);
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n;
	cin >> n;
	rep(i,0,n){
		cin >> s[i];
		int l;
		cin >> l;
		cin.ignore();
		while(l--){
			string s;
			getline(cin, s);
			stringstream ss(s);
			while(ss >> s){
				if(!m.count(s)) m[s] = id++;
				cnt[i][m[s]]++;
			}
		}
	}
	set<int> cheater;
	rep(i,0,n){
		rep(j,i + 1,n){
			double D = f(i, j);
			if(D <= 0.8 || D >= 2.6) cheater.insert(i), cheater.insert(j);
		}
	}
	for(auto x : cheater) cout << s[x] << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
