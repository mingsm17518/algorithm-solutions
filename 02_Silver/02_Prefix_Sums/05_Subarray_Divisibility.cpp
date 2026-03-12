/**
 *      author:  mingsm
 *      created: 2025-09-18 09:09:52
 *      link: https://cses.fi/problemset/task/1662
 *      Question: Output the number of subarrays whose sum is divisible by n
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
    int n; cin >> n;

    vector<int64_t> a(n);
    a[0] = 1;

    int64_t current = 0;
    int64_t ans = 0;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        current = (current + x) % n;
        if(current < 0) current += n;
        a[current]++;
    }

    for(auto x: a){
        ans += x * (x - 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}