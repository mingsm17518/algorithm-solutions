/**
 *      author:  mingsm
 *      created: 2025-09-18 09:15:21
 *      link: https://usaco.org/index.php?page=viewproblem2&cpid=572
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	  freopen("bcount.in","r",stdin);
    freopen("bcount.out","w",stdout);

    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> c(n + 1);
    for (int i = 0; i < n; i++){
      a[i + 1] = a[i];
      b[i + 1] = b[i];
      c[i + 1] = c[i];
      int x; cin >> x;
      if (x == 1) a[i + 1]++;
      else if (x == 2) b[i + 1]++;
      else if (x == 3) c[i + 1]++;
    }
    for(int i = 0; i < q; i++){
      int l, r; cin >> l >> r;
      cout << a[r] - a[l - 1] << " " << b[r] - b[l - 1] << " " << c[r] - c[l - 1] << "\n";
    }

    return 0;
}