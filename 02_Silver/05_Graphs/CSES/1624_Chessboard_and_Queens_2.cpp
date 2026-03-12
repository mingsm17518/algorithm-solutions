#include<bits/stdc++.h>
using namespace std;

int n = 8;
vector<vector<int>> blocked(n, vector<int>(n));
int ans = 0;
vector<bool> row_taken(n);
vector<bool> diag1(2 * n - 1);
vector<bool> diag2(2 * n - 1);

void search_queens(int j){
    if(j == n){
        ans++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!blocked[i][j] && !row_taken[i] && !diag1[i+j] && ! diag2[i-j+n-1]){
            row_taken[i] = diag1[i+j] = diag2[i-j+n-1] = true;
            search_queens(j+1);
            row_taken[i] = diag1[i+j] = diag2[i-j+n-1] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            blocked[i][j] = s[j] == '*';
        }
    }
    search_queens(0);
    cout << ans;
    return 0;
}