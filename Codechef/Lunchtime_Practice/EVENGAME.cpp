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
        ll ans,odd=0;
        for(ll i=0;i<n;i++) {
            ll x;
            cin >> x;
            if(x%2!=0)
                odd++;
        }

        if(odd%2==0)
            cout << "1" << "\n";
        else
            cout << "2" << "\n";

    }

return 0;
}
