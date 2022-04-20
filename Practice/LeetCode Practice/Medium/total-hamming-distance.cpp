#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007


int totalHammingDistance(vector<int>& nums) {
    int ans = 0;
    for(int j = 31;j>=0;j--){
        int ones = 0;
        int zeroes =0;
    for(int i =0;i<nums.size();i++){
        if(nums[i]&1){
            ones++;
        }
        else zeroes++;
        nums[i]>>=1;
    }
        ans += ones *zeroes;
    }
    return ans;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}


