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

    int n,x,y;
    cin >> n;
    vector<int> h(n,0);
    vector<int> dp(n,0);
    for(int i=0;i<n;i++)
        cin >> h[i];
    //base case:-
    dp[0] = 0;
    dp[1] = (h[1]-h[0]>=0) ? h[1]-h[0] : h[0]-h[1];
    //other cases:-
    for(int i=2;i<n;i++){
        x = (h[i]-h[i-1] >= 0) ? h[i]-h[i-1] : h[i-1]-h[i];
        y = (h[i]-h[i-2] >= 0) ? h[i]-h[i-2] : h[i-2]-h[i];
        dp[i] = min(dp[i-1]+x , dp[i-2]+y);
    }
    cout << dp[n-1] << "\n";

return 0;
}