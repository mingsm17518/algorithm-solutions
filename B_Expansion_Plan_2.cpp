#include <bits/stdc++.h>
// https://codeforces.com/contest/2157/problem/B
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n, x, y;
    std::cin >> n >> x >> y;
    x = std::abs(x), y = std::abs(y);
    std::string s;
    std::cin >> s;
    if (x > n || y > n) {
        std::cout << "NO\n";
    } else {
        int cnt = std::count(s.begin(), s.end(), '4');
        if (x + y > 2 * n - cnt) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    //freopen("filename.in", "r", stdin);
    //freopen("filename.out", "w", stdout);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}