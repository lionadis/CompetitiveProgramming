#include "../jngen.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int MAXN = 1000;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    parseArgs(argc, argv);
    int n;
    n = rand() % MAXN + 1;
    setMod().add1();
    cout << 1 << '\n';
    cout << n << " " << '\n';
    Tree t = Tree::random(n);
    t.setEdgeWeights(Array::random(n - 1,100000));
    cout << t << endl;
}
