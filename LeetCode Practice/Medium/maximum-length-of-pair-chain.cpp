#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end()); 
    int j = 0,count = 1;
    for(int i=1; i<pairs.size();i++){
        if(pairs[i][0] > pairs[j][1]){
            count++;
            j=i;
        }
        else {
            if(pairs[i][1] < pairs[j][1])
                j = i;
        }
    }
    
    return count; 
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}