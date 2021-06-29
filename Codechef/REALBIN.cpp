#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        ll a,b;
        cin >> a >> b;
        if(ceil(log2(b)) == floor(log2(b))) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    
    }
    return 0;
}