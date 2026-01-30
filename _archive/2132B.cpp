/**
 *      author:  mingsm
 *      created: 2025-09-03 09:05:49
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
    ll n; cin >> n;
    vector<ll>ans;
    for(ll i = 10; i + 1 <= n; i *= 10){
        if(n % (i + 1) == 0){
            ans.push_back(n / (i + 1));
        }
    }
    reverse(all(ans));
    cout << ans.size() << "\n";
    for (auto x: ans) cout << x << " \n"[x == ans.back()];
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}