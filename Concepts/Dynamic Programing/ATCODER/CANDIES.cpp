#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1000000007


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n,k;
    cin>>n>>k;
    ll arr[n+1];
    ll dp[n+1][k+1];
    memset(dp, 0, sizeof(dp));
    for(ll i=1;i<=n;i++)
        cin >> arr[i];

    //base case :
    for(ll j=0;j<=k;j++){
        dp[1][j] = (j>arr[1]) ? 0 : 1;
    }
    //other cases
    for(ll i=2;i<=n;i++) {
        for(ll j=0;j<=k;j++) {
            if(j==0)
                dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = (MOD + (dp[i-1][j]) + (dp[i][j-1]) - ((j-arr[i]-1 >= 0) ? dp[i-1][j-arr[i]-1] : 0))%MOD;
            }
        }
    }
    // for(ll i=0;i<=n;i++)
    // {
    //     for(ll j=0;j<=k;j++)
    //         cout << dp[i][j] <<" ";
    //     cout << "\n";
    // }
    cout << dp[n][k];

return 0;
}
