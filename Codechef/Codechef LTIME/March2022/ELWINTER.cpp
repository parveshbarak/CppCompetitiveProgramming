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

	long long n,m,q; cin >> n >> m >> q;
	vector<vector<int>> graph(n+1);
	unordered_set<long long> s;
	for(int i=0;i<m;i++) {
		long long u,v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	while(q--) {
		long long t,x; cin >> t >> x;
		if(t==1) s.insert(x);

		// type 2 query
		else if(t==2) {
			queue<long long> q;
			vector<bool> vis(n+1,false);
			for(auto ele: s) q.push(ele), vis[ele] = true;
			x = min(x,n+1);
			for(int i=0;i<x;i++) {
				int sz = q.size();
				if(sz == 0) break;
				for(int j=0;j<sz;j++) {
					auto t = q.front(); q.pop();
					for(auto it : graph[t]) {
						if(s.count(it) != 0) {
							s.insert(it); q.push(it); vis[it] = true;
						}
					}
				}
			}
		}

		else {
			if(s.count(x)==0) cout << "NO\n";
			else cout << "YES\n";
		}

	}

	
	float time = (float)(clock()-start)/CLOCKS_PER_SEC;
	cerr<<"Program executed sucessfully in: "<< time<<" seconds";
	return 0;

}