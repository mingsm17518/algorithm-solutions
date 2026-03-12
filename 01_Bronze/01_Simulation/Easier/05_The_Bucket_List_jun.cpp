#include <bits/stdc++.h>

constexpr int N = 1000;
constexpr int inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> s(n), t(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i] >> t[i] >> b[i];
    }
    std::vector<int> time(N + 1);
    for (int i = 0; i < n; i++) {
        time[s[i]] += b[i];
        time[t[i] + 1] -= b[i];
    }
    for (int i = 1; i <= N; i++) {
        time[i] += time[i - 1];
    }
    int lo = 0, hi = inf;
    auto check = [&](int x) -> bool {
        bool ok = true;
        for (int i = 0; i <= N; i++) {
            if (x < time[i]) {
                ok = false;
            }
        }
        return ok;
    };
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    std::cout << lo;
}