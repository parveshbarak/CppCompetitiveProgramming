#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

const ll N = 100002;

ll createPalindrome(ll x, ll b) {
	ll n = x;
	ll palin = x;
	n /= b;
    
	while (n > 0)
	{
		palin = palin * b + (n % b);
		n /= b;
	}
	return palin;
}

ll power(long long x, ll y)
{
    ll res = 1;
    x = x % MOD; 
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % MOD;
        y = y>>1; // y = y/2
        x = (x*x) % MOD;
    }
    return res;
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<ll> arr;
    vector<ll> pre(N,0);

    ll i = 0,number;
    while (i<N) {
        number = createPalindrome(i,10);
        arr.push_back(number);
        i++;
    }

    for(ll i=1;i<arr.size();i++) {
        pre[i] = pre[i-1]+arr[i];
    }

    ll t;
    cin >> t;
    while (t--) {
        ll l,r,ans;
        cin >> l >> r;
        ans = power(arr[l],pre[r]-pre[l]);
        cout << ans%MOD << "\n";

    }
    
    
    
    return 0;
}