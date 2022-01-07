#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size(),ans,ans2;
    vector<int> dp(n,0);
    dp[0] = nums[0]; ans = dp[0];
    for(int i=1;i<n;i++) {
        dp[i] = max(nums[i], dp[i-1]+nums[i]);
        ans = max(ans,dp[i]);
    }
    vector<int> nums2(n);
    for(int i=0;i<n;i++)
        nums2[i] = -1*nums[i];
    vector<int> dp2(n,0);
    dp2[0] = nums2[0]; ans2 = dp2[0];
    for(int i=1;i<n;i++) {
        dp2[i] = max(nums2[i], dp2[i-1]+nums2[i]);
        ans2 = max(ans,dp2[i]);
    }
    return max(ans,ans2);
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}