/**
 *      author:  mingsm
 *      created: 2025-09-03 10:29:04
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
    int p = 0;
    if(n % 2 == 0){
        p = n / 2 + 1;
    } else{
        p = (n + 1) / 2 + 1;
    }
    for(int i = 0; i < n; i++){
        int x = 0;
        if(i % 2 == 0){
            x = -1;
        } else if(i == n - 1){
            x = 2;
        }
        else{
            x = 3;
        }
        cout << x << " \n"[i == n-1];
    }
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}