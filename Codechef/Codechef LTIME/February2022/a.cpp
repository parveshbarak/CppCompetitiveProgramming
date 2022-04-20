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
// #define long long long long int;

int main(int argc, char const *argv[])
{
	IO;
	FastIO;
	clock_t start = clock();

	long long t; cin >> t;
	set<int> s;
	s.insert(6); s.insert(7); s.insert(13); s.insert(14); s.insert(20); s.insert(21);s.insert(27); s.insert(28);

	while(t--) {
		long long n; cin >> n;
		vector<long long> arr(n);
		for(int i=0;i<n;i++) cin >> arr[i];
		long long ans = 8;
		for(auto x: arr) {
			if(s.count(x)) continue;
			else ans++;
		}
		cout << ans << "\n";
	}


	
	float time = (float)(clock()-start)/CLOCKS_PER_SEC;
	cerr<<"Program executed sucessfully in: "<< time<<" seconds";
	return 0;

}