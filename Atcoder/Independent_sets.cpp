#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
// #define MOD 1e9+7

const ll MOD = 1e9+7;

vector<ll> tree[100005]; // array of vector
// vector<vector<ll>> dp(100005, vector<ll>(2,-1));
ll dp[100005][2];

ll independentSet(ll node,ll parent, ll c) {     //c=>  contraint or color
    if(dp[node][c] != -1) return dp[node][c];
    ll ans = 0; ll w0 = 1;      // w0 is without constraints in both cases or say black in both cases!
    for(auto child :tree[node]) {
        if(c != parent) {
            w0 = (w0*independentSet(child, node, 0))%MOD;
        }
    }
    ans += w0;
    if(!c) {
        ll w1 = 1;
        for(auto child :tree[node]) {
            if(c != parent) {
                w1 = (w1*independentSet(child, node, 1))%MOD;
            }
        }
        ans = (ans%MOD + w1%MOD)%MOD;
    }
    return dp[node][c] = ans;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for(ll i=0;i<n-1;i++) {
        ll u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    cout << independentSet(1,-1,0);     // First Node 1, has no parent i.e -1, has no contraint/or can take both values i.e. 0
    
    return 0;
}