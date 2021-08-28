// Not working !! dont know why????????

#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
    int query(int i , vector<int>bit){
        int ans = 0;
        for(;i>0;i-=i&-i){
           ans+= bit[i];
        }
        return ans;
    }
    void update(int i ,int value, vector<int> & bit){
        for(;i<bit.size();i+=i&-i) bit[i]+=value;
    }
    
    int BIT(vector<int>rating,int n ,vector<int>& greater,vector<int>&lesser){
        
        for(auto x : rating){
            update(x, 1 , greater);
        }
        int ans = 0;
        for(auto x: rating){
            int left = query(x , lesser);
            int right = query(n , greater) - query(x ,greater);
            ans+=left*right;
            update(x , 1 , lesser);
            update(x , -1 , greater);
        }
        return ans;
    }
    
    int numTeams(vector<int>& rating) {
        int i = 1;
        unordered_map<int , int> compress;
        vector<int> new_rating = rating;
        sort(new_rating.begin() , new_rating.end());
        for(int x : new_rating) compress[x] = i++;
        for(i = 0;i<new_rating.size() ;i++){
            rating[i] = compress[rating[i]];
        }
        int n = *max_element(rating.begin() , rating.end())+1;
        vector<int> lesser(n+1,0);
        vector<int> greater(n+1,0);
        int ans = BIT(rating,n,greater , lesser);
        reverse(rating.begin(),rating.end());
        fill(lesser.begin(),lesser.end(),0);
        fill(greater.begin() , greater.end() , 0);
        return ans+BIT(rating , n,greater , lesser);
    }
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}

int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        int last_diff = nums[1] - nums[0];
        int count = (last_diff != 0) ? 2 : 1;
        for (int i = 2; i < nums.length; i++) {
            int diff = nums[i] - nums[i - 1];
            if ((diff > 0 && last_diff <= 0) || (diff < 0 && last_diff >= 0)) {
                count++;
                last_diff = diff;
            }
        }
        return count;
    }