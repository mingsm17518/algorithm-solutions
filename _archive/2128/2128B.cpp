/**
 *      author:  mingsm
 *      created: 2025-08-18 19:33:58
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
    int n;
    cin >> n;
    vec a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    string ans;
    int flag = 0;
    int l = 0, r = n - 1;
    while(l < r){
        if((a[l] < a[r]) ^ flag){
            ans += "LR";
        } else{
            ans += "RL";
        }
        flag ^= 1;
        l ++;
        r --;
    }
    if(l == r) ans += "L";

    cout << ans << "\n";

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}