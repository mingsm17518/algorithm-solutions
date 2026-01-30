/**
 *      author:  mingsm
 *      created: 2025-10-20 15:46:07
 *      link: https://usaco.org/index.php?page=viewproblem2&cpid=831
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

vector<string> a(3);

int one_win_check(char c){
    if(a[0][0] == c && a[1][1] == c && a[2][2] == c) return 1;
    if(a[0][2] == c && a[1][1] == c && a[2][0] == c) return 1;
    for(int i = 0; i < 3; i++){
        if(a[i][0] == c && a[i][1] == c && a[i][2] == c) return 1;
        if(a[0][i] == c && a[1][i] == c && a[2][i] == c) return 1;
    }
    return 0;
}

bool check(char ch1, char ch2, char a, char b, char c){
    if(a != ch1 && a != ch2) return false;
    if(b != ch1 && b != ch2) return false;
    if(c != ch1 && c != ch2) return false;
    if(a == b && b == c) return false;
    return true;
}

int two_win_check(char ch1, char ch2){
    for(int i = 0; i < 3; i ++){
        if(check(ch1, ch2, a[i][0], a[i][1], a[i][2])) return 1;
        if(check(ch1, ch2, a[0][i], a[1][i], a[2][i])) return 1;
    }
    if(check(ch1, ch2, a[0][0], a[1][1], a[2][2])) return 1;
    if(check(ch1, ch2, a[0][2], a[1][1], a[2][0])) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    for(string& s: a) cin >> s;
    int one_win = 0, two_win = 0;
    for(char c = 'A'; c <= 'Z'; c++){
        one_win += one_win_check(c);
        debug(one_win);
    }
    for(int ch1 = 'A'; ch1 < 'Z'; ch1++){
        for(int ch2 = ch1 + 1; ch2 <= 'Z'; ch2++){
            two_win += two_win_check(ch1, ch2);
        }
    }
    cout << one_win << "\n" << two_win;
    return 0;
}