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

    int n,k,x,y;
    cin >> n >> k;
    vector<int> h(n,0);
    vector<int> dp(n,0);
    for(int i=0;i<n;i++)
        cin >> h[i];
    //base case:-
    dp[0] = 0;
    dp[1] = ((h[1]-h[0]>=0) ? (h[1]-h[0]) : (h[0]-h[1]));
    //other cases:-
    for(int i=2;i<n;i++){
        dp[i] = dp[i-1] + ((h[i]-h[i-1] >= 0) ? (h[i]-h[i-1]) : (h[i-1]-h[i]));
        for(int j=2;(j<=k & j<=i);j++) {
            y = dp[i-j] + ((h[i]-h[i-j] >= 0) ? (h[i]-h[i-j]) : (h[i-j]-h[i]));
            dp[i] = min(y , dp[i]);
        }
    }
    cout << dp[n-1] << "\n";

return 0;
}
