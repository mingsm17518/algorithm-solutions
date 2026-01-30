/**
 *      author:  mingsm
 *      created: 2025-09-03 08:28:54
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
    for(auto& x: a) cin >> x;
    sort(all(a));
    for(int i = 0; i < n - 1; i++){
        if(a[i] == a[i+1]){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}