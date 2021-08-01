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
    while(t--)  {
        ll n; cin >> n;
        ll a[n], b[n];
        for(ll i=0;i<n;i++) {
            ll l; cin >> l;
            a[i] = l%n;
        }
        for(ll i=0;i<n;i++) {
            ll l; cin >> l;
            b[i] = l%n;
        }

        
        vector<ll> idx;
        ll minimum = n-1; bool flag =true; ll id1;
        for(ll i=0;i<n;i++) {
            minimum = min(minimum,(a[0]+b[i])%n);
        }
        for(ll i=0;i<n;i++) {
            if(minimum == (a[0]+b[i])%n) {
                idx.push_back(i);
            }
        }

        if(idx.size()==1) {
            flag = false;
            id1 = 0;
        }

        for(ll i=0;i<idx.size();i++)
            cout << idx[i] << " ";
        cout << "\n";

        
        for(ll j=1;(j<n)&&flag;j++) {
            idx.resize(0); minimum = n-1;
            for(ll i=0;i<n;i++) {
                minimum = min(minimum,(a[j]+b[i])%n);
            }
            for(ll i=0;i<n;i++) {
                if(minimum == (a[j]+b[i])%n) {
                    idx.push_back(i);
                }
            }
            if(idx.size()==1) {
                flag = false;
                id1 = j;
            }
        }

        ll id2 = idx.front();

        for(ll i=0;i<n;i++)
            cout << a[i] << " ";
        cout << "\n";

        for(ll i=0;i<n;i++)
            cout << b[i] << " ";
        cout << "\n";

        cout << id1 << " " << id2 << " ";
        if(id2>id1) {
            
        }
        else
            id2 -= id1;

        for(ll i =0;i<n;i++){
			if  (k == n) k =0;
			c[i] = (a[i]+b[k])%n;
			k++;
		}


    }
    
    
    return 0;
}