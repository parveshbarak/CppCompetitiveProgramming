#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e18
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1000000007


ll dp[405][405];
ll sum[405][405];

ll slimes(vector<ll> &arr, ll i, ll j) {
    if(i==j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    ll mincost = MAX;
    for(ll k=i;k<j;k++) {
        mincost = min({mincost, slimes(arr,i,k) + slimes(arr, k+1,j) + sum[i][j]});
    }
    return dp[i][j] = mincost;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n;
    cin>>n;
    vector<ll> arr(n+1);
    for(ll i=1;i<=n;i++)
        cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    // precomputing the sum:-
    for(ll i=1;i<=n;i++) {
        for(ll j=i;j<=n;j++)
            sum[i][j] = arr[j] + ((i==j) ? 0 : sum[i][j-1]);
    }

    cout << slimes(arr,1,n);

return 0;
}
