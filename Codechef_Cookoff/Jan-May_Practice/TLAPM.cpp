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

    ll arr[1001][1001];
    arr[1][1] = 1;
    for(ll i=2;i<1001;i++)
        arr[i][1] = arr[i-1][1] + i;
    
    for(ll i=1;i<1001;i++) {
        for(ll j=2; j<1001;j++)
            arr[i][j] = arr[i][j-1] + j+i-2;
    }

    while(t--) {
        ll x1,y1,x2,y2; ll sum=0;
        cin >> x1 >> y1 >> x2 >> y2;
        for(ll i=x1;i<=x2;i++) {
            sum += arr[i][y1];
        }
        for(ll i=y1+1;i<=y2;i++) {
            sum += arr[x2][i];
        }

        cout << sum << "\n";
    }


	return 0;
}

