#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 

bool isLCS(string a,string b){
    int n=a.length(), m=b.length();
    if(n>m) return false; int i=0;
    for(int j=0;j<m;j++){
        if(a[i]==b[j])
            i++;
        if(i==n)
            return true;
    }
    return false;
}

int findLUSlength(vector<string>& strs) {
    int n=strs.size();
    int ans=-1;
    for(int i=0;i<n;i++){
        bool flag=true;
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            if(isLCS(strs[i],strs[j])){
                flag=false;
                break;
            }
        }
        if(flag==true){
            int val=strs[i].length();
            ans=max(ans,val);
        }
    }
    return ans;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}