#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t; cin >> t;
    while(t--) {
        ll k,n,s;
        cin >> n >> k >> s;
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin >> arr[i];

        vector<ll> idx; vector<ll> val;

        for(ll i=0;i<n;) {
            ll sum=0,ct=-1;
            // idx.push_back(i);
            while(sum<=s) {
                sum+=arr[i];
                i++; ct++;
            }
            i = i-ct;
            val.push_back(ct);
        }

        // for(int i=0;i<val.size();i++) 
        //     cout << val[i] << " ";
        // cout << "\n";

        int max_val = 0, max_idx;
        for(int i=0;i<n;i++) {
            ll sx=0,ch=0;
            for(ll j=i;((j<n)&&ch<k);) {
                sx += val[j];
                j+=val[j];
                ch++;
            }
            if(max_val < sx) {
                max_val = sx;
            }
        }

        cout << max_val << "\n";

    }
    
    
    return 0;
}