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

vector<ll> parent;
ll MOD = 998244353;

void make_parent(ll k) {
    loop(i,0,k)
        parent[i] = i;
}

void do_union(ll x, ll y) {
    ll px = parent[x];
    ll py = parent[y];
    parent[px] = py;
}

ll find_set(ll k) {
    if(k == parent[k])
        return k;
    return find_set(parent[k]);
}

ll power(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y%2 == 1)
            res = (res*x)%MOD;
        y = y >> 1;
        x = (x * x)%MOD;
    }
    return res%MOD;
}


void code_here() {
    ll t; cin >> t;
    while(t--) {
        parent.clear();

        ll c,n,m;
        cin >> c >> n >> m;
        parent.resize(c);
        make_parent(c); // sb khud k parent;

        vector<pair<ll, pair<ll,ll>>> clubs;

        loop(i,0,c) {
            ll x; cin >> x;
            while(x--) {
                ll l,r;
                cin >> l >> r;
                clubs.pb(mp(l,mp(r,i)));
            }
        }

        sort(clubs.begin(),clubs.end());

        ll prev_club, prev_start = 0, prev_end = 0, rest =0;

        for(auto it : clubs) {
            ll start = it.ff;
            ll end = it.ss.ff;
            ll club = it.ss.ss;

            if(prev_end >= start) {
                do_union(club,prev_club);
                prev_end = max(prev_end,end);
            }
            else {
                rest += (start - prev_end -1);
                prev_start = start;
                prev_end = end;
                prev_club = club;
            }
        }

        rest += (n - prev_end);

        set<ll> s;
        loop(i,0,c) 
            s.insert(find_set(i));
        ll ans = s.size() + rest;
        // cerr << ans << " " << m << " ";
        ans = power(m,ans);

        
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