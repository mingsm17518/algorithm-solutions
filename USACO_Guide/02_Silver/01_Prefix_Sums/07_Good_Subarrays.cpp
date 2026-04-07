/**
 *      author:  mingsm
 *      created: 2025-09-18 15:30:00
 *      link: https://codeforces.com/contest/1398/problem/C
 *      Solution: https://usaco.guide/problems/cf-good-subarrays/solution#implementation
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
        vector<int> prefix_sum(n+1);
        for(int i = 1; i <= n; i++){
            char c; cin >> c;
            prefix_sum[i] = prefix_sum[i-1] + (c - '0');
        }
        
        map<int, int> sum_minus_i;
        int64_t ans = 0;
        for(int i = 0; i <= n; i++){
            ans += sum_minus_i[prefix_sum[i] - i]++;
        }
        // for(auto [_, x] : sum_minus_i){
        //     ans += x *  (x - 1) / 2;
        // }

        cout << ans << "\n";
    }
    return 0;
}