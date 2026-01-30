#include <bits/stdc++.h>
using namespace std;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    speedup();
    int t, sum = 0;
    cin >> t;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c >= 2) {
            sum++;
        }
    }
    
    cout << sum;
    return 0;
}