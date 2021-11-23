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

    int n,w;
    cin >> n >> w;
    vector<ll> weight(n,0); vector<ll> v(n,0);
    for(ll i=0;i<n;i++)
        cin >> weight[i] >> v[i];

    vector<ll> dp1(w+1,0); vector<ll> dp2(w+1,0);
    for(ll i=0;i<n;i++) {
        for(ll j=1;j<=w;j++) {
            if(j<weight[i])
                dp2[j] = dp1[j];
            else {
                dp2[j] = max({dp1[j], dp2[j], v[i]+dp1[j-weight[i]]});
            }
        }
        dp2.swap(dp1);
        dp2.clear();
    }
    cout << dp1[w];

return 0;
}
