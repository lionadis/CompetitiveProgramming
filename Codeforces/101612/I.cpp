#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int max_n = 2020202;
int tree[5 * max_n + 5050], lazy[5 * max_n + 5050];

void update_range(int node, int st, int nd, int l, int r){
    if(lazy[node] == 1){
        tree[node] += (nd - st);
        if(st != nd){
            lazy[2 * node] = 1;
            lazy[2 * node + 1] = 1;
        }
    }
    if(st > nd || st > r || nd < l)return;
    if(st >= l && nd <= r){
        tree[node] = (nd - st);
        if(st != nd){
            lazy[2 * node] = 1;
            lazy[2 * node + 1] = 1;
        }
        return;
    }
    int mid = (st + nd) / 2;
    update_range(2 * node, st, mid, l, r);
    update_range(2 * node + 1, mid + 1, nd, l, r);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int sum_range(int node, int st, int nd, int l, int r){
    if(st > nd || st > r || nd < l)return 0;
    if(lazy[node] == 1){
        tree[node] += (nd - st);
        if(st != nd){
            lazy[2 * node] = 1;
            lazy[2 * node + 1] = 1;
        }
    }
    if(st >= l && nd <= r)return tree[node];
    int mid = (st + nd) / 2;
    int q1 = sum_range(2 * node, st, mid, l, r);
    int q2 = sum_range(2 * node + 1, mid + 1, nd, l, r);
    return q1 + q2;
}
int n, x[1010], y[1010];
vector<pair<int, pair<int, int> > > vertical, horizontal;

int main(){
    freopen("test.in", "r+", stdin);
    cin >> n;
    long long int total_perim = 0, visible = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        x[i] += 1000001;
        y[i] += 1000001;
        if(i > 0){
            total_perim += abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
            if(x[i] == x[i - 1])
                horizontal.push_back(make_pair(x[i], make_pair(min(y[i], y[i - 1]), max(y[i], y[i - 1]))));
            if(y[i] == y[i - 1])
                vertical.push_back(make_pair(y[i], make_pair(min(x[i], x[i - 1]), max(x[i], x[i - 1]))));
        }
    }
    total_perim += abs(x[0] - x[n - 1]) + abs(y[0] - y[n - 1]);
    if(x[0] == x[n - 1])horizontal.push_back(make_pair(x[0], make_pair(min(y[0], y[n - 1]), max(y[0], y[n - 1]))));
    if(y[0] == y[n - 1])vertical.push_back(make_pair(y[0], make_pair(min(x[0], x[n - 1]), max(x[0], x[n - 1]))));

    memset(tree, 0, sizeof tree);
    memset(lazy, 0, sizeof lazy);
    sort(vertical.begin(), vertical.end());
    for(int i = 0; i < vertical.size(); i++){
        int x1 = vertical[i].second.first;
        int x2 = vertical[i].second.second;
        visible += x2 - x1 - sum_range(1, 0, max_n - 1, x1, x2 - 1);
        cout << sum_range(1, 0, max_n - 1, x1, x2 - 1) << '\n';
        update_range(1, 0, max_n - 1, x1, x2 - 1);
    }
    cout << "ok" << '\n';
    memset(tree, 0, sizeof tree);
    memset(lazy, 0, sizeof lazy);
    for(int i = vertical.size() - 1; i >= 0; i--){
        int x1 = vertical[i].second.first;
        int x2 = vertical[i].second.second;
        visible += x2 - x1 - sum_range(1, 0, max_n - 1, x1, x2 - 1);
        cout << visible << '\n';
        update_range(1, 0, max_n - 1, x1, x2 - 1);
    }

    memset(tree, 0, sizeof tree);
    memset(lazy, 0, sizeof lazy);
    sort(horizontal.begin(), horizontal.end());
    for(int i = 0; i < horizontal.size(); i++){
        int x1 = horizontal[i].second.first;
        int x2 = horizontal[i].second.second;
        visible += x2 - x1 - sum_range(1, 0, max_n - 1, x1, x2 - 1);
        cout << visible << '\n';
        update_range(1, 0, max_n - 1, x1, x2 - 1);
    }

    memset(tree, 0, sizeof tree);
    memset(lazy, 0, sizeof lazy);
    for(int i = horizontal.size() - 1; i >= 0; i--){
        int x1 = horizontal[i].second.first;
        int x2 = horizontal[i].second.second;
        visible += x2 - x1 - sum_range(1, 0, max_n - 1, x1, x2 - 1);
        cout << visible << '\n';
        update_range(1, 0, max_n - 1, x1, x2 - 1);
    }
    cout << total_perim - visible << '\n';
}
