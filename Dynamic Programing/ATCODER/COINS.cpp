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

    ll n; double res=0.0;
    cin >> n;
    vector<double> p(n);
    for(ll i=0;i<n;i++)
        cin >> p[i];

    vector<vector<double>> dp(n+1,vector<double> (n+1,0));
    //base case :-
    dp[0][0] = 1;
    //other cases:-
    for(ll i=1;i<=n;i++) {
        dp[i][0] = (1-p[i-1]);
        for(ll j=1;j<=n;j++) {
            dp[i][j] = ((dp[i-1][j])*(1-p[i-1])) + ((dp[i-1][j-1])*(p[i-1]));
        }
    }

    for(ll i=0;i<=n;i++) {
        for(ll j=0;j<=n;j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }

    for(ll i=(n/2);i<n;i++) {
        res += dp[n][i+1];
    }

    cout<<fixed<<setprecision(10)<<res;

return 0;
}
