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

int main(int argc, char const *argv[])
{
	IO;
	FastIO;
	clock_t start = clock();

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		if(n==2) cout << "-1\n";
		else if(n%2==0) {
			cout << 1 << " " << n << " ";
			for(int i=2;i<n;i++) cout << i << " ";
		} else {
			for(int i=0;i<n;i++) cout << i+1 << " ";
		}
		cout << "\n";
	}

	
	float time = (float)(clock()-start)/CLOCKS_PER_SEC;
	cerr<<"Program executed sucessfully in: "<< time<<" seconds";
	return 0;

}