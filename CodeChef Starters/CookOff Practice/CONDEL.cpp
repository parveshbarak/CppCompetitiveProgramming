#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1e9+7


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        ll n,k;
        cin >> n >> k;
        vector<ll> arr(n+1,0), cost(n+1,0);
        for(ll i=1;i<=n;i++) {
            cin >> arr[i];
            cost[i] = cost[i-1] + arr[i];
        }
        ll total_ones = cost[n];
        ll min_ones = k;

        for(ll i=k;i<=n;i++) {
            ll ones = cost[i] - cost[i-k];
            min_ones = min(min_ones, ones);
        }

        ll ans = (min_ones*(min_ones+1)/2) + (total_ones-min_ones);
        cout <<  ans << endl;
    }
	return 0;
}

