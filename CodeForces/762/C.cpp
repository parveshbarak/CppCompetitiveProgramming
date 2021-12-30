#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,ct=0,k=0;
        cin>>a>>b;
        vector<long long> v;
        while(a!=0  && b!=0){
            if(b%10>=a%10){v.push_back(b%10-a%10); b=b/10;}
            else{
                if((b%100-a%10)>9 || (b%100-a%10)<0){cout<<-1<<endl; k++; break;}
                v.push_back(b%100-a%10);
                b=b/100;
            }
            a=a/10;
        }if(k==0){if(a!=0){cout<<-1<<endl;}
        else{
            while(b!=0){
           v.push_back(b%10);
            b=b/10;
        }
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==0 && ct==0){continue;}
            cout<<v[i];
            ct++;
        }cout<<endl;
    }}}

return 0;
}