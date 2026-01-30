/**
 *      author:  mingsm
 *      created: 2025-09-25 10:39:12
 *      link: https://usaco.org/index.php?page=viewproblem2&cpid=855
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
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);
    int n = 3;
    vector<int> capacity(n);
    vector<int> milk(n);
    for(int i = 0; i < n; i++){
        cin >> capacity[i] >> milk[i]; 
    }
    for(int i = 0; i < 100; i++){
        int bucket1 = i % n;
        int bucket2 = (i + 1) % n;
        int change = min(milk[bucket1], capacity[bucket2] - milk[bucket2]);
        milk[bucket1] -= change;
        milk[bucket2] += change;
    }
    for(int x: milk) cout << x << "\n";
    return 0;
}