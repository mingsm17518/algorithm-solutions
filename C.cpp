#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 4e18;

void solve() {
    int n;
    cin >> n;
    vector<ll> b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> b[i];

    set<pair<int, ll>> alive;
    for (int i = 1; i <= n; ++i) alive.insert({i, b[i]});

    priority_queue<int> pq;
    for (int i = 1; i <= n; ++i) pq.push(i);

    while (!pq.empty()) {
        int i = pq.top(); pq.pop();
        auto it = alive.find({i, b[i]});
        if (it == alive.end()) continue; 

        ll min_pre = INF;
        auto it2 = alive.begin();
        while (it2 != alive.end() && it2->first < i) {
            min_pre = min(min_pre, it2->second);
            ++it2;
        }

        if (i > 1 && min_pre * 2 <= b[i]) {
            cout << "NO\n";
            return;
        }

        ll d = (i > 1) ? min(min_pre, b[i]) : b[i];
        alive.erase({i, b[i]});
        b[i] -= d;

        if (b[i] > 0) {
            alive.insert({i, b[i]});
            pq.push(i);
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
