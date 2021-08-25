#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
 
string convert(string s, int numRows) {
    if (numRows == 1) return s;
    
    string ans;
    int n = s.length();
    // int cols = 0;
    // for(int i=0;i<n;) {
    //     if(cols%(numRows-1) == 0) {
    //         i+=4;
    //     }
    //     else {
    //         i+=1;
    //     }
    //     cols++;
    // }
    // cout << n << " ";
    // cout << cols << "\n";
    // return  " ";
    vector<vector<int>> table(numRows,vector<int>(n,0));
    int k = 0,h=0;
    for(int i=0;k<n;i++) {
        if(h==0) {
            for(int j=0;j<numRows;j++) {
                table[j][i] = (int)s[k]; k++;
            }
            // h = numRows-2;
        } else {
            table[h][i] = (int)s[k]; k++;
            h--;
        }
    }

    // for(int i=0;i<numRows;i++) {
    //     for(int j=0;j<n;j++)
    //         cout << table[i][j] << " ";
    //     cout << " ";
    // }
}




int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s = convert("PAYPALISHIRING", 4);
    
    
    return 0;
}