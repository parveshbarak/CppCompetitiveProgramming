#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define pb emplace_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll, ll>
#define vp vector<pair<ll, ll>>
#define mp make_pair
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll>>
#define ff first
#define ss second
#define mid(l, r) (l + (r - l) / 2)
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define revloop(i, a, b) for (int i = (a); i >= (b); i--)
#define printarr(arr, a, b)          \
    for (int z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";     \
    cout << endl;

void io_file()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("/home/parvesh/Documents/Practice/io_files/input.txt", "r", stdin);
    freopen("/home/parvesh/Documents/Practice/io_files/output.txt", "w", stdout);
    freopen("/home/parvesh/Documents/Practice/io_files/error.txt", "w", stderr);
#endif
}

ll get_MEX(vi A, ll n) {
    for (ll i = 0; i < n; ++i)
        while (A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
            swap(A[i], A[A[i] - 1]);

    for (ll i = 0; i < n; ++i)
        if (A[i] != i + 1)
            return i + 1;
    return n + 1;
}

void code_here()
{
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vi arr(n);
        loop(i, 0, n) cin >> arr[i];
        // cout << get_MEX(arr,n) << "\n";
        unordered_map<ll,ll> mp;
        loop(i,0,n) mp[arr[i]]++;
        ll i = 0; vi ans;
        while(i<n) {
            ll mex = 0,temp = 0;
            loop(j,0,n+1) {
                if(mp[j]==0) {mex = j; break;}
            }
            if(mex > 0){
                while(i<n && mex > temp) {
                    if(arr[i] < mex) temp++, mp[arr[i]]--;
                    i++;
                }
            }
            cout << i << " ";
            ans.pb(mex);
        }
        // cout << ans.size() << "\n";
        loop(i,0,ans.size()) cout << ans[i] << " ";
        cout << "\n"; 
    }
}

int main()
{

    clock_t start = clock();

    io_file();
    code_here();

    clock_t end = clock();
    cerr << endl
         << endl
         << "Executed In: " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms";

    return 0;
}