#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1e9+7



const ll size  = 1000000000000+1;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        ll d,D,P,Q,x,ans = 0;
        cin >> D >> d >> P >>Q;
        ans += D*P;
        x = D/d;
        ans += (d*Q*x*(x-1))/2;
        ans += (D-(d*x))*x*Q;
        cout << ans <<endl;
    }
    
    return 0;
}