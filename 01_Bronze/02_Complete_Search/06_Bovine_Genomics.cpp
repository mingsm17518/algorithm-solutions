#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

int char2idx(char c){
    switch (c) {
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
        default: 
            return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<char>> b(n, vector<char>(m));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }

    int ans = 0;
    for(int j = 0; j < m; j++){
        vector<int> check(4);
        bool is = true;
        for(int i = 0; i < n; i++){
            check[char2idx(a[i][j])] ++;
        }
        for(int i = 0; i < n; i++){
            if(check[char2idx(b[i][j])]){
                is = false;
                break;
            }
        }
        if(is){
            ans ++;
        }
    }
    cout << ans;
    return 0;
}