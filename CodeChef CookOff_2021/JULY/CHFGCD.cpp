#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
 
ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while(t--) {
        ll x,y,ans=0;
        cin >> x >> y;
        if(gcd(x,y)==1) {
            if(x%2==0 && y%2==0)
                ans = 0;
            else if(x%2==0 || y%2==0)
                ans = 1;
            else
                ans = 2;
        }

        // if(gcd(x,y)==1) {
        //     if(x<y) {
        //         ll res = y%x;
        //         ans = min(res,(x-res));
        //     } else  {
        //         ll res = x%y;
        //         ans = min(res,(y-res));
        //     }
        // }

        cout << ans << "\n";
    }
    
    
    return 0;
}