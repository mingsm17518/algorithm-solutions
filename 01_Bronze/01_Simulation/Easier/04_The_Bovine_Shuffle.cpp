/**
 *      author:  mingsm
 *      created: 2025-10-18 15:59:46
 *      link: 
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
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for(int& x: a) cin >> x;
    vector<int> id(n);
    for(int& x:id) cin >> x;
    int change_num = 3;
    while(change_num--){
        vector<int> old(n);
        for(int i = 0; i < n; i++){
            old[i] = id[a[i] - 1];
        }
        id = old;
    }
    for(int x: id) cout << x << "\n";
    return 0;
}