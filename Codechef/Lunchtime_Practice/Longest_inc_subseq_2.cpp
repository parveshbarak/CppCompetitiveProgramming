// Note :-> 
//         *** Using binary search to Optimize searching in N time to logN time


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

    ll n;
    cin >> n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin >> arr[i];

    vector<ll> dp(n+1,MAX);
    dp[0] = -MAX;

    // d[i] will be the element at which a subsequence of length i terminates.
    // If there are multiple such sequences, then we take the one that ends in the smallest element.

    for(ll i=0;i<n;i++) {
        ll j = upper_bound(dp.begin(), dp.end(),arr[i]) - dp.begin();
        if(dp[j-1]<arr[i] && arr[i]<dp[j])
            dp[j] = arr[i];
    }

    ll ans = 0;
    for(ll i=0;i<=n;i++) {
        if(dp[i]<MAX)
            ans = i;
    }
    cout << ans << "\n";

return 0;
}
