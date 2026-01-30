#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    vector<int> freq(55, 0);
    for (int x : S) freq[x]++;
    int ans = 0;
    int cnt2 = min(freq[0], freq[1]);
    ans += cnt2 * 2;
    freq[0] -= cnt2;
    freq[1] -= cnt2;
    int cnt1 = freq[0];
    ans += cnt1;
    freq[0] = 0;
    for (int i = 0; i < 55; i++) {
        if (freq[i] > 0) {
            ans += i * freq[i];
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}