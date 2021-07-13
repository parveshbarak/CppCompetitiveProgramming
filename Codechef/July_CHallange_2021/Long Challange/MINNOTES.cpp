#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while(t--) {
        ll n,ans=MAX,sum=0;
        cin >> n;
        ll arr[n];
        for(ll i=0;i<n;i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        vector<ll> pre(n,0);
        vector<ll> suf(n,0);

        if(n==1)
            ans = 1;
        else {

            pre[0] = arr[0]; suf[n-1] = arr[n-1];
            for(ll i=1;i<n;i++) {
                pre[i] = gcd(pre[i-1],arr[i]);
            }
            for(ll i=n-2;i>=0;i--) {
                suf[i] = gcd(suf[i+1],arr[i]);
            }

            for(ll i=0;i<n;i++){
                ll g;
                if(i==0)
                    g = suf[i+1];
                else if(i==n-1)
                    g = pre[i-1];
                else {
                    g = gcd(suf[i+1],pre[i-1]);
                }
                ll res = (sum-arr[i]+g)/g;
                ans = min(ans,res);
                // cout << ans  << " " <<  g  << " " << sum << " " << arr[i] <<"    ";
            }
        }
        cout << ans << "\n";
    }
    
    
    return 0;
}