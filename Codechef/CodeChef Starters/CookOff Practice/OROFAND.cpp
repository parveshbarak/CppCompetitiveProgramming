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
        ll n,k,ans=0;
        cin >> n >> k;
        ll arr[n+1];
        for(ll i=1;i<=n;i++)
            cin >> arr[i];

        int freq[32] = {0};
        for(ll i=1;i<=n;i++) {
            bitset<32> b(arr[i]);
            for(ll j=0;j<32;j++)
                freq[31-j] += b[j];
        }

        for(int i=0;i<32;i++) {
            if(freq[31-i]>0)
                ans += pow(2,i);
        }

        cout << ans << "\n";

        while(k--) {
            ll x,v,ans = 0;
            cin >> x >> v;
            bitset<32> a(arr[x]);
            for(ll j=0;j<32;j++)
                freq[31-j] -= a[j];
            arr[x] = v;
            bitset<32> b(arr[x]);
            for(ll j=0;j<32;j++)
                freq[31-j] += b[j];

            for(int i=0;i<32;i++) {
                if(freq[31-i]>0)
                    ans += pow(2,i);
            }

            cout << ans << "\n";

        }
        
    }

	return 0;
}

