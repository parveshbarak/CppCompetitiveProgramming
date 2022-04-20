#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1000000007


ll index_no(ll arr[], ll n, ll K)
{
    ll start = 0;
    ll end = n - 1;
    while (start <= end) {
        ll mid = (start + end) / 2;
        if (arr[mid] == K)
            return mid;
        else if (arr[mid] < K)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return end + 1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n,q;
    cin >> n >> q;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin >> arr[i];

    sort(arr,arr+n);

    while(q--) {
        ll x,y;
        cin >> x;
        y = index_no(arr,n,x);
        if(arr[y+1]==x || arr[y] == x || arr[y-1] == x)
            cout << "0\n";
        else {
            if((n-y)%2)
                cout << "NEGATIVE\n";
            else
                cout << "POSITIVE\n";
        }

    }
return 0;
}
