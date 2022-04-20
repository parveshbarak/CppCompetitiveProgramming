#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size(), ans = INT_MIN;
    vector<vector<int>> dp(1005,vector<int>(n,0));

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int diff = nums[j] - nums[i] + 500;
            dp[i][diff] = max(dp[i][diff] , dp[j][diff]+1);
            ans = max(ans,dp[j][diff]);
        }
    }
    return ans+1;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}