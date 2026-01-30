#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("lostcow.in", "r", stdin);
    // freopen("lostcow.out", "w", stdout);
    int x, y;
    std::cin >> x >> y;
    int dir = 1;
    int now = x;
    int ans = 0;
    int dis = 1;
    while (true) {
        if ((y >= x && now >= y) || (y <= x && now <= y)) {
            ans -= std::abs(now - y);
            break;
        } else {
            int nnow = x + dir * dis;
            ans += std::abs(nnow - now);
            now = nnow;
            dir *= -1;
            dis *= 2;
        }
    }
    std::cout << ans;
    return 0;
}