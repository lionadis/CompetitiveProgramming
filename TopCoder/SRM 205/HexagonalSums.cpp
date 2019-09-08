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
class HexagonalSums {
public:
    int minLength(int N) {
        vi a;
        for(int i=0;i < 1000;++i){
            int x = 6 * i * (i + 1) / 2 + 1 - i * i;
            a.push_back(x);
        }
        vector<int> dp1(N + 1, 1000), dp2(N + 1, 1000);
        dp1[0] = 0;
        trav(x, a){
            if(x > N) break;
            dp1[x] = 1;
        }
        trav(x1, a){
            trav(x2, a){
                if(x1 + x2 > N) break;
                if(dp1[x1 + x2] == 1000) dp1[x1 + x2] = 2;
            }
        }
        rep(i,0,N + 1){
            dp1[N] = min(dp1[N], dp1[i] + dp1[N - i]);
        }
        dp2[0] = 0;
        rep(i,1,min(N + 1, 1720)){
            trav(x, a){
                if(x <= i){
                    dp2[i] = min(dp2[i], dp2[i - x] + 1);
                }
            }
        }
        if(N < 1720) return dp2[N];
        return dp1[N];
    }
};

// CUT begin
ifstream data("HexagonalSums.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int N, int __expected) {
    time_t startClock = clock();
    HexagonalSums *instance = new HexagonalSums();
    int __result = instance->minLength(N);
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
        int N;
        from_stream(N);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1528041774;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "HexagonalSums (600 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases);
}
// CUT end
