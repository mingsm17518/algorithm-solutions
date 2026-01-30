/**
 *      author:  mingsm
 *      created: 2025-09-18 10:54:03
 *      link: https://usaco.org/index.php?page=viewproblem2&cpid=715
 *      Solution: https://usaco.guide/problems/usaco-715-why-did-the-cow-cross-the-road-ii/solution
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
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
    int n, k, b;
    cin >> n >> k >> b;

    vector<int> isBroken(n+1);
    for(int i = 0; i < b; i++){
        int x; cin >> x;
        // broken
        isBroken[x] = 1;
    }

    int ans = n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        a[i] = a[i-1] + isBroken[i];
    }

    for(int i = 0; i <= n - k; i++){
        ans = min(ans, a[i+k] - a[i]);
    }
    cout << ans << "\n";
    
    return 0;
}