/**
 *      author:  mingsm
 *      created: 2025-10-29 10:31:58
 *      link: 
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
    //freopen("filename.in", "r", stdin);
    //freopen("filename.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n);
    for(int& x:a) cin >> x;
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int ii = i; ii <= j; ii++){
                sum += a[ii];
            }
            double avg = 1.0 * sum / (j - i + 1);
            for(int ii = i; ii <= j; ii++){
                if(a[ii] == avg){
                    ans ++;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}