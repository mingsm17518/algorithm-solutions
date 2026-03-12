/**
 *      author:  mingsm
 *      created: 2025-10-20 18:20:56
 *      link: https://usaco.org/index.php?page=viewproblem2&cpid=615
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
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, m;
    cin >> x >> y >> m;
    int ans = 0;
    for(int i = 0; i <= m / x; i++){
        for(int j = 0; j <= m / y; j++){
            int now = i * x + j * y;
            if(now <= m){
                ans = max(now, ans);
            }
        }
    }
    cout << ans;
    return 0;
}