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
    vector<pair<int, char>> cow(n);
    for(int i = 0; i < n; i++){
        cin >> cow[i].second >> cow[i].first;
    }
    sort(cow.begin(), cow.end());
    vector<int> left_lying(n);
    for(int i = 1; i < n; i++){
        left_lying[i] = left_lying[i-1];
        if(cow[i-1].second == 'L'){
            left_lying[i] ++;
        }
    }
    vector<int> right_lying(n);
    for(int i = n - 2; i >= 0; i--){
        right_lying[i] = right_lying[i+1];
        if(cow[i+1].second == 'G'){
            right_lying[i]++;
        }
    }
    int ans = n;
    for(int i = 0; i < n; i++){
        ans = min(ans, left_lying[i] + right_lying[i]);
    }
    cout << ans;
    return 0;
}