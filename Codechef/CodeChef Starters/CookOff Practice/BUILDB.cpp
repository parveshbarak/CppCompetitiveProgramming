#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n,r,i,ans = 0,x=0;
        cin >> n >> r;
        vector<int> A(n), B(n);
        for(i=0;i<n;i++)
            cin >> A[i];
        for(i=0;i<n;i++)
            cin >> B[i];
            
        for(i=0;i<n;i++) {
            x += B[i];
            ans = max(x,ans);
            if(i != n-1)
                x -= r*(A[i+1]-A[i]);
            if(x < 0)
                x = 0;
        }
        std::cout <<  ans << std::endl;
    }
	return 0;
}
