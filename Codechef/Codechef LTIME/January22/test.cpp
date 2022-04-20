class Solution {
public:
    vector<int> maxScoreIndices(vector<int> &arr) {
        int n=arr.size();
        vector<int> left(n+1,0), right(n+1,0);
        for(int i=1;i<=n;i++){
            if(arr[i-1]==0) left[i]=left[i-1]+1;
        }
        for(int i=n-1;i>=0;i--){
            if(arr[i]==1) = right[i]=right[i+1]+1;
        }
        int mx=0; vector<int> ans;
        for(int i=0;i<=n;i++){
            int s=left[i]+right[i];
            if(s>mx){
                mx=s;
                ans={i};
            }else if(s==mx){
                ans.push_back(i);
            }
        }
        return ans;
    }
};