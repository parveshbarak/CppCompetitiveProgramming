#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

int jump(vector<int>& nums) {
    int n = nums.size();
    if(n == 1)  return 0;

    int prevDist = -1, curDist = nums[0] + 0, count = 0;
    for(int i = 0; i < n; i++) {
        if(i > prevDist) {
            prevDist = curDist;
            ++count;
        }

        if(prevDist >= n - 1)
            return count;

        int newPos = i + nums[i];
        if(newPos > curDist)
            curDist = newPos;
    }
    return count;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}