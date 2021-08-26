#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
vector<int> findSubstring(string s, vector<string>& words) {
    int n = s.length();
    int m = words.size();
    int k = words[0].length();
    int total_len = m*k;
    vector<int> result;
    unordered_map<string ,int> counter;
    for(string word : words){
        counter[word]+=1;
    }

    for(int i=0;i<k;i++) {
        int left = i, right = total_len+i;

        unordered_map<string ,int> counter1;
            
        for(int j =left;j<right;j = j+k){
            if(j>=n) break;
            counter1[s.substr(j,k)] +=1;
        }

        // if all the words of size k from left to right exist in count array then ans is yes 
        // otherwise slide the window to right.
        while(true) {
            bool flag = true;
            for(auto x:counter) {
                if(x.second != counter1[x.first]) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                result.push_back(left);
            }

            if(right <= n-k) {
                string w_remove = s.substr(left , k);
                string w_add = s.substr(right , k);
                counter1[w_remove]-=1;
                counter1[w_add] +=1;
                left += k; right += k;
            }
            else
                break;
        }
    } 

    return result;       
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> ans;
    string s = "abcdefghijkl";
    vector<string> words = {"abc","def"};
    ans = findSubstring(s,words);
    
    
    return 0;
}