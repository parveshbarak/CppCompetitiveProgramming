#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1e9+7


// Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
// Modified Merge Sort to do the task! =>  0(NlogN)

ll merge(ll arr[], ll temp[], ll l, ll mid, ll h) {
    ll inv_count = 0;
    ll i=l,j=mid,k=l;
    while((i < mid) && (j<=h)) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv_count += mid-i;
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];
        
    while (j <= h)
        temp[k++] = arr[j++];
 
    for (i = l; i <= h; i++)
        arr[i] = temp[i];

    return inv_count;
}

ll _merge_sort(ll arr[], ll temp[], ll l, ll h) {
    ll mid, inv_count = 0;
    if(l<h) {
        mid = (l+h)/2;
        inv_count += _merge_sort(arr,temp,l,mid);
        inv_count += _merge_sort(arr,temp,mid+1, h);

        inv_count += merge(arr, temp, l, mid, h);
    }
    return inv_count;
}

ll inversion_count(ll arr[], ll size) {
    ll temp[size];
    return _merge_sort(arr,temp,0,size-1);
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n;
    cin >> n;   //size of array
    ll arr[n+1];
    for(ll i=1;i<=n;i++)
        cin >> arr[i];

    cout << inversion_count(arr,n) << "\n";


	return 0;
}

