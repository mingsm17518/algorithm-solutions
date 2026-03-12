/**
 *      author:  mingsm
 *      created: 2025-10-20 19:48:17
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
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int& x:a) cin >> x;
    int ans = 0;
    for(int x: a){
        int now = 0;
        for(int y:a){
            if(y >= x && y - x <= k) now++;
        }
        ans = max(ans, now);
    }
    cout << ans;
    return 0;
}