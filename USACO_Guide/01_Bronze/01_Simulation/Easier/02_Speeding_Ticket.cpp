#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("FileName.in", "r", stdin);
    freopen("FileName.out", "w", stdout);
    int m, n;
    cin >> m >> n;
    vector<int> limit(100);
    vector<int> speed(100);
    int start = 0;
    while(m--){
    	int x, y;
    	cin >> x >> y;
    	for(int j = start; j < start + x; j ++){
            limit[j] = y;
        }
        start += x;
    }
    start = 0;
    while(n--){
    	int x, y;
    	cin >> x >> y;
    	for(int j = start; j < start + x; j ++){
            speed[j] = y;
        }
        start += x;
    }
    int ans = 0;
    for(int i = 0; i < 100; i++){
        ans = max(ans, speed[i] - limit[i]);
    }
    cout << ans;
    return 0;
}