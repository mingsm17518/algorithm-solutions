/**
 *      author:  mingsm
 *      created: 2025-09-01 09:49:31
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
    ll n;
    cin >> n;
    vec p(n);
    for(auto& x: p) cin >> x;
    ll sum = (n * (n + 1) * (n + 2))/6;
    for(int i = 0; i < n - 1; i++){
        if (p[i] < p[i+1]){
            sum -= (i + 1) * (n - i - 1);
        }
    }
    cout << sum << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}