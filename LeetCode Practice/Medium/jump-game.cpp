#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

// bool naive(vector<int>& nums, int idx) {
//     if(idx==nums.size()-1)
//         return true;
//     if(idx>nums.size()-1)
//         return false;

//     bool mx = false;
//     for(int j=1;j<=nums[idx];j++) {
//         mx = max(mx,naive(nums,j+idx));
//     }
//     return mx;
// }

// bool canJump(vector<int>& nums) {
//     return naive(nums, 0);
// }

// vector<int> dp;

// int naive_memo(vector<int>& nums, int idx) {
//     if(idx==nums.size()-1)
//         return 1;
//     if(idx>nums.size()-1)
//         return 0;
//     if(dp[idx] != -1)
//         return dp[idx];

//     int mx = 0;
//     for(int i=1;(i<=nums[idx]&&i+idx<nums.size());i++) {
//         if(dp[i+idx] != -1)
//             dp[i] = dp[i+idx];
//         else
//             dp[i] = max(0,naive_memo(nums,i+idx));
        
//         if(dp[i]==1)
//             return 1;
//     }
//     return dp[nums.size()-1];
// }



//still the simple solution is below(greedy) :->
bool canJump(vector<int>& nums) {
    int r=0, n=nums.size();
    for(int i=0;i<n;++i) {
        if(r<i) return false;
        r=max(r,i+nums[i]);
    }
    return true;
}

bool canJump(vector<int>& nums) {
    dp.resize(10004,-1);
    return naive_memo(nums, 0);
}

 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    
    cout << canJump(arr) << "\n";
    
    return 0;
}