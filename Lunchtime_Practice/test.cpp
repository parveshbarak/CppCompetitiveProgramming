#include <bits/stdc++.h>
#ifdef GOURISHANKER
	#define IO freopen("/media/gouri/Heart/inputf.in","r",stdin); freopen("/media/gouri/Heart/errorf.in","w",stderr); freopen("/media/gouri/Heart/outputf.in","w",stdout);
	#include "/media/gouri/Heart/myheader.h"
	#define print(args...) riint(_LINE_,#args,args)
#else
#define print(x,...)
	#define IO
	using namespace std;
#endif	
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
bool compare(pair<long long,long long>q1, pair<long,long>q2)
{
    return (q1.first > q2.first);
}
long long gcd(long long a , long long b){
	return b == 0 ? a:gcd(b,a%b);
}
int main(int argc, char const *argv[])
{
	IO;
	FastIO;
	clock_t start = clock();
	int t;
	cin>>t;
	while(t--){
		long long n ,m;
		cin>>n>>m;
		vector<pair<long long ,long long>> queries;
		while(m--){
			long long q,w;
			cin>>q>>w;
			queries.push_back({q,w});
		}
		
		sort(queries.begin(),queries.end(),compare);
		print(queries);
		long long ans = 0;
		long long y1 = queries[0].second;
		ans += (n-n/y1)*queries[0].first;
		n = n/y1;
		print(ans ,n);
		long long y2;
		// cout << ans << "  ";
		for(int i =1;i<queries.size();i++){
			y2 = queries[i].second;
			y2 /=gcd(y1,y2);
			ans += (n - n/y2)*queries[i].first;
			n = n/y2;
			y1 = queries[i].second;
			if (n == 0) break;
			// cout << ans << "  ";

		}
		cout<<ans<<"\n";
	}
	
	float time = (float)(clock()-start)/CLOCKS_PER_SEC;
	cerr<<"Program executed sucessfully in: "<< time<<" seconds";
	return 0;

}

