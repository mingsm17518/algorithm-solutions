/**
 *      author:  mingsm
 *      created: 2025-10-20 17:14:52
 *      link: https://usaco.org/index.php?page=viewproblem2&cpid=593
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
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int n; cin >> n;
    vector<vector<int>> a(3e3, vector<int>(3e3, -1));
    int time = 0;
    int x = 2e3, y = 2e3;
    int ans = -1;
    while(n--){
        char c;
        int move;
        cin >> c >> move;
        for(int i = 0; i < move; i++){
            if(a[x][y] != -1){
                int diff = time - a[x][y];
                if(ans == -1 || diff < ans){
                    ans = diff;
                }
            }
            a[x][y] = time++;
            if(c == 'N') y++;
            if(c == 'S') y--;
            if(c == 'W') x--;
            if(c == 'E') x++;
        }
    }
    cout << ans;
    return 0;
}