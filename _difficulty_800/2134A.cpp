/**
 *      author:  mingsm
 *      created: 2025-09-02 11:45:59
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
    int n, a, b;
    cin >> n >> a >> b;
    if((n - b) % 2 ==0 && ((a < b) || (n - a) % 2 == 0)){
        cout << "Yes\n";
    } else{
        cout << "NO\n";
    }
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}