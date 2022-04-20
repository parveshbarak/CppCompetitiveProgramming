#include <bits/stdc++.h>
#ifdef GOURISHANKER
	#define IO freopen("/Users/gourishanker/Heart/inputf.in","r",stdin); freopen("/Users/gourishanker/Heart/errorf.in","w",stderr); freopen("/Users/gourishanker/Heart/outputf.in","w",stdout);
	#include "/Users/gourishanker/Heart/myheader.h"
	#define print(args...) riint(_LINE_,#args,args)
#else
#define print(x,...)
	#define IO
	using namespace std;
#endif	
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(int argc, char const *argv[])
{
	IO;
	FastIO;
	clock_t start = clock();
	int t;
	cin>>t;
	while(t--){
		int n , k;
		cin>>n>>k;
		if(n-1 == k) cout<<-1<<'\n';
		else if(k == 0){
			for(int i = 0;i<n/2;i++) cout<<i<<" "<<n-i-1<<'\n';
		}
		else if(k == 1){
			cout<<0<<" "<<n-2<<"\n";
			for(int i = 1;i<n/2;i++) {
				if(i == 1) cout<<1<<" "<<n-1<<"\n";
				else cout<<i<<" "<<n-i-1<< " ";
			}
		}
		else{
			for(int i = 1;i<n/2;i++)
				if(i == k or n-i-1 == k) {
					if( n-i-1 == k){
						cout<< 0<<" "<<i<<"\n";
						cout<<n-i-1<<" "<<n-1<<"\n";
					}
					else {
						cout<< 0<<" "<<n-i-1<<"\n";
						cout<<i<<" "<<n-1<<"\n";
					}
				}
				else cout<<i<<" "<<n-i-1<<"\n";
		}


	}

	
	float time = (float)(clock()-start)/CLOCKS_PER_SEC;
	cerr<<"Program executed sucessfully in: "<< time<<" seconds";
	return 0;

}