#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

int uniquePathsWithObstacles(vector<vector<int>>& og) {
    int m = og.size(), n = og[0].size();
    vector<vector<int>> dp(m, vector<int>(m,1));

    for(int i=0;i<m;i++) {
        for(int j=0; j<n;j++) {
            if(og[i][j] = 1)
                dp[i][j] = 0;
        }
    }


    for(int i=1;i<m;i++) {
        for(int j=1;j<n;j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    
    
    for(int i=1;i<m;i++) {
        for(int j=1;j<n;j++) {
            if(dp[i][j] == 0)
                continue;
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