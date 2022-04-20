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
// #define ll long long;

int main(int argc, char const *argv[])
{
	IO;
	FastIO;
	clock_t start = clock();

	long long t; cin >> t;
	while(t--) {
		long long n; cin >> n;
		vector<long long> arr(n);
		for(long long i=0;i<n;i++) cin >> arr[i];
		vector<long long> odd, even;
		for(long long i=0;i<n;i++) {
			if(arr[i]%2==1) odd.push_back(arr[i]);
			else even.push_back(arr[i]);
		}
		if(odd.size() == 0 || odd.size()==1) cout << "-1\n";
		else if(odd.size()%2==0) {
			for(long long i=0;i<odd.size();i++) cout << odd[i] << " ";
			for(long long i=0;i<even.size();i++) cout << even[i] << " ";
			cout << "\n";
		}
		else {
			if(n==odd.size()) cout << "-1\n";
			else {
				for(long long i=0;i<odd.size()-1;i++) cout << odd[i] << " ";
				for(long long i=0;i<even.size();i++) cout << even[i] << " ";
				cout << odd[odd.size()-1] << "\n";
			}
		}
	}

	
	float time = (float)(clock()-start)/CLOCKS_PER_SEC;
	cerr<<"Program executed sucessfully in: "<< time<<" seconds";
	return 0;

}