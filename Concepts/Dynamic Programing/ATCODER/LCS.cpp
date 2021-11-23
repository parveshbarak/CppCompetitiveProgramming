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

	string s1,s2,s;
	cin >> s1 >> s2;

	ll n = s1.length(), m = s2.length();
	vector<vector<ll>> dp(n+1, vector<ll> (m+1,0));
	// base case :-  0th row and column are set to zero :- already set.
	//other cases :-
	for(ll i=1;i<=n;i++) {
		for(ll j=1;j<=m;j++) {
			if(s1[i-1] == s2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	// Now to know the exact substring we traverse the dp backward as follows:-
	ll i=n, j=m;
	while(i>0 && j>0) {
		if((dp[i][j] > dp[i-1][j]) && (dp[i][j] > dp[i][j-1])) {
			s.push_back(s1[i-1]);
			i--; j--;
		}
		else {
			if(dp[i-1][j] > dp[i][j-1])
				i--;
			else
				j--;
		}
	}

	// reversing the string and then printing it:-
	reverse(s.begin(), s.end());
	cout << s;

return 0;
}
