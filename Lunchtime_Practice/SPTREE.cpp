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


vector<pair<ll,ll>> bfs_for_level(vector<vector<ll>> adj, ll n, ll a) {
    vector<pair<ll,ll>> level(n);
    vector<bool> visited(n,false);
    queue<ll> que;
    loop(i,0,n) {
        level[i].ff=0; level[i].ss=i;
    }
    
    que.push(a);
    level[a].ff = 0;
    visited[a] = true;

    while (!que.empty()) {
        a = que.front();
        que.pop();
        loop(i,0,adj[a].size()) {
            ll b = adj[a][i];
            if (!visited[b]) {
                que.push(b);
                level[b].ff = level[a].ff + 1;
                visited[b] = true;
            }
        }
    }
    return level;
}

vector<bool> rev_bfs_for_marking(vector<vector<ll>> adj, vector<bool>sp, vector<pair<ll,ll>>level, ll n, ll a) {
    vector<bool> visited(n,false);
    vector<bool> p_marking(n,false);
    queue<ll> que;
    sort(level.rbegin(), level.rend());

    ll last_level = level[0].ff, ct=0;;
    for(ll i=0;level[i].ff == last_level;i++) {
        if(sp[level[i].ss]) {
            p_marking[level[i].ss] = true;
        }
        visited[level[i].ss] = true;
        ct++;
    }

    loop(i,ct,n) {
        if(sp[level[i].ss]) {
            p_marking[level[i].ss] = true;
        }
        else {
            loop(j,0,adj[level[i].ss].size()) {
                ll b = adj[level[i].ss][j];
                if (visited[b] && p_marking[b]) {
                    p_marking[level[i].ss] = true;
                }
            }
        }
        visited[level[i].ss] = true;
    }

    return p_marking;
}

vector<ll> get_L_for_Q_marked(vector<vector<ll>> adj, vector<bool> p_marking, ll n, ll a) {
    vector<ll> LCA(n,-1);
    vector<bool> visited(n,false);
    queue<ll> que;

    visited[a] = true;
    que.push(a);

    while (!que.empty()) {
        a = que.front();
        que.pop();
        loop(i,0,adj[a].size()) {
            ll b = adj[a][i];
            if(!visited[b]) {
                if((!p_marking[b]) && LCA[a]==-1)
                    LCA[b] = a;
                else if((!p_marking[b]) && LCA[a] != -1)
                    LCA[b] = LCA[a];
                que.push(b);
                visited[b] = true;
            }
        }
    }

    return LCA;
}


void code_here() {
    ll t; cin >> t;
    while(t--) {
        ll n,k,a;
        cin >> n >> k >> a; a--;
        vector<vector<ll>> adj(n);
        vector<bool> sp(n,false);
        loop(i,0,k) {
            ll x; cin >> x;
            sp[x-1] = true;
        }
        loop(i,0,n-1) {
            ll u,v; cin >> u >> v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        //First bfs for calculating level of each node witth a as root node;
        vector<pair<ll,ll>> level(n);
        level = bfs_for_level(adj,n,a);
        // loop(i,0,n)
        //     cerr << level[i].ff << "-" << level[i].ss << "  ";
        // cerr << "\n";

        //Now re_bfs for marking the nodes as p or q
        vector<bool> p_marking(n);
        p_marking = rev_bfs_for_marking(adj,sp,level,n,a);
        // loop(i,0,n)
        //     cerr << p_marking[i] << "  ";
        // cerr << "\n";

        // Now time to get L for all the nodes which are marked Q;
        vector<ll> LCA(n);
        LCA = get_L_for_Q_marked(adj, p_marking, n, a);
        // loop(i,0,n)
        //     cerr << LCA[i] << "  ";
        // cerr << "\n";


        // Now time to answer :-
        loop(i,0,n) {
            ll max_dist;
            if(p_marking[i]) {
                max_dist = level[i].ff;
            }
            else {
                max_dist = (2*(level[LCA[i]].ff) - level[i].ff);
            }
            cout << max_dist << " ";
        }
        cout << "\n";
        loop(i,0,n) {
            ll max_dist;
            if(p_marking[i]) {
                max_dist = level[i].ff;
            }
            else {
                max_dist = (2*(level[LCA[i]].ff) - level[i].ff);
            }
            cout << max_dist << " ";
        }

        cout << "\n";
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