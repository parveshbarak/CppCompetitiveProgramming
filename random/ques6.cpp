#include<bits/stdc++.h>
using namespace std;

vector<int> splitAtSpace(string str){
	vector<int> var;
	string temp ="";
	for(int i =0;i<str.length();i++){
		if (str[i] == ' ') {var.push_back((stoi(temp)));temp = "";}
		else temp+=str[i];
	}
	var.push_back(stoi((temp)));
	return var;
}



int main()
{
string input;
getline(cin,input);
vector<int> arr = splitAtSpace(input);
int n = arr.size();
for(int i=0;i<n;i++) {
    int a = arr[i];
    for(int j=i+1;(j<n) || (j<i+1+a);j++)
        
}

return 0;
}