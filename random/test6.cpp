#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 

class Solution {
public:
    string adding(string num1 , string num2){
        if(num1.length() <num2.length()){
            int zeroes = num2.length()-num1.length();
            string zero ="";
            while(zeroes){
                zero+=48;
                zeroes--;
                }
            num1 = zero+num1;
            }
        
        else{
            int zeroes = num1.length()-num2.length();
            string zero ="";
            while(zeroes){
                zero+=48;
                zeroes--;
            }
            num2 = zero+num2;
        }
        int carry = 0;
        string result ="";
        for(int i =num1.size()-1;i>=0;i--){
            int value = (num1[i]-'0')+(num2[i]-'0') + carry;
            result += (value%10)+48 ;
            carry = value/10;
            
        }
        if (carry) result +=carry+48;
        reverse(result.begin(),result.end());
        return result;
        
    }
    string mult(string num1 , int key,int zero){
        int carry = 0;
        string result = "";
        for(int i = num1.size()-1;i>=0;i--){
            int value = num1[i]-'0';
         
            value = (value *key)+carry;
            carry = value/10;
            value = value%10;
            result +=value+48;
        }
        if(carry)
            result+=carry+48;
        reverse(result.begin(),result.end());
        while(zero>0){
            result+=48;
            zero--;
        }
        return result;
    }
    string multiply(string num1, string num2) {
        if(num1.length() == 1 and num1[0] =='0') return "0";
        if (num2.length() == 1 and num2[0] =='0') return "0";
        string result = mult(num1 , num2[num2.size()-1]-'0',0);
        int k = 1;
        for(int i = num2.size()-2;i>=0;i--,k++){
            string mu = mult(num1,num2[i]-'0',k);
            result = adding(result,mu);
        }
        return result;
    }

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

        string s1 = num1.substr(0,l-1), s2 = num1.substr(l+1);
        string s3 = num2.substr(0,m-1), s4 = num2.substr(m+1);
        char one,two,three,four;
        string sf1,sf2,sf3,sf4;
        if(s1[0] == '+' || s1[0] == '-') {
            one = s1[0];
            sf1 = s1.substr(1);
        } else if(s2[0] == '+' || s2[0] == '-') {
            two = s2[0];
            sf2 = s2.substr(1);
        }if(s1[0] == '+' || s1[0] == '-') {
            one = s1[0];
            sf1 = s1.substr(1);
        }if(s1[0] == '+' || s1[0] == '-') {
            one = s1[0];
            sf1 = s1.substr(1);
        }

    }
};
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}