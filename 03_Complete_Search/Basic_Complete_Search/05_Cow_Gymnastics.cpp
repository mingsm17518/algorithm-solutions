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
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int k, n;
    cin >> k >> n;
    vector<vector<bool>>a(n, vector<bool>(n));
    for(int tt = 0; tt < k; tt++){
        vector<int> b(n);
        for(int& x:b){
            cin >> x;
            x--;
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                a[b[i]][b[j]] = true;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ans += a[i][j] ^ a[j][i];
        }
    }
    cout << ans;
    return 0;
}