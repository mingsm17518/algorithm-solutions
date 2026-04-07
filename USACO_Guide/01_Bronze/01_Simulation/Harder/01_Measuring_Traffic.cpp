/**
 *      author:  mingsm
 *      created: 2025-10-19 11:22:09
 *      link: https://usaco.org/index.php?page=viewproblem2&cpid=917
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<string> mode(n);
    for(int i = 0; i < n; i++){
        cin >> mode[i] >> a[i] >> b[i];
    }
    int low = 0, high = 1e9;
    for(int i = n - 1; i >= 0; i--){
        if(mode[i] == "none"){
            low = max(low, a[i]);
            high = min(high, b[i]);
        } else if(mode[i] == "off"){
            high += b[i];
            low += a[i];
        } else if(mode[i] == "on"){
            high -= a[i];
            low -= b[i];
            low = max(low, 0);
        }
    }
    cout << low << " " << high << "\n";
    low = 0; high = 1e9;
    for(int i = 0; i < n; i++){
        if(mode[i] == "none"){
            low = max(low, a[i]);
            high = min(high, b[i]);
        } else if(mode[i] == "on"){
            low += a[i];
            high += b[i];
        } else if(mode[i] == "off"){
            low -= b[i];
            high -= a[i];
            low = max(0, low);
        }
    }
    cout << low << " " << high;
    return 0;
}