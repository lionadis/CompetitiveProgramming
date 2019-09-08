#include <bits/stdc++.h>
using namespace std;

int query(int index) {
    cout << "Q " << index << "\n";
    cout.flush();
    int value;
    cin >> value;
    return value;
}

int solve(int N) {
    int l = 1, r = N;
    int last = query(r);
    while(l < r){
        int mid = (l + r + 1) / 2;
        int midq = query(mid);
        if(midq > last) l = mid;
        else r = mid - 1;
    }
    return l - 1;
}
int main() {
    int N;
    cin >> N;
    cout << "A " << solve(N) << "\n";
    cout.flush();
    return 0;
}