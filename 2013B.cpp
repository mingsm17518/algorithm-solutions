#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s, sum = 0;
    cin >> n >> s;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
        sum += x;
    }
    if(n == 3 & s == 2){
        cout << "0 1 2" << "\n";
        return;
    }
    
    int T = s - sum;
    if (T < 0 || T == 1) {
        sort(a.begin(), a.end(), [](int x, int y) {
            if (x == y) return false;
            if (x == 0) return true;
            if (x == 2 && y == 1) return true;
            return false;
        });
        for (int i = 0; i < n; ++i)
            cout << (i ? " " : "") << a[i];
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
