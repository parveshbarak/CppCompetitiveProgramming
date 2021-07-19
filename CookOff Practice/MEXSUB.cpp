#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1e9+7



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n,mex=0;
        cin >> n;
        int arr[n]; map<int,int> mp;
        for(int i=0;i<n;i++) {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        
        while(mp[mex] != 0) mex++;

        if(mex == 0) {
            cout << pow(2, n-1) << "\n";
            continue;
        }

        multiset<int> index;
        for(int i=0;i<mex;i++)
            index.insert(0);

        vector<int> dp(n+1),ind(n+1), prefdp(n+1);
        dp[0] = prefdp[0] = 1; 

        

    }
	return 0;
}

