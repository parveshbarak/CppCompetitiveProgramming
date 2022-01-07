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

    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ans,even=0,odd=0;
        for(ll i=0;i<n;i++) {
            ll x;
            cin >> x;
            if(x%2==0)
                even++;
            else
                odd++;
        }

        ans = (odd > even) ? even : odd;
        cout << ans << "\n";

    }

return 0;
}
