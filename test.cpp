#include<iostream>
#include<vector>
#include<algorithm>


int test(std::vector<int> &arr, int target){
    int l = 0;
    int r = arr.size()-1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return -1;
}

int main(){
    std::vector<int> a(4);
    for(int & x:a){
        std::cin >> x;
    }
    int target = 6;
    int ans = test(a, target);
    std :: cout << ans;
}