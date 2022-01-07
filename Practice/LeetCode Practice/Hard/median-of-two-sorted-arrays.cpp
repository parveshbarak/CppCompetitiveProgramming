#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

 
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(),m = nums2.size();
    if(n>m) {
        vector<int> swap = nums1;
        nums1 = nums2;
        nums2 = swap;
    }

    int l = 0, h = n;
    while(l<=h) {
        int part_x,part_y,mid, max_left_x,max_left_y,min_right_x,min_right_y;
        part_x = (l+h)/2;
        part_y = (n+m+1)/2 - part_x;
        max_left_x = (part_x == 0) ? INT_MIN : nums1[part_x-1];
        min_right_x = (part_x == n) ? INT_MAX : nums1[part_x];
        max_left_y = (part_y == 0) ? INT_MIN : nums2[part_y-1];
        min_right_y = (part_y == m) ? INT_MAX : nums2[part_y];

        // found the exact partition
        if(max_left_x <= min_right_y && max_left_y <= min_right_x) {
            if((n+m)%2 == 0) {
                return (max(max_left_x,max_left_y) + min(min_right_x,min_right_y))/(double)2;
            } else {
                return max(max_left_x,max_left_y)/(double)1;
            }
        }   // Condition to go the left of the nums1 array for partition
        else if(max_left_x > min_right_y) {
            h = part_x - 1;
        }   // condition to go on the right of nums array
        else {
            l = part_x + 1;
        }
    }
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int a =4,b=5;
    // double c = (a+b)/(double)2;
    // cout << c << "\n";

    vector<int> a = {1,2,3,4,5,6,7,8};
    vector<int> b = {1,2,3,4};

    double ans = findMedianSortedArrays(a,b);

    cout << ans << "\n";
    
    
    return 0;
}