#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <unordered_set>
using namespace std;

const int MAX_VAL = 5000;
int gcd_table[MAX_VAL+1][MAX_VAL+1];

void precompute_gcd_table() {
    for (int i = 1; i <= MAX_VAL; i++) {
        gcd_table[i][i] = i;
    }
    for (int i = 1; i <= MAX_VAL; i++) {
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                gcd_table[i][j] = j;
            } else {
                gcd_table[i][j] = gcd_table[j][i % j];
            }
        }
    }
    for (int i = 1; i <= MAX_VAL; i++) {
        for (int j = i+1; j <= MAX_VAL; j++) {
            gcd_table[i][j] = gcd_table[j][i];
        }
    }
}

int main() {
    precompute_gcd_table();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        int g = a[0];
        for (int i = 1; i < n; i++) {
            g = gcd_table[g][a[i]];
        }
        int count_g = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == g) {
                count_g++;
            }
        }
        if (count_g > 0) {
            cout << n - count_g << endl;
            continue;
        }
        vector<int> b;
        for (int x : a) {
            b.push_back(x / g);
        }
        sort(b.begin(), b.end());
        auto last = unique(b.begin(), b.end());
        b.erase(last, b.end());
        int m = b.size();
        int max_val = *max_element(b.begin(), b.end());
        vector<int> dp(max_val + 1, 1000000000);
        set<int> current_states;
        for (int x : b) {
            if (x <= max_val) {
                dp[x] = 1;
                current_states.insert(x);
            }
        }
        bool found = false;
        for (int x : b) {
            if (found) break;
            vector<int> states(current_states.begin(), current_states.end());
            for (int d : states) {
                int new_g = gcd_table[x][d];
                if (dp[new_g] > dp[d] + 1) {
                    dp[new_g] = dp[d] + 1;
                    current_states.insert(new_g);
                    if (new_g == 1 && dp[1] == 2) {
                        found = true;
                        break;
                    }
                }
            }
        }
        int k = dp[1];
        int ans = (k - 1) + (n - 1);
        cout << ans << endl;
    }
    return 0;
}