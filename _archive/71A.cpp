/**
 *      author:  mingsm
 *      created: 2025-08-15 23:17:10
 */
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using pii = pair<int, int>;
using vec = vector<int>;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    
    string word;
    cin >> word;
    if(word.size() <= 10){
        cout << word << "\n";
    } else{
        cout << word[0] << word.size() - 2 << word.back() << "\n";
    }

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}