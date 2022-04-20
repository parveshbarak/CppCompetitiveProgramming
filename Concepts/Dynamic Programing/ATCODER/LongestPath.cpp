#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1000000007


void dfs(vector<ll> adj[], vector<ll> dp, vector<bool> visited, ll i) {
    if(visited[i])
        return;
    visited[i] = true;
    
    for(ll j=0;j<adj[i].size();j++) {
        ll nei = adj[i][j];
        //cout << nei << " ";
        if(!visited[nei])
            dfs(adj,dp,visited,nei);
        dp[i] = max(dp[i], 1+dp[nei]);
    }
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n,m, res=0;
    cin >> n >> m;
    vector<ll> adj[n+1];
    for(ll i=0;i<m;i++) {
        ll x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<ll> dp(n+1, 0);
    vector<bool> visited(n+1,false);

    for(ll i=1;i<=n;i++) {
        if(!visited[i]) {
            //cout << visited[i] << "   ";
            dfs(adj,dp,visited,i);
        }
    }

    // for(auto d : visited) 
        //res = max(res,d);

    //cout << res;

return 0;
}
