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
        string s;
        cin >> s;
        ll n = s.length();
        vector<ll> arr(26,0);
        for(ll i=0;i<n;i++) {
            int x = int(s[i]) - 97;
            arr[x]++;
        }
        
        ll odds=0, evens=0;
        for(ll i=0;i<26;i++) {
            if(arr[i]%2 != 0)
                odds++;
        }

        // cout << odds << "  " << evens << "\n";
        evens = (n - odds)/2;
        if(evens >= odds)
            cout << "YES"<<endl;
        else    
            cout << "NO"<<endl;
    }
    return 0;
}