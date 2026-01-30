/**
 *      author:  mingsm
 *      created: 2025-08-16 01:07:34
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
    int64_t a, b, k;
    cin >> a >> b >> k;
    auto g = gcd(a, b);
    a /= g;
    b /= g;
    cout << (a <= k && b <= k ? 1 : 2) << '\n';
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}