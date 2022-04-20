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

long long get_lcm(long long a, long long b) {
    return (a*b)/gcd(a,b);
}
long long solve(vector<pair<long long,long long>> queries,int n){
		long long ans = 0;
		long long y1 = queries[0].second;
		ans += (n-n/y1)*queries[0].first;
		n = n/y1;
		long long lcm = y1;
		
		for(int i =1;i<queries.size();i++){
			long long y2 = queries[i].second;
            lcm = get_lcm(lcm,y2)/gcd(lcm,y2);
			long long  value = -1;
			value = gcd(y1,y2);
            ans += (n - n/y2)*queries[i].first;
            n = n/y2;
			//print(y1,y2,value);
			//print(ans,n,y2,y1,lcm,queries[i].second,value);
			// y2 = y2/value;
			// if (n!=1  and lcm % queries[i].second !=0) 
			// 	{ans += (n - n/y2)*queries[i].first;
			// 	n = n/y2;
			// }
			// else if ((lcm % queries[i].second != 0))
			// 	 {ans += queries[i].first;
			// 	 n--;
			// 	};
			// lcm = (lcm *queries[i].second)/gcd(lcm , queries[i].second);
			
			// y1 = queries[i].second;
			// print(ans,n,y2,y1,lcm,gcd(y2,y1));
			if (n == 0) break;

		}
		return ans;
}
long long navieSolve(vector<pair<long long,long long>> queries,int n){
	vector<long long> l(n+1,0);
	for (pair x : queries){
		for(int i = 1;i<=n;i++){
			if (l[i] == 0 and (i%x.second !=0))
				l[i] = x.first;
		}
	}
	long long s1 = 0;
	for(int i =1;i<=n;i++){
		s1+=l[i];

	}
	return s1;
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
		// vector<pair<long long ,long long>> query;
		// set<int ,greater<int>> freq;
		// for( pair x: queries){
		// 	if (freq.count(x.second)) continue;
		// 	else{
		// 		query.push_back(x);
		// 		freq.insert(x.second);}
		// }
		long long gouri = solve(queries , n);
		long long pravesh = navieSolve(queries , n);
		if (gouri != pravesh){
			print(queries ,n,gouri,pravesh);
			break;
		}
		
	}
	
	float time = (float)(clock()-start)/CLOCKS_PER_SEC;
	cerr<<"Program executed sucessfully in: "<< time<<" seconds";
	return 0;

}