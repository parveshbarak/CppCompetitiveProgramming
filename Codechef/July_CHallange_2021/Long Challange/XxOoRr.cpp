#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 

int get_ceil(int x, int k) {
    if(x==0)
        return 0;
    int a = x/k;
    int b = (x-1)/k;
    if(a==b)
        return a+1;
    else
        return a;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)     {
        int n,k;
        cin >> n >> k;
        vector<int> bits(32,0);
        for(int i=0;i<n;i++) {
            int x;
            cin >> x;
            for(int j=0;j<32;j++) {
                if(x&(1<<j))
                    bits[j] += 1;
            }
        }
        int ans = 0;
        for(int i=0;i<32;i++)
            ans += get_ceil(bits[i],k);
        cout << ans <<"\n";
    }
    
    
    
    return 0;
}