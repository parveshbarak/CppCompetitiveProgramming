#include <bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

int firstMissingPositive(vector<int> &nums){
    int j = 0, i, ans = 0, big = 0;
    for (i = 0; i < nums.size(); i++) {
        if (nums[i] > 0)        {
            swap(nums[i], nums[j]);
            j++;
        }
    }

    for (i = 0; i < j; i++) {
        big = max(big, nums[i]);
        int idx = nums[i];
        if (idx < 0)
            idx = -1 * idx;
        idx--;
        if (idx < nums.size()) {
            nums[idx] = (nums[idx] > 0) ? -1 * nums[idx] : nums[idx];
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            ans = i + 1;
            break;
        }
    }

    if (ans == 0)
        ans = big + 1;

    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}