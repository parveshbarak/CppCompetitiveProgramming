#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld	long double
#define mod 1000000007
#define inf 1e18
#define pb emplace_back
#define vi vector<ll>
#define vs	vector<string>
#define pii pair<ll,ll>
#define vp vector<pair<ll,ll>>
#define mp  make_pair
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll,vi,greater<ll> >
#define ff first
#define ss second
#define mid(l,r) (l+(r-l)/2)
#define loop(i,a,b) for(int i=(a);i<(b);i++)
#define revloop(i,a,b) for(int i=(a);i>=(b);i--)
#define printarr(arr,a,b) for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;



void io_file() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/home/parvesh/Documents/Practice/io_files/input.txt","r", stdin);
        freopen("/home/parvesh/Documents/Practice/io_files/output.txt","w", stdout);
        freopen("/home/parvesh/Documents/Practice/io_files/error.txt","w", stderr);
    #endif
}

vi dist;
vector<bool> vis;

void dfs(vector<vector<ll>> &graph, ll node, ll par) {
    for(auto x : graph[node]) {
        if(par == x) continue;
        dfs(graph,x,node);
        dist[node] = min(dist[node])
    }
}

void code_here() {
    ll t; cin >> t;
    while(t--) {
        ll n,k; cin >> n >> k;
        d_v.resize(n+1,1e9); d_f.resize(n+1,1e9); vis.resize(n+1,false);
        vector<vector<ll>> graph(n+1);
        vi x(k,0), friends(n,0);
        loop(i,0,k) cin >> x[i], friends[x[i]] = 1;
        loop(i,0,n) {
            ll x,y; cin >> x >> y;
            graph[x].pb(y);
            graph[y].pb(x);
        }

        dfs(graph,1,0);

    }
}


int main() {
    
    clock_t start = clock();
    
    io_file();
    code_here();
    
    clock_t end = clock();
    cerr<<endl<<endl<<"Executed In: "<<double(end - start) / CLOCKS_PER_SEC*1000<<" ms";
    
    return 0;
}