#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    for(int i=0;i<n;i++) {
        int idx = nums[i];
        if(idx < 0)
            idx *= -1;
        idx--;
        nums[idx] *= -1;
    } 
    for(int i=0;i<n;i++) {
        if(nums[i] > 0)
            return i;
    }       
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}