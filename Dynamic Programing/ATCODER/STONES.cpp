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
    vector<ll> arr(n);
    for(ll i=0;i<n;i++)
        cin >> arr[i];
    vector<bool> dp(k+1,false);
    for(ll i=1;i<=k;i++) {
        for(ll j=0;j<n;j++) {
            if(arr[j] > i) continue;
            if(dp[i-arr[j]] == false)
                dp[i] = true;
        }
    }

    if(dp[k])
        cout << "First";
    else
        cout << "Second";

return 0;
}
