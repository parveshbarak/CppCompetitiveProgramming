#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
string Multiply(string s, int a) {
    // int a = (int)s1[0] - 48;
    int c = 0; string ans = s;
    for(int i=ans.length()-1;i>=0;i--) {
        int b = (int)s[i] - 48;
        int res = a*b+c;
        ans[i] = '0' + (res%10);
        c = res/10;
    }
    char prep = '0' + c;
    ans = prep + ans;

    return ans;
}

string add(string s, string ans) {
    string result = ans;
    int n = s.length() - 1; 
    int m = ans.length() - 1;
    int i = n, j=m, c=0;
    while(j>=0 && i>=0) {
        int a = (int)s[i] - 48; i--;
        int b = (int)ans[j] - 48; j--;
        int res = a+b+c;
        result[i] = '0' + (res%10);
        int c = res/10;
    }
    result[i-1] = '0' + c;
    return result;
}

string multiply(string num1, string num2) {
    int n = num1.length(), m = num2.length();
    string ans(10,'0');
    if(n>m) {
        for(int i=0;i<m;i++) {
            int a = (int)num2[i] - 48;
            string s = Multiply(num1,a);
            ans = add(s,ans);
        }
    } else {
        for(int i=0;i<n;i++) {
            int a = (int)num1[i] - 48;
            string s = Multiply(num2,a);
            ans = add(s,ans);
        }
    }

    return ans;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1,s2;
    cin >> s1 >> s2;

    string ans = multiply(s1,s2);
    cout << ans << "\n";
    
    return 0;
}