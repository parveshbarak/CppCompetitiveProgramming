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
        int x,y,X,Y,ans=0;
        cin >> x >> y >> X >> Y;
        if(X%x==0)
            ans += X/x;
        else    
            ans += X/x+1;
        if(Y%y==0)
            ans += Y/y;
        else    
            ans += Y/y+1;
        cout << ans << endl;
    }
    
    return 0;
}