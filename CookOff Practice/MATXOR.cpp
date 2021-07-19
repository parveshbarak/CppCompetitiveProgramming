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
        ll n,m,k,ans = 0;
        cin >> n >> m >> k;
        for(ll i=1;i<=n+m;i++) {
            if(i<=n) {
                ll freq = min(i,m);
                if(freq%2 != 0)
                    ans ^= (k+i+1);
            }
            else {
                ll freq = min(n,(m+n-i));
                if(freq%2 != 0)
                    ans ^= (k+i+1);
            }
        }

        cout << ans << "\n";

    }
	return 0;
}

