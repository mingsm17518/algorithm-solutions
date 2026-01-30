#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define vec vector
#define fi first
#define se second

using namespace std;

struct DSU {
    int n;
    vec<int> p;
    DSU(int _n): n(_n), p(n+1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a==b) return false;
        p[b] = a;
        return true;
    }
};

void solve(){
    int n;
    cin >> n;
    struct E{int a,b,w,idx;};
    vec<E> edges(n);
    int maxNode = 0;
    for(int i=0;i<n;i++){
        cin >> edges[i].a >> edges[i].b;
        edges[i].w = edges[i].b - edges[i].a;
        edges[i].idx = i+1;
        maxNode = max({maxNode, edges[i].a, edges[i].b});
    }
    sort(edges.begin(), edges.end(), [&](auto &x, auto &y){
        return x.w > y.w;
    });
    DSU dsu(maxNode);
    vec<int> ans;
    for(auto &e: edges){
        if(dsu.unite(e.a, e.b)){
            ans.push_back(e.idx);
        }
    }
    cout << ans.size() << "\n";
    for(int i=0;i<(int)ans.size();i++){
        cout << ans[i] << (i+1<(int)ans.size()?' ':'\n');
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}