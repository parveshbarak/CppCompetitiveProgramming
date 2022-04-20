#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
int maxSubArray(vector<int>& nums) {
    int n = nums.size(),ans;
    vector<int> dp(n,0);
    dp[0] = nums[0]; ans = dp[0];
    for(int i=1;i<n;i++) {
        dp[i] = max(nums[i], dp[i-1]+nums[i]);
        ans = max(ans,dp[i]);
    }
    return ans;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}