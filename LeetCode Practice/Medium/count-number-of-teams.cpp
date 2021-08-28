#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
int numTeams(vector<int>& rating) {
    int sb=0,bs=0;
    for(int i=1;i<rating.size()-1;i++) {
        int lbig=0,rsmall=0,lsmall=0,rbig=0;
        for(int j=0;j<i;j++) {
            if(rating[i] > rating[j])
                lsmall++;
            else
                lbig++;
        }
        for(int j=i+1;j<rating.size();j++) {
            if(rating[i] < rating[j])
                rbig++;
            else
                rsmall++;
        }
        sb += lsmall*rbig; 
        bs += lbig*rsmall;
    }
    return sb+bs;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}