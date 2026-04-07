#include<bits/stdc++.h>
using namespace std;

string str;
vector<string> ans;
int char_count[26];

void search(string curr){
    if(curr.size() == str.size()){
        ans.push_back(curr);
        return;
    }
    for(int i = 0; i < 26; i++){
        if(char_count[i] > 0){
            char_count[i]--;
            search(curr + (char)('a' + i));
            char_count[i]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> str;
    for(char c: str){
        char_count[c - 'a'] ++;
    }
    search("");

    cout << ans.size() << "\n";

    for(string str: ans){
        cout << str << "\n";
    }

    return 0;
}