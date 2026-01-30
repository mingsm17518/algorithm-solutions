#include <cstdio>
#include <algorithm>
using namespace std;

int num[500001];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int mav = 0, t, cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t == k) cnt++;
        else num[t] = max(num[t], cnt) + 1;

        mav = max(mav, num[t] - cnt);
    }

    printf("%d", cnt + mav);
}