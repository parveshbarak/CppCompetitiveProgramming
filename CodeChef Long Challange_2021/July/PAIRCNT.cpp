#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 

vector<vector<int>> graph;

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

vector<int> set_level(int n) {
    vector<bool> visited(n+1,false);
    queue<int> qu;
    vector<int> level(n+1,0);
    qu.push(1);
    visited[1] = true;
    level[1] = 1;
    while(!qu.empty()) {
        int node = qu.front();
        qu.pop();
        for(auto c:graph[node]) {
            if(!visited[c]) {
                visited[c] = true;
                qu.push(c);
                level[c] = level[node]+1;
            }
        }
    }

    return level;
}

int get_lca(int u, int v, map<int, int> ch_parent, vector<int> level_vec) {
    if(u == v)
        return u;
    else {
        int l1 = level_vec[u], l2 = level_vec[v];
        // cout << "\n" << "Levels :-   ";
        // cout << l1 << "  " << l2 << "\n";
        if(l1 > l2) {
            int diff = l1-l2;
            while(diff--) {
                u = ch_parent.find(u)->second;
            }
        }
        else {
            int diff = l2-l1;
            while(diff--) {
                v = ch_parent.find(v)->second;
            }
        }
        // cout << "Now lets see what are u and v : " << u << " " << v << " =>   ";
        if(u == v) {
            return u;
        }
        else {
            map<int, int>::iterator itr1, itr2;
            itr1 = ch_parent.find(u);   itr2 = ch_parent.find(u);
            if(itr1->second == itr2->second)
                return itr1->second;
            else {
                get_lca(itr1->second,itr2->second,ch_parent, level_vec);
            }
        }

    }
}


void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n,q;
        cin >> n >> q;
        graph.reserve(n+1);
        map<int, int> ch_parent;
        for(int i=0;i<n-1;i++) {
            int u,v;
            cin >> u >> v;
            addEdge(u,v);
            ch_parent.insert(pair<int,int>(v,u));
        }

        // cout << "\n\n";
        // for(int i=1;i<6;i++) {
        //     cout << i << "=> ";
        //     for(int j : graph[i])
        //         cout << j << " ";
        //     cout << "\n";
        // }
        // cout << "\n\n";

        // map<int, int>::iterator itr;
        // cout << "\tKEY\tELEMENT\n";
        // for (itr = ch_parent.begin(); itr != ch_parent.end(); ++itr) {
        //     cout << '\t' << itr->first
        //         << '\t' << itr->second << '\n';
        // }
        // cout << endl;

        vector<int> level_vec(n+1);
        level_vec = set_level(n);

        while(q--) {
            int k,d;
            cin >> k >> d;
            int vertices[k];
            for(int i=0;i<k;i++)
                cin >> vertices[i];
        
            // cout << d << "\n";
            int count = 0;
            for(int i=0;i<k;i++) {
                for(int j=i+1;j<k;j++) {
                    int x = get_lca(vertices[i],vertices[j],ch_parent, level_vec);
                    int ans = (level_vec[vertices[i]] + level_vec[vertices[i]] - 2*(level_vec[x]));
                    // cout << level_vec[vertices[i]] << " " << level_vec[vertices[j]] << " " << level_vec[x] << " " << ans << "   ";
                    if(ans == d) {
                        count++;
                    }
                }
            }

            cout << count << "\n";
        }

    }
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    clock_t start, end;
    start = clock();
  
    solve();

    end = clock();  
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    // cout << "Time taken by program is : " << fixed 
    //      << time_taken << setprecision(5);
    // cout << " sec " << endl;
    
    
    return 0;
}