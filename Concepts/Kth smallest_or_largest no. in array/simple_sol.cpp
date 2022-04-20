#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1e9+7


// A simple solution is to sort the given array using a O(N log N) sorting algorithm like Merge Sort, Heap Sort, etc,
//  and return the element at index k-1 in the sorted array. 
// TC = O(NlogN)

ll kth_smallest(ll arr[], ll n, ll k) {
    sort(arr, arr+n);
    return arr[k-1];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n,k;
    cin >> n >> k;   //size of array and k so that to find kth largest..
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin >> arr[i];

    cout << kth_smallest(arr,n,k) << "\n";


	return 0;
}

