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
        ll n;
        cin >> n;
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin >> arr[i];

        bool flag = false;
        for(ll i=0;i<n-1;i++) {
            if(arr[i] < arr[i+1])
                flag = true;
        }

        if(flag)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
        
    }
    return 0;
}