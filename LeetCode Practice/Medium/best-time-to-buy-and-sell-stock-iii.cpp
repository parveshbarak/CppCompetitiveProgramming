#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
int maxProfit(vector<int>& prices) {
    int n = prices.size(),ans = INT_MIN;
    vector<vector<int>> dp(3,vector<int>(n,0));

    for(int i=1;i<3;i++) {
        int max_diff = INT_MIN;
        for(int j=1;j<n;j++) {
            max_diff = max(max_diff, dp[i-1][j-1] - prices[j-1]);
            dp[i][j] = max(dp[i][j-1] , prices[j] + max_diff);
            ans = max(ans,dp[i][j]);
        }
    }
    return max(ans,0);
}

 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}