/**
 *      author:  mingsm
 *      created: 2025-09-10 10:11:24
 *      link: https://usaco.org/index.php?page=viewproblem2&cpid=691
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
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n+1);
    vector<int> b(n+1);
    vector<int> c(n+1);
    int max_wins = 0;
    for (int i = 0; i < n; i++){
        a[i+1] = a[i];
        b[i+1] = b[i];
        c[i+1] = c[i];
        char x;
        cin >> x;
        if (x == 'H') a[i+1]++;
        if (x == 'S') b[i+1]++;
        if (x == 'P') c[i+1]++;
    }
    for (int i = 1; i <= n; i++){
        int before_wins = max(a[i], max(b[i], c[i]));
        int after_wins = max(a[n] - a[i], max(b[n]- b[i], c[n] - c[i]));
        max_wins = max(max_wins, before_wins + after_wins);
    }
    cout << max_wins << "\n";
    return 0;
}