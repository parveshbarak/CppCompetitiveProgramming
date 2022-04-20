#include<bits/stdc++.h>
using namespace std;
 
 
int back(vector<int>&arr, int idx, int k) {
    int n = arr.size();
    if(idx >= n) return 0;
    int ans = INT_MAX;
    for(int i=idx;i<n;i++) {
        vector<int> temp(k,0);
        int l=0;
        for(int j=i;j<i+k;j++) {
            temp[l++] = arr[j%n];
            arr[j%n] = 0;
        }
        int sum = 0;
        for(int i=0;i<n;i++) sum += arr[i];
        ans = min(ans,sum + back(arr,(i+k),k));
        l=0;
        for(int j=i;j<i+k;j++) {
            arr[j%n] = temp[l++];
        }
    }
    return ans;
}

int main() {
    int n,k; cin >> n >> k;
    vector<int> arr(n);
    int ans = 0, sum = 0;
    for(int i=0;i<n;i++) cin >> arr[i], sum += arr[i];
    // while(sum>0) {
    //     int mx = 0,idx;
    //     for(int i=0;i<n;i++) {
    //         int x = 0;
    //         for(int j=i;j<k+i;j++) x += arr[j%n];
    //         if(x> mx)  mx = x, idx = i;
    //     }
    //     // cout << mx << " ";
    //     sum -= mx;
    //     ans += sum;
    //     for(int i=idx;i<idx+k;i++) arr[i%n] = 0;
    //     for(int i=0;i<n;i++) cout << arr[i] << " ";
    //     cout << "\n";
    // }
    // cout << ans << "\n";
    cout << back(arr,0,k) << " ";
    return 0;
}