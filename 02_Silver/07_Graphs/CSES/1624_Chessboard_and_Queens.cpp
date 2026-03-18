#include<bits/stdc++.h>
using namespace std;

int n = 8;
vector<vector<bool>>blocked(n, vector<bool>(n));
vector<int> queens(n);

bool check(){
    for(int i = 0; i < n; i++){
        int j = queens[i];
        if(blocked[i][j]){
            return false;
        }
    }

    vector<bool> taken1(n * 2 - 1);
    for(int i = 0; i < n; i++){
        int sum = queens[i] + i;
        if(taken1[sum]){
            return false;
        }
        taken1[sum] = true;
    }

    vector<bool> taken2(n * 2 - 1);
    for(int i = 0; i < n; i++){
        int diff = queens[i] - i + n - 1;
        if(taken2[diff]){
            return false;
        }
        taken2[diff] = true;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '*'){
                blocked[i][j] = true;
            } else{
                blocked[i][j] = false;
            }
        }
    }
    
    iota(queens.begin(), queens.end(), 0);
    int ans = 0;
    do{
        if(check()){
            ans++;
        }
    } while(next_permutation(queens.begin(), queens.end()));

    cout << ans;
    
    return 0;
}