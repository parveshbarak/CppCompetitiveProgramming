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


void code_here() {
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        string s; cin >> s;
        vi arr(n,1);
        loop(i,0,n) {
            if(s[i]=='0') arr[i] = -1;
        }
        ll k = n-1; bool flag = false;
        ll ct = 0;
        while(flag) {
            flag = false;
            vi prefix(n);
            prefix[0] = arr[0];
            loop(i,1,n) {
                prefix[i] = prefix[i-1]+arr[i];
            }
            ll j = n-1;
            while(j>=0 && prefix[j]>=0) j--;
            if(j==0) {
                ll it = 0;
                while(arr[it]==0) it++;
                arr[it]=0;
            }
            else {
                ct++;
                for(ll i=0;i<=j;i++) arr[i] = 0;
            }

            for(ll i=0;i<n;i++) {
                if(arr[i]==-1) flag = true;
            }
        }
        cout << ct << " ";
        if(ct%2==0) cout << "Uttu\n";
        else cout << "JJ\n";
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