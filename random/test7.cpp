#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 


string complexNumberMultiply(string num1, string num2) {
    int l,m;
    for(int i=1;i<num1.length();i++) {
        if(num1[i] == '+' || num1[i] == '-') {
            l = i; break;
        }
    }
    for(int i=1;i<num2.length();i++) {
        if(num2[i] == '+' || num2[i] == '-') {
            m = i; break;
        }
    }

    string s1 = num1.substr(0,l), s2 = num1.substr(l+1,num1.length()-2);
    string s3 = num2.substr(0,m), s4 = num2.substr(m+1,num2.length()-2);
    int n1=0,n2=0,n3=0,n4=0;
    stringstream par(s1); stringstream gou(s2); stringstream han(s3); stringstream nit(s4);
    par >> n1; gou >> n2; han >> n3; nit >> n4;
    int r1,r2,r3,r4,r5,r6;
    r1 = n1*n3; r2 = n1*n4; r3 = n2*n3; r4 = n2*n4;
    // cout << n1 << " " << n2 << " " << n3 << " "<< n4 << "  ";
    r5 = r1 - r4; r6 = r2+r3;
    string ans = to_string(r5) + "+" + to_string(r6) + "i";
    return ans;
}

 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s = "-3+5i";
    string s1 = "5+-3i";
    // stringstream geek(s);
    // stringstream geeks(s1);
    // int x = 0; geek >> x;
    // int y=0; geeks >> y;
    // cout << x <<  " " << y << "\n";

    string s2 = complexNumberMultiply(s,s1);
    cout << s2 << "\n";
    
    
    return 0;
}