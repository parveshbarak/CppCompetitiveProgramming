#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1e9+7

void swap(ll* a, ll* b) {
    ll t = *a;
    *a = *b;
    *b = t;
}

ll partition(ll arr[], ll l, ll h) {
    ll pivot = arr[l];
    ll i, j = h;
    i = l+1; j = h;
    while(i<j) {
        while(arr[i]<pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<j) swap(&arr[i], &arr[j]);
    }
    swap(&arr[l], &arr[j]);
    return j;
}

void Quick_sort(ll arr[], ll l, ll h) {
    ll j;
    if(l<h) {
        j = partition(arr,l,h);
        if(j>0)
            Quick_sort(arr,l,j-1);
        if(j<h)
            Quick_sort(arr,j+1,h);
    }
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n;
    cin >> n;   //size of array
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin >> arr[i];

    Quick_sort(arr,0,n-1);

    for(ll i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << "\n";


	return 0;
}

