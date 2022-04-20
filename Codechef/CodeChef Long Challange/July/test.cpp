#include<bits/stdc++.h>
using namespace std;
#define print(a,b) cerr<<"value of a: "<<a<<" "<<"value of b :"<<b<<endl;

int const N = 1e5+10;
int level[N];
int parent[N];
bool visited[N];


void level_parent(vector<int> tree[]){
    queue<int>q;
    q.push(1);
    visited[1] = 1;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        visited[node] = 1;
        for(auto x : tree[node]){
            if (not visited[x]){
                level[x] = level[node]+1;
                parent[x] = node;
                q.push(x);
            }
        }

    }
}

void visit(int node){
    visited[node] = true;
    while (parent[node] !=-1){
        node = parent[node];
        visited[node] = true;
    }

}
int visit2(int node){
    while (parent[node] !=-1 and not visited[node]){
        visited[node] = true;
        node = parent[node];

    }
    return node;
}

bool ispath(vector<int> list_path ){
     int max = INT_MIN , min = INT_MAX;
     int first_node, small_node; 
     for ( auto x : list_path){
        if (max <= level[x]){
            max = level[x];
            first_node = x;
        }
        if (min >= level[x]){
            min = level[x];
            small_node = x;
        }
     }
    memset(visited , 0 , sizeof(visited));
    visit(first_node);
    bool flag = false;
    for ( auto x : list_path){
        if (not visited[x]) 
            {
                flag = true ;
                break;
            }
    }
    if (not flag) return true;
    max = INT_MIN;
    int second ;
    for ( auto x : list_path){
        if (max <= level[x]  and not visited[x]){
            max = level[x];
            second = x;
        }
     }
     int node = visit2(second);
     if (level[node] > level[small_node]) return false;
     for ( auto x : list_path)
    {
        if (not visited[x]) return false;
    }

    return true;



}

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(level , 0 ,sizeof(level));
        memset(parent , -1 , sizeof(parent));
        memset(visited , 0, sizeof(visited));
        int u ,v,n;
        cin>>n;
        vector<int> tree[n+1];
        for(int i = 0;i<n-1;i++){
            cin>>u;
            cin>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
  

        }
        level_parent(tree);
        
        int query ;
        cin>>query;
        while (query--)
        {
            vector<int> list_path;
            int  k ;
            cin>> k;
            while(k--)
            {
                int node ;
                cin>>node;
               list_path.push_back(node);
            }
        if (ispath(list_path)) cout<<"Yes\n";
        else cout<<"No\n";
        }

        }


    return 0 ;
 }