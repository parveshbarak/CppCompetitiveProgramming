#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
//#define MOD 1e9+7

int power(ll x, ll y, ll MOD) {
    int res = 1;
    x = x%MOD;
    if(x == 0) 
        return 0;
    
    while(y>0)
    {
        if(y & 1)   // y == odd
            res = (res*x) % MOD;
        // y must be even now
        y = y >> 1;      // y/2;
        x = (x*x)%MOD;
    }
    return res;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        ll n,m,a,ans,MOD = 1e9+7;
        cin >> n >> m;
        a = power(2,n,MOD) - 1;
        ans = power(a,m,MOD);
        ans = ans % MOD;
        cout << ans << endl;
    }
    
    return 0;
}