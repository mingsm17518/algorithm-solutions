#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<ll> apples;

ll sol(int ind, ll sum1, ll sum2){
    if(ind == n){
        return abs(sum1 - sum2);
    }
    return min(sol(ind+1, sum1 + apples[ind], sum2),
                sol(ind+1, sum1, sum2 + apples[ind]));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    apples.resize(n);
    for(int i = 0; i < n; i++){
        cin >> apples[i];
    }
    ll ans = sol(0, 0, 0);
    cout << ans;

    return 0;
}
