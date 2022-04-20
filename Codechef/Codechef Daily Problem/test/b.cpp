#include<bits/stdc++.h>
using namespace std;
 
 

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int ct1=0, ct2 = 0;
    int i=0;
    while(i<n) {
        int x = arr[i];
        while(i<n-1 && x!=0) x^= arr[++i];
        if(x!=0) ct1 = 0;
        else ct1++;
        i++;
    }
    i = n-1;
    while(i>=0) {
        int x = arr[i];
        while(i>0 && x!=0) x ^= arr[--i];
        if(x!=0) ct2 = 0;
        else ct2++;
        i--;
    }
    cout << max(ct1,ct2) << "\n";
    
    return 0;
}