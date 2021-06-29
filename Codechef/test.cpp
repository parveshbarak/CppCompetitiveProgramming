#include <bits/stdc++.h>
using namespace std;
  

  
 int main()
{
    string s;
    
      cin>>s;
      
      map<char , int >m;
      
         map<char , int >::iterator itr;
       
      for(long i=0;i<s.length();i++)
        m[s[i]]++;
        
        for(itr=m.begin();itr!=m.end();itr++)
          
            cout<<itr->first<<" - "<<itr->second<<endl;
}