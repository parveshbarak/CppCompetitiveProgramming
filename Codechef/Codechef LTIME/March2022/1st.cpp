#include <bits/stdc++.h>
#ifdef parveshbarak
	#define IO freopen("/home/parvesh/Desktop/Codes/DebuggingFiles/inputf.in","r",stdin); freopen("/home/parvesh/Desktop/Codes/DebuggingFiles/errorf.in","w",stderr); freopen("/home/parvesh/Desktop/Codes/DebuggingFiles/outputf.in","w",stdout);
	#include "/home/parvesh/Desktop/Codes/DebuggingFiles/myheader.h"
	#define print(args...) riint(__LINE__,#args,args)
#else
#define print(x,...)
	#define IO
	using namespace std;
#endif	
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long;
const int  m = 1<<10;
int dp[11][m];
bool solve(string &s , int i ,int cr){
	if(i>= s.size()){
		long long first  = 0 , second  = 0;
		for(int j = 0;j<s.size();j++){
			if(cr&(1<<j)) first = first*10 + (s[j]-'0');
			else second = second*10+ (s[j]-'0');
		}
		if(cr == 0 or cr == ((1<<s.size())-1)) return false;
		print(cr , first , second , s);
		return !((first+second)&1);
	}
	if(dp[i][cr]!=-1) return dp[i][cr];
	return dp[i][cr] = solve(s , i+1 , cr|(1<<i))| solve(s , i+1 , cr);
}
int main(int argc, char const *argv[])
{
	IO;
	FastIO;
	clock_t start = clock();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(dp , -1 , sizeof(dp));
		string str = to_string(n);
		long long sum = 0;
		 if(solve(str , 0,0)){
		 	cout<<"Yes\n";
		 }
		 else cout<<"No\n";
	}
	
	float time = (float)(clock()-start)/CLOCKS_PER_SEC;
	cerr<<"Program executed sucessfully in: "<< time<<" seconds";
	return 0;

}