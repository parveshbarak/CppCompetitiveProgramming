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

vector<int> bfs(vector<vector<int>>& graph, int root) {
	queue<int> q; q.push(root);
	int n = graph.size();
	vector<bool> vis(n, false); vis[root] = true;
	vector<int> s; s.push_back(root);
	while(!q.empty()) {
		int t = q.front(); q.pop();
		for(auto ch : graph[t]) {
			if(!vis[ch])  {
				q.push(ch);
				s.push_back(ch);
				vis[ch] = true;
			}
		}
	}
	return s;
}

int main(int argc, char const *argv[])
{
	IO;
	FastIO;
	clock_t start = clock();

	int t; cin >> t;
	while(t--) {
		int n,m; cin >> n >> m;
		vector<vector<int>> graph(n+1);
		for(int i=0;i<m;i++) {
			int u,v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		vector<int> s1 = bfs(graph, 1);
		int x = 1;
		for(auto xlx : s1) x = max(x, xlx);
		if(x == n) cout << 0 << "\n";
		else {
			x += 1; int ct = 1;
			// cerr << x << " ";
			// int lund = 5;
			// vector<int> s2;
			while(x != n) {
				vector<int> s2 = bfs(graph, x);
				for(auto zl: s2) x = max(x, zl);

				// auto it = (s2.end());
				// x = *it;
				// cerr << x << "\n";
				if(x != n) ct++, x+=1;
				// cerr << "ct=> " << x << " ";
				// cerr << "\n";
				// cerr << x << " ";
			}
			cout << ct << "\n";
		}

	}

	
	float time = (float)(clock()-start)/CLOCKS_PER_SEC;
	cerr<<"Program executed sucessfully in: "<< time<<" seconds";
	return 0;

}