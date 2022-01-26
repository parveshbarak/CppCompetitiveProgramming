#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1e9+7


int minEdgeBFS(vector <int> edges[], int u, int v, int n)
{
	vector<bool> visited(n, 0);
	vector<int> distance(n, 0);

	queue <int> Q;
	distance[u] = 0;

	Q.push(u);
	visited[u] = true;
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		for (int i=0; i<edges[x].size(); i++)
		{
			if (visited[edges[x][i]])
				continue;

			// update distance for i
			distance[edges[x][i]] = distance[x] + 1;
			Q.push(edges[x][i]);
			visited[edges[x][i]] = 1;
		}
	}
	return distance[v];
}

// function for addition of edge
void addEdge(vector <int> edges[], int u, int v)
{
edges[u].push_back(v);
edges[v].push_back(u);
}





int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n,q,u,v,i,j=0;
        cin >> n >> q;
	    vector<int> edges[n];
        vector<int> arr(n,0);
        set<int> s1;
        for(i=0;i<n-1;i++) {
            cin >> u >> v;
            u=u-1;v=v-1;
            s1.insert(u);
            s1.insert(v);
            addEdge(edges, u, v);
        }

        int s2[n];
        set<int>::iterator itr;
        for (itr = s1.begin(); itr != s1.end(); itr++) {
            s2[j] = *itr; j++;
        }


        // cout << minEdgeBFS(edges, 0, 3, n) << "\n";

        for(i=0;i<n;i++)
            arr[i] = minEdgeBFS(edges,0,s2[i],n);

        for(i=0;i<n;i++)
            cout << arr[i] << " ";
        cout <<"\n\n";
            
        // while(q--)
        // {
        //     int m,l,a,b,sum=0;
        //     cin >> a >> b;
        //     a = a-1; b = b-1;
        //     for(i=0;i<n;i++) {
        //         m = arr[a] - arr[i];
        //         l = arr[b] - arr[i];
        //         m = (m>0) ? m : (-1*m);
        //         l = (l>0) ? l : (-1*l);
        //         cout << m << l << " ";
        //         sum += min(m,l);
        //         //cout << sum << "  ";
        //     }
        //     cout << sum << "\n";
        // }


    }

	// int n = 9;
	// vector <int> edges[9];
	// addEdge(edges, 0, 1);
	// addEdge(edges, 0, 7);
	// addEdge(edges, 1, 7);
	// addEdge(edges, 1, 2);
	// addEdge(edges, 2, 3);
	// addEdge(edges, 2, 5);
	// addEdge(edges, 2, 8);
	// addEdge(edges, 3, 4);
	// addEdge(edges, 3, 5);
	// addEdge(edges, 4, 5);
	// addEdge(edges, 5, 6);
	// addEdge(edges, 6, 7);
	// addEdge(edges, 7, 8);
	// int u = 0;
	// int v = 5;
	// cout << minEdgeBFS(edges, u, v, n) << "\n";
	return 0;
}

