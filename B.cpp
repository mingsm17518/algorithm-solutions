#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct State {
    int inc_len, dec_len; // 末尾连续递增和递减长度
    int last;             // q末尾元素
    bool valid;           // 当前状态是否合法
    State() : inc_len(0), dec_len(0), last(-1), valid(true) {}
    State(int l, int i, int d, bool v) : last(l), inc_len(i), dec_len(d), valid(v) {}
};

State update(State s, int x) {
    if (!s.valid) return s;
    if (s.last == -1) { // 第一个元素
        s.last = x;
        s.inc_len = s.dec_len = 1;
        return s;
    }
    if (x > s.last) {
        s.inc_len++;
        s.dec_len = 1;
    } else if (x < s.last) {
        s.dec_len++;
        s.inc_len = 1;
    } else {
        s.inc_len = 1;
        s.dec_len = 1;
    }
    s.last = x;
    if (s.inc_len >= 5 || s.dec_len >= 5) s.valid = false;
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];

        int l = 0, r = n - 1;
        string ans;
        State curr;

        for (int i = 0; i < n; ++i) {
            // 尝试左边
            State left_state = update(curr, p[l]);
            // 尝试右边
            State right_state = update(curr, p[r]);

            if (left_state.valid && right_state.valid) {
                // 两边都合法，优先选较小值
                if (p[l] < p[r]) {
                    curr = left_state;
                    ans += 'L';
                    l++;
                } else {
                    curr = right_state;
                    ans += 'R';
                    r--;
                }
            } else if (left_state.valid) {
                curr = left_state;
                ans += 'L';
                l++;
            } else if (right_state.valid) {
                curr = right_state;
                ans += 'R';
                r--;
            } else {
                // 题目保证有解，这里理论不应该出现
                // 强行选左边以防死循环
                curr = left_state;
                ans += 'L';
                l++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
