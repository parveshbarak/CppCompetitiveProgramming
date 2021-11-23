#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1000000007


int main() {
	int n;
	cin>>n;
	vector<vector<ll> >v(n, vector<ll> (3));
	for(auto &x:v){
		for(auto &y:x)
			cin>>y;
	}
	vector<vector<ll> >dp(n+1, vector<ll> (3));
	dp[0][0]=v[0][0];
	dp[0][1]=v[0][1];
	dp[0][2]=v[0][2];
    for(ll i=1;i<n;i++){
		for(ll j=0;j<3;j++){
			if(j==1){
			dp[i][j]=v[i][j]+max(dp[i-1][0],dp[i-1][2]);
			}
			else if(j==2){
				dp[i][j]=v[i][j]+max(dp[i-1][1],dp[i-1][0]);
			}
			else
			dp[i][j]=v[i][j]+max(dp[i-1][2],dp[i-1][1]);
		}
	}
	cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});

return 0;
}