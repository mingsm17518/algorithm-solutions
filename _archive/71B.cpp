/**
 *      author:  mingsm
 *      created: 2025-08-15 23:36:33
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vec = vector<int>;

inline void speedup() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

void solve(){
    int n, k, t;
    cin >> n >> k >> t;
    int total = n * k * t / 100;
    for (int i = 0; i < n; i++) {
        int v = min(total, k);
        cout << v << " \n"[i == n-1];
        total -= v;
    }
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}