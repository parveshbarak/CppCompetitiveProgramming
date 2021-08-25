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

struct node {
    ll sum, prefix_sum, suffix_sum, max_sum;
};

void make_seg_tree(ll arr[], node tree[],ll low, ll high, ll idx) {
    if (low == high) {
        tree[idx].sum = arr[low];
        tree[idx].prefix_sum = arr[low];
        tree[idx].suffix_sum = arr[low];
        tree[idx].max_sum = arr[low];
    } else {
        ll md = mid(low,high);
        make_seg_tree(arr, tree, low, md, 2*idx+1);
        make_seg_tree(arr, tree, md+1, high, 2*idx+2);

        tree[idx].sum = tree[2*idx+1].sum + tree[2*idx+2].sum;
                          
        tree[idx].prefix_sum =  max(tree[2*idx+1].prefix_sum, tree[2*idx+1].sum + tree[2*idx+2].prefix_sum);
        
        tree[idx].suffix_sum = max(tree[2*idx+2].suffix_sum, tree[2*idx+2].sum + tree[2*idx+1].suffix_sum);

        tree[idx].max_sum = max(tree[idx].prefix_sum, max(tree[idx].suffix_sum, max(tree[2*idx+1].max_sum, max(tree[2*idx+2].max_sum, tree[2*idx+1].suffix_sum + tree[2*idx+2].prefix_sum))));
    }
}




void code_here() {
    ll n =6;
    ll arr[n] = {1,2,-3,4,-7,8};
    node tree[4*n];
    make_seg_tree(arr,tree,0,5,0);
    loop(i,0,2*n) {
        cout << "sum => " << tree[i].sum << "  "<< "prefix_sum => " << tree[i].prefix_sum << "  "<< "suffix_sum => " << tree[i].suffix_sum << "  "<< "max_sum => " << tree[i].max_sum << "\n";
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