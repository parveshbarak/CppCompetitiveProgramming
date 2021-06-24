#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1000000007



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll t;
    cin >> t;
     while (t--)
    {
        ll n;
        string s;
        cin >> n >> s;
        ll pre[n+1], suf[n+1];
        pre[0] = suf[n] = 0;
        for (ll i=1;i<=n;i++)
            pre[i]=pre[i-1]+(s[i-1]=='1');
        for (ll i=n-1;i>=0;i--)
            suf[i]=suf[i+1]+(s[i]=='0');

        ll ans=n;
        for (ll i=0;i<=n;i++)
            ans=min(ans,pre[i]+suf[i]);
        cout << ans << "\n";
    }

return 0;
}
