/**
 *      author:  mingsm
 *      created: 2025-09-10 08:33:15
 *      link: https://usaco.org/index.php?page=viewproblem2&cpid=595
 *      Question: Output the longest length of the subarray whose sum is a multiple of 7
 *      Solution：除7同余的下标之间的子数组 和为7的倍数
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
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(7, -1);
    a[0] = 0;
    int current_sum = 0;
    int max_length = 0;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        current_sum = (current_sum + x) % 7;
        if (a[current_sum] == -1){
            // if current remainder does not exist, record i
            a[current_sum] = i;
        } else{
            // else, sum of subarrays between i and the previously recorded subscript is a multiple of 7
            max_length = max(max_length, i - a[current_sum]);
        }
    }
    cout << max_length;

    return 0;
}