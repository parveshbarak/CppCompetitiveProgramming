#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    vector<ll>stones(n);
	    for(ll i = 0;i<n;i++) cin >> stones[i];
	    vector<ll> jumps(n , 1e18);
	    jumps[0] = 0;
	    for(ll i = 0 ;i<jumps.size();i++){
	        for(ll j = i+1;j<jumps.size();j++){
	            ll d = j-i+1;
	            jumps[j] = min(jumps[i]+(d*stones[i])-stones[j],jumps[j]);
	        }
	    }
	    cout<<(jumps[n-1] < 0 ? 0: jumps[n-1])<<endl;
	}
	return 0;
}