/**
 *      author:  mingsm
 *      created: 2025-08-15 22:58:27
 */
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using pii = pair<int, int>;
using vec = vector<int>;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){

    int d, sumTime;
    cin >>d >> sumTime;
    vector<int> minTime(d);
    vector<int> maxTime(d);

    int total_min = 0, total_max = 0;
    
    for(int i = 0; i < d; i++){
        cin >> minTime[i] >> maxTime[i];
        total_min += minTime[i];
        total_max += maxTime[i];
    }

    if(total_min > sumTime || total_max < sumTime){
        cout << "NO";
        return;
    }

    cout << "YES" << endl;

    vector<int> schedule(d);
    for(int i = 0; i < d; i++){
        schedule[i] = minTime[i];
    }

    int rem = sumTime - total_min;
    for(int i = 0; i < d; i++){
        if(rem <= 0) break;
        int add = min(maxTime[i] - minTime[i], rem);
        schedule[i] += add;
        rem -= add;
    }

    for(int i = 0; i < d; i++){
        cout << schedule[i];
        if(i < d - 1) cout << " ";
    }
    
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}