#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
 
void addEdge(vector<vector<int>> &graph ,int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

vector<int> bfs(vector<vector<int>> graph, int src, int n) {
    vector<int> count(n,0);
    vector<bool> visited(n,false);
    queue<int> qu;

    qu.push(src);
    visited[src] = true;
    while(!qu.empty()); {
        int node = qu.front();
        qu.pop();
        for(int nei : graph[node]) {
            if(!visited[nei]) {
                visited[nei] = true;
                count[nei] = 1+count[node];
            }
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<vector<int>> graph;
        graph.reserve(n+2);
        for(int i=2;i<=n;i++) {
            int x;
            cin >> x;
            addEdge(graph,i,x);
        }
        // cout <<"\n";
        // for(int i=1;i<=n;i++) {
        //     cout << i << " =>  ";
        //     for(int j:graph[i])
        //         cout << j << " ";
        //     cout << "\n";
        // }
        // cout <<"\n";
    }
    
    
    return 0;
}