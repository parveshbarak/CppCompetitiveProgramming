#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t; cin >>t;
    while(t--) {
        ll n,ans=0; cin >> n;
        ll arr[n], dp[32]={0};
        for(ll i=0;i<n;i++)
            cin >>arr[i];

        for(ll i=0;i<n;i++) {
            for(ll j=0;j<32;j++) {
                if(arr[i]&(1<<j))
                    dp[j]++;
            }
        }

        for(ll j=0;j<32;j++) {
            if(dp[j]==n) {
                ans+=(1<<j);
            }
        }

        for(ll i=0;i<n;i++) {
            ll x = arr[i]^ans;
            arr[i] = x;
        }
        ll res=0;
        for(ll i=0;i<n;i++) {
            res = (res|arr[i]);
        }

        cout << ans << " " << res << "\n";
    }
    
    
    return 0;
}