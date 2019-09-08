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
class PowerPlants {
public:
    const static int N = 17;
    int a[N][N], dp[1 << N][N], n, cnt;

    int solve(int x, int curr_cnt){
        if(curr_cnt >= cnt) return 0;
        int &ans = dp[x][curr_cnt];
        if(~ans) return ans;
        ans = 1e9;
        rep(k,0,n){
            if((x & (1 << k)) == 0){
                int cost = 1e9;
                rep(i,0,n){
                    if((x & (1 << i)) != 0) cost = min(cost, a[i][k]);
                }
                ans = min(ans, cost + solve(x | (1 << k), curr_cnt + 1));
            }
        }
        return ans;
    }

    int minCost(vector<string> connectionCost, string plantList, int numPlants) {
        memset(a, 0, sizeof a);
        memset(dp, -1, sizeof dp);
        n = sz(connectionCost);
        cnt = numPlants;
        rep(i,0,n){
            rep(j,0,n){
                if(connectionCost[i][j] >= 'A' ) a[i][j] = connectionCost[i][j] - 'A' + 10;
                    else a[i][j] = connectionCost[i][j] - '0';
            }
        }
        int start = 0;
        rep(i,0,n){
            if(plantList[i] == 'Y') start |= 1 << i;
        }
        return solve(start, __builtin_popcount(start));
    }
};

// CUT begin
ifstream data("PowerPlants.sample");

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

bool do_test(vector<string> connectionCost, string plantList, int numPlants, int __expected) {
    time_t startClock = clock();
    PowerPlants *instance = new PowerPlants();
    int __result = instance->minCost(connectionCost, plantList, numPlants);
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
        vector<string> connectionCost;
        from_stream(connectionCost);
        string plantList;
        from_stream(plantList);
        int numPlants;
        from_stream(numPlants);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(connectionCost, plantList, numPlants, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1527693399;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "PowerPlants (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases);
}
// CUT end
