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

    ll t;
    cin >> t;

    while(t--) {
        ll n,k,ans = 0;
        cin >> n >> k;
        map<ll,ll> mp[k];
        for(ll i=0;i<n;i++) {
            ll num; cin >> num;
            mp[i%k][num]++;
        }

        for(ll j=0;j<k;j++) {
            ll total = 0, max_c = -1;
            for(auto [num,ct] : mp[j]) {
                total += ct;
                max_c = max(max_c,ct);
            }
            c += (total - max_c);
        }

        cout << ans << "\n";
         
    }


	return 0;
}

