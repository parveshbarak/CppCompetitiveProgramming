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
        ll n,k; cin >> n >> k;
        string s; cin >> s;
        vi steps(26,0), ct(26,0), cti(26,0);
        for(ll j=0;j<26;j++) {
            loop(i,0,n) {
                if(s[i]==('A'+j)) ct[j]++;
            }
        }
        loop(i,0,26) {
            ll ic;
            char y = ('A'+i);
            for(ll j=0;j<n;j++) {
                ic = 0;
                while(j<n && s[j]==y) j++, ic++;
                cti[i] = max(cti[i],ic);
            }
        }
        loop(j,0,26) {
            char x = ('A'+j);
            for(ll i=0;i<n;) {
                if(x!=s[i]) {
                    steps[j]++;
                    while(i<n && x!=s[i]) i++;
                }
                else i++;
            }
        }
        // sort(steps.begin(),steps.end(),greater<ll>());
        if(k==0) {
            bool flag = true;
            char z = s[0];
            loop(i,1,n) if(s[i]!=z) flag = false;
            if(flag) cout << n << "\n";
            else cout << "-1\n"; 
        }
        else if(k==1) {
            ll a1 =0, a2 = 0;
            ll j = 0;
            while(s[j]==s[0]) j++, a1++;
            while(s[j]==s[n-1]) j--, a2++;
            cout << max(a1,a2) << "\n";
        }
        else {
            ll mx1 = 0;
            loop(i,0,26) mx1 = max(mx1,cti[i]);
            ll mx2 = 0;
            loop(i,0,26) {
                if(steps[i] <= k) mx2 = max(mx2,ct[i]);
            }
            cout << max(mx1,mx2) << "\n";
        }
        // if(steps > k) cout << cti << "\n";
        // else cout << ct << "\n";
    }
}


int main() {
    
    clock_t start = clock();
    
    // io_file();
    code_here();
    
    clock_t end = clock();
    cerr<<endl<<endl<<"Executed In: "<<double(end - start) / CLOCKS_PER_SEC*1000<<" ms";
    
    return 0;
}




class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        int prev1, prev2;
        prev1 = nums[0];
        
        if(n == 1) return prev1;
        
        prev2 = max(prev1, nums[1]);
        int ans = prev2;
        for(int i = 2; i < n; i++){
            ans = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;
    }
};
