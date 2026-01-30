/**
 *      author:  mingsm
 *      created: 2025-08-16 01:13:12
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

int64_t Count(int64_t n) {
  int64_t ans = n - n / 2 - n / 3 - n / 5 - n / 7 + n / 6 + n /10 + n / 14 + n / 15 + n / 21 + n / 35 - n / 30 - n / 42 - n / 70 - n / 105 + n / 210;
  return ans;
}

void solve(){
    int64_t l, r;
    cin >> l >> r;
    cout << Count(r) - Count(l - 1) << '\n';
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}