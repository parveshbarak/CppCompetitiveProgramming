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

    ll n,m,i,j,none;
    cin>>n>>m;
    vector<vector<ll>> dp(n+1, vector<ll>(m+1,0));
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            char x;
            cin >> x;
            if(x=='#')
                dp[i][j] = -1;
        }
    }
    //base case :-
    dp[1][1] = 1;

    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(dp[i][j] == -1)
                dp[i][j] = 0;
            else if(dp[i][j]==1) none=1;
            else 
                dp[i][j] = (dp[i-1][j]%MOD + dp[i][j-1]%MOD)%MOD;
        }
    }

    cout << dp[n][m] <<endl;


return 0;
}
