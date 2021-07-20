#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1e9+7


// We can find k’th smallest element in time complexity better than O(N Log N). 
// A simple optimization is to create a Min Heap of the given n elements and call extractMin() k times. 
// TC = O(N + klogN)


void swap(ll arr[], ll i, ll j) {
    ll temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void delete_from_heap(ll arr[], ll n) {
    swap(arr[1],arr[n]);
    for(ll i=1;i<=n/2;) {
        ll f = -1;
        if((2*i)+1 > n-1) {
            if(arr[i] > arr[2*i]) swap(arr,(2*i),i);
            f = 2*i;
        } else {
            ll m = min(arr[2*i], arr[(2*i)+1]);
            ll k = (arr[2*i]==m) ? 2*i : (2*i)+1;
            if (m < arr[i]) swap(arr,k,i);
            f = k;
        }
        if(f == -1) break;
        i = f;
    }

    // for(ll i=1;i<n;i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
}


void heapify(ll arr[], ll n, ll x) {
    //base case :
    if(2*x > n) return;
    if((2*x)+1 > n) {
        if(arr[x] > arr[2*x]) swap(arr,(2*x),x);
    }
    else {
        ll m = min(arr[2*x], arr[(2*x)+1]);
        ll i = (arr[2*x]==m) ? 2*x : (2*x)+1;
        if (m < arr[x]) swap(arr,i,x);
        heapify(arr,n,(2*x));  heapify(arr,n,(2*x)+1);
    }
}


ll kth_smallest(ll arr[], ll n, ll k) {
    for(ll i=(n/2)+1;i>=1;i--)
        heapify(arr,n,i);

    // for(ll i=1;i<=n;i++)
    //     cout << arr[i] << " ";
    // cout << "\n\n";

    while(k--) {
        delete_from_heap(arr,n);
        n--;
    }

    // for(ll i=1;i<=n;i++)
    //     cout << arr[i] << " ";
    // cout << "\n\n";

    return arr[1];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n,k;
    cin >> n >> k;   //size of array and k so that to find kth largest..
    ll arr[n+1];
    for(ll i=1;i<=n;i++)
        cin >> arr[i];

    cout << kth_smallest(arr,n,k-1) << "\n";


	return 0;
}

