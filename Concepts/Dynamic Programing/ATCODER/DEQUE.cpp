#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1000000007


ll arr[3005];
ll dp[3005][3005];

ll deque_(ll i, ll j) {
    if(dp[i][j] != -1) return dp[i][j];
    if(i==j) return dp[i][j] = arr[i];
    return dp[i][j] = max(arr[i]-deque_(i+1,j), arr[j]-deque_(i,j-1));
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(ll i=0;i<n;i++)
        cin >> arr[i];

    cout << deque_(0,n-1);

return 0;
}
