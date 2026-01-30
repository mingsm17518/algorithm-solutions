/**
 *      author:  mingsm
 *      created: 2025-09-16 10:35:13
 *      link: https://cses.fi/problemset/task/1660
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
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for(int& num: a){
        cin >> num;
    }
    int l = 0, r = 0;
    int sum = a[0];
    int ans = 0;
    while(r < n){
        if(sum < x){
            r++;
            sum += a[r];
        } else if(sum == x){
            ans++;
            sum -= a[l];
            l++;
        } else{
            sum -= a[l];
            l++;
        }
    }
    cout << ans << "\n";
    return 0;
}