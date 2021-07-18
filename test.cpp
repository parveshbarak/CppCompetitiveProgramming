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
        for(ll i=0;i<n;i++) 
            cin >> arr[i];

        sort(arr,arr+n);
        ll ans = INT_MAX;
        bool flag = true;
        for(ll i=0;i<n;i++) {
            if(flag) {
                ll diff = (arr[i+1] ^ arr[i]);
                // cout << diff << "  ";
                ans = min(ans,diff);
                if(diff==0) {
                    flag=false;
                }
            }
        }

        
        cout << ans << "\n";
    }
    
    
    return 0;
}