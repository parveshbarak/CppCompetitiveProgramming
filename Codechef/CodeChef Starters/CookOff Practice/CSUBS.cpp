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

    ll t;
    cin >> t;

    ll N = 1000006;
    vector<bool> primes(N, true);
    for(ll i=2;i*i<N;i++) {
        for(ll j=i*i;j<N;j+=i) {
            if(primes[i]==true)
                primes[j] = false;
        }
    }

    vector<ll> ans(N,0); ll count = 0;
    for(ll i=5;i<N;i++) {
        if(primes[i] && primes[i-2])
            count++;
        ans[i] = count;
    }

    while(t--) {
        ll n;
        cin >> n;
        cout << ans[n] << "\n";
    }


	return 0;
}

