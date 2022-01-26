#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007


const ll N = 1e6+6;
ll big_arr[N] = {0};
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll arr[n];
        memset(big_arr,0,sizeof(big_arr));
        for(ll i=0;i<n;i++) {
            ll x; cin >> x;
            arr[i] = x;
            big_arr[x]++;
        }

        // for(ll i=0;i<7;i++)
        //     cout << big_arr[i] <<" ";
        // cout << "\n";

        ll sub=0;
        for(ll i=0;i<N;i++) {
            ll z = big_arr[i];
            sub += z*(z-1);
        }

        // cout << sub << " ";

        ll ans = (n*(n-1) - sub);

        cout << ans << "\n";
    }
    
    
    return 0;
}