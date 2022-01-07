#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

int get_ans(int l, int h, vector<vector<int>>&dp){
    if(l>=h)
        return 0;
    if(dp[l][h] != INT_MAX)
        return dp[l][h];
    for(int i=l;i<=h;i++){
        dp[l][h] = min(dp[l][h], max(i+get_ans(i+1,h,dp), i+get_ans(l,i-1,dp)));
    }
    return dp[l][h];
}

int getMoneyAmount(int n) {
    vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
    return get_ans(1,n,dp);
}
    

 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}