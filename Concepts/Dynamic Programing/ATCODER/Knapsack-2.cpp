#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e12
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1000000007


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n,w,i,j,result=0;
    cin>>n>>w;
    vector<ll> v(n+1,0) , weights(n+1,0);
    for(i=0;i<n;i++) {
        cin >> weights[i] >> v[i];
    }
    // here for space optimization : - We can take 2 1-D dps instead of one 2-D dp.
    vector<ll> dp1(n*1000+1,INT_MAX);
    vector<ll> dp2(n*1000+1,INT_MAX);

    //baas case and initialisinf dp1
    dp1[0] = 0;
    dp1[v[0]] = weights[0];

    for(i=1;i<n;i++) {
        for(j=0;j<=n*1000;j++) {
            if(j<v[i])
                dp2[j] = dp1[j];
            else {
                dp2[j] = min(dp1[j], dp1[j-v[i]]+weights[i]);
            }
        }
        for(int k=0;k<=n*1000;k++)
        {
            dp1[k] = dp2[k];
            dp2[k] = INT_MAX;

        }
    }

    for(i=0;i<=n*1000;i++) {
        if(dp1[i] <= w)
            result = i;
    }
    cout <<result <<endl;

return 0;
}
