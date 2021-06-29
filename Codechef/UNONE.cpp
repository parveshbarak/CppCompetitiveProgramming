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
        ll n;
        cin >> n;
        vector<ll> odd,even;
        for(ll i=0;i<n;i++) {
            ll x; cin >> x;
            if(x%2==0) {
                even.push_back(x);
            }
            else {
                odd.push_back(x);
            }
        }
        for(ll i=0;i<even.size();i++)
            cout << even[i] << " ";

        for(ll i=0;i<odd.size();i++)
            cout << odd[i] << " ";

        cout << "\n";
    }
    
    
    return 0;
}