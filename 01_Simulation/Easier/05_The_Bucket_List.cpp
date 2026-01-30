/**
 *      author:  mingsm
 *      created: 2025-10-18 16:26:25
 *      link: https://usaco.org/index.php?page=viewproblem2&cpid=856&lang=en
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
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    int n; cin >> n;
    vector<int> s(1000);
    vector<int> t(1000);
    for(int i = 0; i < n; i++){
        int x, y, num_b; cin >> x >> y >> num_b;
        s[x] = num_b;
        t[y] = num_b;
    }
    int total_b = 0;
    int free_b = 0;
    for(int i = 0; i < 1000; i++){
        free_b += t[i];
        if(free_b > s[i]){
            free_b -= s[i];
        } else{
            total_b += s[i] - free_b;
            free_b = 0;
        }
    }
    cout << total_b;
    return 0;
}