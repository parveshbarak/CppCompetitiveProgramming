#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 

int search(vector<int>& nums, int target) {
    int l=0,h=nums.size()-1;
    
    while(l<=h) {
        int mid = (l+h)/2;
        cout << nums[l] << " " << nums[h] << " " << nums[mid] << " " << target << "\n";
        if(nums[mid] == target || nums[l] == target || nums[h] == target)
            return true;

        
        
        // agr low target is chota h ... ans left me hi milega
        // else ans right me hi milega
        // agr mid ki value low se bdii h tb to sidhi baat h left side sorted h otherwise right waali h
        if(nums[l]==nums[mid] && nums[h] == nums[mid]) {
            l++; h--;
        } else {
            if(nums[mid]<=nums[h]) { // yhaan se left waala part pura sorted h
                if(target>nums[mid] && target<=nums[h])    //right me ans hi hoga ans to 
                    l=mid+1;
                else    //nhii to left me hi jaao
                    h=mid-1;
            } else {  // yhaan se right waala part pura sorted h
                if(target<nums[mid] && target>=nums[l]) //  left me ans hi hoga ans to 
                    h=mid-1;
                else    // agr nhii h to sidhi baat h target mid ki value se jyada h to right me hi hoga
                    l=mid+1;
            }
        }
    }
    return false;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 2;
    vector<int> arr = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};

    bool ans = search(arr,t);
    cout << ans << "\n";
    
    
    return 0;
}