#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

int videoStitching(vector<vector<int>>& clips, int time) {
    sort(clips.begin(), clips.end());
    if(clips[0][0] 1= 0)
        return -1;
    int mn = 0, mx = clips[0][1];
    for(int i=1;i<clips.size();i++) {
        if(mx >= time)
            return 
        if(clips[i][0] > mx)
            return -1;
        els
    }
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}