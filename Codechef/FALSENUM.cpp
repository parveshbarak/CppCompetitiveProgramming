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
        string num,ans;
        cin >> num;
        if(num[0] != '1') {
            ans = "1";
            ans.append(num);
            cout << ans << "\n";
        }
        else {
            ans = "0";
            num.insert(1,ans);
            cout << num << "\n";
        }

    }
    
    
    return 0;
}