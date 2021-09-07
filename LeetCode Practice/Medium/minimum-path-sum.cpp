#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

int min_path_sum(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    int m = grid.size(), n = grid[0].size();
    if(dp[x][y] > 0)
        return dp[x][y];
    if(x==m-1 && y==n-1)
        return dp[x][y] = grid[x][y];
    if(x==m-1)
        return dp[x][y] = (grid[x][y] + min_path_sum(x,y+1,grid,dp));
    if(y==n-1)
        return dp[x][y] = (grid[x][y] + min_path_sum(x+1,y,grid,dp));
    return dp[x][y] = (grid[x][y] + min(min_path_sum(x+1,y,grid,dp), min_path_sum(x,y+1,grid,dp)));
}

int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size() , vector<int>(grid[0].size(),0));
    return min_path_sum(0,0,grid, dp);
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}