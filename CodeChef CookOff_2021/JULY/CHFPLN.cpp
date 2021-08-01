#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];

        // vector<pair<ll>> occ;

        sort(arr,arr+n);
        ll ans=0;
        for(ll i=0;i<n;) {
            ll x = arr[i],ct=0;
            while(arr[i]==x) {
                ct++; i++;
            }
            // cout << ct << " ";
            ans += min(ct,(arr[i]-1));
            // cout << ans << "  ";
        }

        cout << ans << "\n";

    }
    
    
    return 0;
}