// MY CHUTIYAAAAA MISTALKEEEEEEEE!!!!!!!!!!!!!!!


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
        freopen("/home/parvesh/Desktop/Codes/io_files/input.txt","r", stdin);
        freopen("/home/parvesh/Desktop/Codes/io_files/output.txt","w", stdout);
        freopen("/home/parvesh/Desktop/Codes/io_files/error.txt","w", stderr);
    #endif
}


void rec(vector<vector<ll>> &arr, int i, int j, string ans, int vis, bool &flag) {
    if(flag) return;
    cout << ans << " ";
    int n = arr.size(), m = arr[0].size();
    if(i==0 && j==0 && vis==0){ cout << ans << "\n"; flag = true; return; }

    if(i+1==0 && j==0) {
        if(vis == 0) rec(arr,i+1,j,ans+"S", vis,flag);
    }
    else {
        if(i+1 >=0 && i+1 <n && j>=0 && j<m && arr[i+1][j] == 0) {
            int x = arr[i+1][j];
            arr[i+1][j] = -1;
            rec(arr,i+1,j,ans+"S",vis-1,flag);
            arr[i+1][j] = x;
        }
    }

    if(i-1==0 && j==0) {
        if(vis == 0) rec(arr,i-1,j,ans+"N", vis,flag);
    }
    else {
        if(i-1 >=0 && i-1 <n && j>=0 && j<m && arr[i-1][j] == 0) {
            int x = arr[i-1][j];
            arr[i-1][j] = -1;
            rec(arr,i-1,j,ans+"N",vis-1,flag);
            arr[i-1][j] = x;
        }
    }

    if(i==0 && j+1==0) {
        if(vis == 0) rec(arr,i,j+1,ans+"E", vis,flag);
    }
    else {
        if(i >=0 && i <n && j+1>=0 && j+1<m && arr[i][j+1] == 0) {
            int x = arr[i][j+1];
            arr[i][j+1] = -1;
            rec(arr,i,j+1,ans+"E",vis-1,flag);
            arr[i][j+1] = x;
        }
    }

    if(i==0 && j-1==0) {
        if(vis == 0) rec(arr,i,j-1,ans+"W", vis,flag);
    }
    else {
        if(i >=0 && i <n && j-1>=0 && j-1<m && arr[i][j-1] == 0) {
            int x = arr[i-1][j];
            arr[i][j-1] = -1;
            rec(arr,i,j-1,ans+"W",vis-1, flag);
            arr[i][j-1] = x;
        }
    }
}


void code_here() {
    ll t; cin >> t;
    while(t--) {
    	ll r,c; cin >> r >> c;
        vector<vector<char>> ip(r,vector<char>(c));
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) cin >> ip[i][j];
        }
        vector<vector<ll>> arr(2*r, vector<ll>(2*c,0));
        ll t = 0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(ip[i][j] == '#') {
                    arr[2*i][2*j] = 1; 
                    arr[2*i+1][2*j] = 1;
                    arr[2*i][2*j+1] = 1;
                    arr[2*i+1][2*j+1] = 1;
                } else t+=4;
            }
        }
        for(auto a: arr) {
            for(auto b: a) cout << b << " ";
            cout << "\n";
        }
        cout << "\n";

        bool flag = false;
        rec(arr,0,0,"",t-1, flag);

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
