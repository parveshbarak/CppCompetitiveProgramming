#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1000000007


double dp[3005][3005];  //dp[i][j] -> prob of geeting atleast j heads in in coins.

double coins(vector<double>& arr, int i, int x) {
    if(x==0) return 1;
    if(i==0) return 0;
    if(dp[i][x] > -0.9) return dp[i][x];
    return dp[i][x] = arr[i]*coins(arr, i-1, x-1) + (1-arr[i])*coins(arr, i-1,x);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,i;
    cin>>n;
    vector<double> arr(n+1);
    memset(dp, -1, sizeof(dp));
    for(i=1;i<=n;i++)
        cin>>arr[i];

    cout<<fixed<<setprecision(10)<<coins(arr,n,(n+1)/2);

    // cout << "\n\n";


    // for(ll i=0;i<=n;i++) {
    //     for(ll j=0;j<=n;j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }

return 0;
}
