/**
 *      author:  mingsm
 *      created: 2025-10-20 00:29:58
 *      link: https://usaco.org/index.php?page=viewproblem2&cpid=616
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
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for(int& x:a){
        cin >> x;
    }
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        int now_ans = 0;
        for(int j = 0; j < n; j++){
            now_ans += j * a[(i + j) % n];
        }
        ans = min(ans, now_ans);
    }
    cout << ans;
    return 0;
}