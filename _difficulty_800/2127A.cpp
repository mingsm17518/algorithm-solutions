/**
 *      author:  mingsm
 *      created: 2025-09-04 08:38:28
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int mx = *max_element(a.begin(), a.end());
        if (mx == -1){
            cout << "YES\n";
            continue;
        } else if(mx == 0){
            cout << "NO\n";
            continue;
        }
        bool ok = (mx > 0);
        for(int i = 0; i < n; i++){
            if(a[i] != -1 && a[i] != mx){
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}