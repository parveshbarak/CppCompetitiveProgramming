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
        ll x,y,n=1,i;
        cin >> x >> y;

        // check if x+y is a square number (total pair = n*n)
        while(n*n < x+y)
            n++;
        if(n*n != x+y) {
            cout << "NO\n";
            continue;
        }

        //Handling Corner case of x+y=1
        if(n==1) {
            if(x==1) {
                cout << "YES\n";
                cout << 1 << "\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }

        ll even=1, odd=n-1;
        bool poss = false;

        while(odd >= 1) {
            ll odd_pairs = even*odd*2;
            if(odd_pairs==y) {
                poss = true;
                break;
            }
            even++; odd--;
        }

        if(!poss) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        cout << n << odd << even << "\n";

        for(ll i=1;i<=odd;i++)
            cout << 1 << " " << i+1 << "\n";

        for(ll i=1;i<even;i++)
            cout << 2 << " " << odd+i+1 << "\n";

    }
	return 0;
}

