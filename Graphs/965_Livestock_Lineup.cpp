#include <bits/stdc++.h>
using namespace std;

// https://usaco.guide/bronze/intro-graphs?lang=cpp
// USACO 965: Livestock Lineup
// 问题描述：有8头奶牛，需要按照给定的邻接约束排列成一行，使得所有相邻的奶牛都满足约束条件。
// 约束条件构成一个图，其中奶牛是节点，约束是边。由于是线排列，图由不相交的路径组成。
// 我们通过寻找端点（邻居数为0或1的奶牛）并遍历路径来构建排列。
// https://usaco.org/index.php?page=viewproblem2&cpid=965

// 定义所有奶牛的名字，按字典序排序，以便后续索引一致
const vector<string> COWS = [](){
    vector<string> temp{"Bessie", "Buttercup", "Belinda",
        "Beatrice","Bella",  "Blue", "Betsy","Sue"};
    sort(begin(temp), end(temp));
    return temp;
}();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    // 将奶牛名字映射到索引，用于O(1)查找
    map<string, int>cow_idx;
    int n = COWS.size();
    for(int i = 0; i < n; i++){
        cow_idx[COWS[i]] = i;
    }

    int tt;
    cin >> tt;
    // 邻接表，存储每头奶牛的邻居
    vector<vector<int>> neighbors(n);
    while(tt--){
        string cow1;
        string cow2;
        string trash;
        cin >> cow1 >> trash >> trash >> trash >> trash >> cow2;
        int cow1_idx = cow_idx[cow1];
        int cow2_idx = cow_idx[cow2];
        neighbors[cow1_idx].push_back(cow2_idx);
        neighbors[cow2_idx].push_back(cow1_idx);
    }

    // 存储最终的排列顺序
    vector<int> order;
    // 标记奶牛是否已被添加到排列中
    vector<bool> added(n);
    // 遍历所有奶牛，按字典序查找端点开始构建排列
    for(int i = 0; i < n; i++){
        // 按字典序遍历每头牛
        // 找到 邻居为0个或1个，并且没有被添加 的牛i
        if(neighbors[i].size() <= 1 && !added[i]){
            // 添加牛i
            added[i] = true;
            order.push_back(i);
            // 如果邻居为1个，则沿着链继续添加
            if(neighbors[i].size() == 1){
                int prev = i;
                // 牛i的邻居
                int now = neighbors[i][0];

                // 牛i的邻居的邻居有2个的情况，说明在链的中间，继续遍历
                while(neighbors[now].size() == 2){
                    added[now] = true;
                    order.push_back(now);
                    int a = neighbors[now][0];
                    int b = neighbors[now][1];
                    int temp = a == prev ? b : a;
                    prev = now;
                    now = temp;
                }
                // 否则，牛i的邻居的邻居只有1个，即牛i，说明到达链的另一端
                // 添加牛i的邻居即可
                added[now] = true;
                order.push_back(now);

            }
        }
    }
    for(int order_idx: order){
        cout << COWS[order_idx] << "\n";
    }

    return 0;
}
