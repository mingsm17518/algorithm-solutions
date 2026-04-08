#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    if (!(cin >> n >> x)) return 0;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<long long> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 0; i <= x; i++) {
        for (int c : coins) {
            if (i - c >= 0) {
                dp[i] = (dp[i - c] + dp[i]) % MOD;
            }
        }
    }

    cout << dp[x] << "\n";
    return 0;
}