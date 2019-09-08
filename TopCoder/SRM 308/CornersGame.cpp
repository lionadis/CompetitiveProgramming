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
#define debug(x) cerr << #x << " : " << x << "n";
#define _ cin.sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

class CornersGame {
public:
    int cost(vector<string> &board, pii src, pii dst){
        map<pii, bool> vis;
        int ans = 1e9 + 123;
        queue<pair<pii, int> > Q;
        Q.push({src, 0});
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
        while(!Q.empty()){
            pair<pii, int> top = Q.front() ;
            Q.pop();
            if(vis[top.F]) continue;
            if(top.F == dst) ans = min(ans, top.S);
            vis[top.F] = true;
            rep(i,0,4){
                int x = top.F.F + dx[i], y = top.F.S + dy[i];
                if(x < 0 || x > 5 || y < 0 || y > 5) continue;
                if(board[x][y] == '.') Q.push({{x, y}, top.S + 1});
                else if(board[x][y] != 'r'){
                    x += dx[i], y += dy[i];
                    if(board[x][y] == '.') Q.push({{x, y}, top.S + 1});
                }
            }
        }
        return (ans > 1e9 ? -1 : ans);

    }


    struct HASH{
        int encode(const pii &x)const{
            return x.F + x.S * 6;
        }
        size_t operator()(const vector<pii> &a)const{
            return encode(a[0])  + encode(a[1]) * 36 + encode(a[2]) * 36 * 36 + encode(a[3]) * 36 * 36 * 36;
        }
    };

    struct EQ{
        bool operator()(const vector<pii> &x, const vector<pii> &y)const{
            return x == y;
        }
    };
    int countMoves(vector<string> board) {
        vector<pii> piece = {{4, 4}, {4, 5}, {5, 4}, {5, 5}};
        vector<pii> goal = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        int ans = -1;
        queue<pair<vector<pii>, int> > Q;
        //unordered_map<vector<pii>, bool, HASH, EQ> vis;
        map<vector<pii>, bool> vis;
        Q.push({piece, 0});
        while(!Q.empty()){
            pair<vector<pii>, int> top = Q.front();
            Q.pop();
            sort(all(top.F));
            if(vis[top.F]) continue;
            //cout << sz(Q) << '\n';
            if(top.F == goal){
                ans = top.S;
                break;
            }
            vis[top.F] = true;
            int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
            rep(p,0,4){
                rep(i,0,4){
                    int x = top.F[p].F + dx[i], y = top.F[p].S + dy[i];
                    if(x < 0 || x > 5 || y < 0 || y > 5) continue;
                    bool overlap = false;
                    rep(j,0,4){
                        if(top.F[j] == make_pair(x, y)) overlap = true;
                    }
                    if(board[x][y] == '.' && !overlap){
                        vector<pii> curr = top.F;
                        curr[p].F = x, curr[p].S = y;
                        sort(all(curr));
                        if(!vis[curr]) Q.push({curr, top.S + 1});
                    } else {
                        if(board[x][y] != 'r'){
                            x += dx[i], y += dy[i];
                            if(x < 0 || x > 5 || y < 0 || y > 5) continue;
                            overlap = false;
                            rep(j,0,4){
                                if(top.F[j] == make_pair(x, y)) overlap = true;
                            }
                            if(board[x][y] == '.' && !overlap){
                                vector<pii> curr = top.F;
                                curr[p].F = x, curr[p].S = y;
                                sort(all(curr));
                                if(!vis[curr]) Q.push({curr, top.S + 1});
                            }
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};

// CUT begin
ifstream data("CornersGame.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<string> board, int __expected) {
    time_t startClock = clock();
    CornersGame *instance = new CornersGame();
    int __result = instance->countMoves(board);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<string> board;
        from_stream(board);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(board, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1525887795;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "CornersGame (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases);
}
// CUT end
