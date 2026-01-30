/**
 *      author:  mingsm
 *      created: 2025-09-03 08:42:24
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
    string a; cin >> a;
    int m; cin >> m;
    string b, c; cin >> b >> c;
    for(int i = 0; i < m; i++){
        if(c[i] == 'V'){
            a = b[i] + a;
        } else{
            a += b[i];
        }
    }
    cout << a << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}