/**
 *      author:  mingsm
 *      created: 2025-10-17 21:36:35
 *      link: https://usaco.org/index.php?page=viewproblem2&cpid=665
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int m, n, k;
    cin >> m >> n >> k;
    vector<string> str(m);
    for(string& s:str){
        cin >> s;
    }
    for(int i = 0; i < m*k; i++){
        for(int j = 0; j < n*k; j++){
            cout << str[i/k][j/k];
        }
        cout << "\n";
    }
    return 0;
}