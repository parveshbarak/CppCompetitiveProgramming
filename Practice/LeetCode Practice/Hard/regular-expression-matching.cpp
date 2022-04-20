#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
bool isMatch(string s, string p) {
    int i=0,j=0,n=s.length(),m=p.length();
    vector<vector<bool>> dp(n+1,vector<bool>(m+1));

    /*base case :->
        1. The zeroth col will be zero as no match when no pattern is given
        2. The zeroth col can have non zero value/true in case p[1] has a "*"
            conditions like a*, a*b*, a*b*c* etc
    */ 
   /* Other cases :->
        1. s[i] and p[j] matches or p[j] is a "." => dp[i][j] = dp[i-1][j-1] i.e without including thses two
        2. p[j] is a "*" => dp[i][j] = (dp[i-1][j] OR dp[i][j-2]) i.e if we include thee previous char or not
        3. else false 
   */
    dp[0][0] = true;
    for(i=1;i<=m;i++) {
        if(p[i-1] == '*')
            dp[0][i] = dp[0][i-2];
    }

    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(p[j-1] == '.' || p[j-1] == s[i-1])
                dp[i][j] = dp[i-1][j-1];
            else if(p[j-1] == '*') {
                dp[i][j] = dp[i][j-2];
                if(p[j-2] == '.' || p[j-2] == s[i-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            }
            else
                dp[i][j] = false;
        }
    }
    // for(i=0;i<=n;i++) {
    //     for(j=0;j<=m;j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    return dp[n][m];
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}