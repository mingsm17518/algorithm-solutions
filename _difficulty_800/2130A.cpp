/**
 *      author:  mingsm
 *      created: 2025-09-03 10:56:00
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
    int n; cin >> n;
    vec s(n);
    int ans = 0;
    for(int& x: s){
        cin >> x;
        ans += max(1, x);
    }
    cout << ans << "\n";

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}