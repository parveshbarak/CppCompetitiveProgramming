#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    cin >> t;
    while(t--) {
        ll a,b,c,d,k,dist=0;
        cin >> a >> b >> c >> d >> k;
        dist += (d-b > 0) ? (d-b) : (b-d);
        dist += (c-a > 0) ? (c-a) : (a-c);

        if((k-dist)%2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}