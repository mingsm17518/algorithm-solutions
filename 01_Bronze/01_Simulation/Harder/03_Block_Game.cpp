/**
 *      author:  mingsm
 *      created: 2025-10-20 00:58:00
 *      link: https://usaco.org/index.php?page=viewproblem2&cpid=664
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
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int n; cin >> n;
    vector<int> ans(26);
    for(int i = 0; i < n; i++){
        string a, b; cin >> a >> b;
        vector<int> num_a(26);
        vector<int> num_b(26);
        for(char c:a){
            num_a[c-'a']++;
        }
        for(char c:b){
            num_b[c-'a']++;
        }
        for(int j = 0; j < 26; j++){
            ans[j] += max(num_a[j], num_b[j]);
        }
    }
    for(int x:ans){
        cout << x << "\n";
    }
    return 0;
}