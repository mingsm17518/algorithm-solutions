/**
 *      author:  mingsm
 *      created: 2025-09-10 10:43:22
 *      link: https://cses.fi/problemset/task/1661
 *      Question: Outputs the number of subarrays with sum x
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
    int n, target; cin >> n >> target;
    int64_t ans = 0;
    map<int64_t, int> sums;
    sums[0] = 1;
    int64_t prefix_sum = 0;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        prefix_sum += x;
        ans += sums[prefix_sum - target];
        sums[prefix_sum] ++;
    }

    cout << ans << "\n";
    return 0;
}