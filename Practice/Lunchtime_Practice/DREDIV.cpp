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
     while (t--)
    {
        ll n,k;
        cin >> n >> k;
        while(k%2 == 0) {
            k = k/2;
        }
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin >> arr[i];

        bool flag = true;
        for(ll i=0;i<n;i++) {
            if(arr[i]%k != 0) {
                flag = false;
            }
        }

        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}