/**
 *      author:  mingsm
 *      created: 2025-10-20 15:46:07
 *      link: https://usaco.org/index.php?page=viewproblem2&cpid=831
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

vector<string> a(3);
set<set<char>> win[4];

void check(vector<pair<int, int>> pos){
    set<char> cur;
    for(pair<int, int> p: pos){
        cur.insert(a[p.first][p.second]);
    }
    win[cur.size()].insert(cur);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    for(string& s: a) cin >> s;
    for(int i = 0; i < 3; i++){
        check({{i, 0}, {i, 1}, {i, 2}});
    }
    for(int i = 0; i < 3; i++){
        check({{0, i}, {1, i}, {2, i}});
    }
    check({{0, 0}, {1, 1}, {2, 2}});
    check({{0, 2}, {1, 1}, {2, 0}});
    cout<< win[1].size() << "\n" << win[2].size();
    return 0;
}