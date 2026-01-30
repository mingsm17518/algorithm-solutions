/**
 *      author:  mingsm
 *      created: 2025-09-03 10:11:07
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
    vec a(n);
    vec b(n);
    for(int& x: a) cin >> x;
    for(int& x: b) cin >> x;
    
    int ans = 1;
    for(int i = 0; i < n; i++){
        ans += max(0, a[i] - b[i]);
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