#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
int numComponents(ListNode* head, vector<int>& nums) {
    unordered_set<int> us(nums.begin(), nums.end());
    ListNode* h = head; int ct = 0;
    while(h) {
        if(us.find(h->val) != us.end() && (!(h->next) || us.find(h->next->val) == us.end())) 
            ct++;
        h = h->next;
    }
    return ct;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}