#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,1));
    for(int i=1;i<m;i++) {
        for(int j=1;j<n;j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}