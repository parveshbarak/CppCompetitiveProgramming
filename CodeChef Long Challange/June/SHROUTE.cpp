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
        ll n,m,i,j;
        cin >> n >> m;
        ll A[n]; ll B[m]; ll Front[n]; ll Last[n]; ll ans[n];
        for(i=0;i<n;i++)
            cin >> A[i];
        for(i=0;i<m;i++)
            cin >> B[i];
        
        (A[0] == 0 ) ? Front[0] = MAX : Front[0] = 0; 
        for(i=1;i<n;i++) {
            if(A[i] != 0)
                Front[i] = 0;
            else {
                if(A[i-1] == 2) {
                    ll count = 1;
                    for(j=i-1;(j > -1 & (Front[j]<=0 & A[j] != 1)); j--)
                        count++;
                    if(j == -1)
                        Front[i] = MAX;
                    else
                        Front[i] = Front[i-count] + count;
                }
                else
                    Front[i] = Front[i-1]+1;
            }
        }
        
        (A[n-1] == 0 ) ? Last[n-1] = MAX : Last[n-1] = 0;
        for(i=n-2;i>=0;i--) {
            if(A[i] != 0)
                Last[i] = 0;
            else {
                if(A[i+1] == 1) {
                    ll count = 1;
                    for(j=i+1;( j<n & (Last[j]<=0 & A[j] != 2)); j++)
                        count++;
                    if(j==n)
                        Last[i] = MAX;
                    else    
                        Last[i] = Last[i+count] + count;
                }
                else
                    Last[i] = Last[i+1]+1;
            }
        }

        Front[0] = 0;
        
        for(i=0;i<n;i++) {
            ans[i] = min(Front[i], Last[i]);
        }

        for(i=0;i<n;i++) {
            cout << Front[i] << "  ";
        }
        cout << "\n";

        for(i=0;i<n;i++) {
            cout << Last[i] << "  ";
        }
        cout << "\n";
        
        // for(i=0;i<m;i++) {
        //     if(ans[B[i]-1] >= MAX)
        //         cout << -1 << " ";
        //     else
        //         cout << ans[B[i]-1] << " ";
        // }
        // cout << "\n";
        
    }
    
    return 0;
}