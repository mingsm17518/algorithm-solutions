/**
 *      author:  mingsm
 *      created: 2025-09-25 08:31:57
 *      link: https://codeforces.com/contest/1826/problem/D
 *      Solution: https://usaco.guide/problems/cf-running-miles/solution
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
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        vector<int> beauty(n);
        for(int& x: beauty) cin >> x;
        vector<int> pref_max(n);
        vector<int> suff_max(n);
        for(int i = 0; i < n; i++){
            pref_max[i] = beauty[i] + i;
            suff_max[i] = beauty[i] - i;
        }

        for(int i = 1; i < n; i++){
            pref_max[i] = max(pref_max[i], pref_max[i-1]);
        }
        for(int i = n-2; i >= 0; i--){
            suff_max[i] = max(suff_max[i], suff_max[i+1]);
        }

        int ans = 0;
        for(int i = 1; i < n-1; i++){
            ans = max(ans, pref_max[i-1] + beauty[i] + suff_max[i+1]);
        }
        cout << ans << "\n";
    }
    return 0;
}