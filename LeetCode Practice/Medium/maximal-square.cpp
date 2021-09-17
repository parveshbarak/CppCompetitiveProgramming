#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int res = 0;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            dp[i][j] = min(dp[i-1][j-1],dp[i-1][j], dp[i][j-1]) + 1;
            res = max(res,dp[i][j]);
        }
    }
    return res;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}