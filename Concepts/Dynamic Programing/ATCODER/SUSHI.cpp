#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1000000007

double dp[302][302][302];

double sushi(ll x, ll y, ll z, ll n) {
    if(x < 0 || y < 0 || z < 0) return 0;   // If any of these get negetive values........
    if(x==0 && y==0 && z==0) return 0;  //base case....
    if(dp[x][y][z] > -0.9)       // becoz I have set dp values to -1
        return dp[x][y][z];

    double exp = n+ x*sushi(x-1,y,z,n) + y*sushi(x+1,y-1,z,n) + z*sushi(x,y+1,z-1,n);
    return dp[x][y][z] = exp/(x+y+z);
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n,i,one=0,two=0,three=0;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(i=0;i<n;i++) {
        ll x;
        cin >> x;
        if(x==1) one++;
        else if(x==2) two++;
        else three++;
        
    }
    cout << fixed << setprecision(10) << sushi(one,two,three,n);

return 0;
}
