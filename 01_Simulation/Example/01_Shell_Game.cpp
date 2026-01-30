/**
 *      author:  mingsm
 *      created: 2025-10-17 21:09:44
 *      link: https://usaco.org/index.php?page=viewproblem2&cpid=891
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
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n; cin >> n;
    vector<int> arr(3);
    for(int i = 0; i < 3; i++){
        arr[i] = i;
    }
    vector<int> p;
    while(n--){
        int a, b, g;
        cin >> a >> b >> g;
        a--; b--; g--;
        swap(arr[a], arr[b]);
        p[arr[g]]++;
    }
    int ans = max(p[0], max(p[1], p[2]));
    cout << ans;
    return 0;
}