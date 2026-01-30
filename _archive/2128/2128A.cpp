/**
 *      author:  mingsm
 *      created: 2025-08-18 17:18:15
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x) << "\n"

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vce = vector<int>;

inline void speedup() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

void solve(){
    int n, c;
    cin >> n >> c;
    vce a(n);
    for(int i = 0; i < n; i++) cin >> a[i]; 
    sort(a.begin(), a.end());
    int ans = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if(a[i] <= c){
            ans --;
            c /= 2;
        }
    }
    print(ans);
    
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}