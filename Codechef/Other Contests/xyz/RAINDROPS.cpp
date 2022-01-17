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


void bfs(vector<vector<ll>>&graph, vector<ll>&dist) {
    int n = graph.size();
    queue<ll> q; vector<bool> vis(n+1,false);
    q.push(1); vis[1] = true;
    ll s = 0;
    while(!q.empty()) {
        ll sz = q.size();
        for(ll i=0;i<sz;i++) {
            auto t = q.front(); q.pop();
            bool flag = false;
            for(auto x: graph[t]) {
                if(!vis[x]) {
                    vis[x] = true;
                    flag = true;
                    q.push(x);
                }
            }
            if(!flag) dist[s]++;
        }
        s++;
    }
}


void code_here() {
    ll t; cin >> t;
    while(t--) {
        ll n,m; cin >> n >> m;
        vector<vector<ll>> graph(n+1);
        loop(i,0,n-1) {
            ll u,v; cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vi arr(m+1); ll ans = 0; arr[0] = 0;
        loop(i,1,m+1) cin >> arr[i];
        // loop(i,0,m+1) cout << arr[i] << " ";
        // unordered_map<ll,ll> distances;
        vector<ll> d(n+1,0);
        bfs(graph,d);
        // for(auto t: distances) {
        //     d[t.first] = t.second;
        // }
        for(ll i=1;i<=n;i++) d[i] += d[i-1];
        for(ll i=0;i<m;i++) {
            ll x = arr[i+1]-arr[i];
            // cout << x << " " << arr[i+1] << " " << arr[i] << "   ";
            for(ll j=0;j<x;j++) ans += d[j];
            // cout << ans << " ";
        }
        cout << ans << "\n";
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