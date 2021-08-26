#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
string make_binary(num,m) {
    string str(m);
    int i = m-1;
    while(num>0) {
        int x = num%2;
        num /= 2;
        if(x==1)
            str[i] = '1';
        else
            str[i] = '0';
        i--;
    }
    for(int j=0;j<i;j++)
        str[i] = '0';

    return str;
}

string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size();
    int m = nums[0].length();
    unordered_map<string,int> binary(n);
    for(int i=0;i<n;i++) {
        binary.insert(nums[i]);
    }

    for(int i=0;i<=n+1;i++) {
        string str = make_binary(i,m);
        if(binary.find(str) == binary.end())
            return str;
    }

    return " ";
        
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}