/**
 *      author:  mingsm
 *      created: 2025-09-25 08:12:40
 *      link: https://atcoder.jp/contests/abc125/tasks/abc125_c
 *      Solution: https://usaco.guide/problems/ac-gcd-on-blackboard/solution
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
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> prefGcd(n+1);
    vector<int> suffGcd(n+1);

    for(int& x: arr) cin >> x;

    prefGcd[0] = 0;
    suffGcd[n+1] = 0;
    for(int i = 1; i <= n; i++) prefGcd[i] = gcd(prefGcd[i-1], arr[i-1]);
    for(int i = n; i >= 1; i--) suffGcd[i] = gcd(suffGcd[i+1], arr[i-1]);

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, gcd(prefGcd[i-1], suffGcd[i+1]));
    }
    cout << ans << "\n";
    return 0;
}