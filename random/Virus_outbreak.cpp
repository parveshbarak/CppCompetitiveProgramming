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
    ll N = 1000006;
    vector<ll> primes(N,1);

    for(ll i=2;i*i<=N;i++) {
        if(primes[i] == 1) {
            for(ll j=i*i;j<=N;j+=i) {
                primes[j] = 0;
            }
        }
    }
    while(t--) {
        ll r,l,p1=0,p2=0;
        cin >> l >> r;
        for(ll i=l;i<=r;i++) {
            if(primes[i] == 1) {
                p1 = i;
                break;
            }
        }
        for(ll i=r;i>=l;i--) {
            if(primes[i] == 1) {
                p2 = i;
                break;
            }
        }

        if(p1==0 && p2==0) {
            cout << "-1\n";
        }
        else if(p2 == p1) {
            cout << "0\n";
        }
        else {
            cout << (p2-p1) << "\n";
        }
    }

return 0;
}
