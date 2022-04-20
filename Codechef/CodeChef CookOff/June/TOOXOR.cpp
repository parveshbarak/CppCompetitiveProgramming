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

    ll t;
    cin >> t;
    while(t--) {
        ll n,ct=0;
        cin >> n;
        ll arr[n];
        set<ll> s;
        for(ll i=0;i<n;i++) {
            cin >> arr[i];
            s.insert(arr[i]);
        }

        

        vector<vector<ll>> ans((3*n)+6, vector<ll>(3,0));

return 0;
}
