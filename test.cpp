class Solution {
public:
    string opa(string t,int a)    {
        for(int i=1;i<t.size();i+=2) {
             int num  = t[i]-'0';
             num = (num+a)%10;
             t[i]= num+'0';
        }
        return t;
    }
    string opb(string t,int k) {
         k  = k%t.size();
        reverse(t.begin(),t.end());
        reverse(t.begin(),t.begin()+k);
        reverse(t.begin()+k,t.end());
        return t;
    }
    string findLexSmallestString(string s, int a, int b) {
        queue<string>q; vector<string>st;
        set<string>visited; string ans;
        visited.insert(s);
        q.push(s);
        while(!q.empty()) {
          string t = q.front(); q.pop();
            if(ans>t) ans = t;
            string one = opa(t,a);
            if(visited.find(one)==visited.end()) {
                q.push(one); visited.insert(one);
            }  
            string two = opb(t,b);
            if(visited.find(two)==visited.end()) {
                q.push(two); visited.insert(two);
            }  
        }
        return ans;
    }
};