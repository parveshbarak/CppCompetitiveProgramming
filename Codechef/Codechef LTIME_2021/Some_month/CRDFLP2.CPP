#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, ans = 0, mn = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<int> inverted(n, -1);
    for (int i = 29; i >= 0; i--)
    {
        int isPossible = 1;
        for (int j = 0; j < n; j++)
        {
            if (inverted[j] != -1)
            {
                if (inverted[j] == 1)
                    isPossible = ((isPossible & (b[j] >> i) & 1));
                else
                    isPossible = ((isPossible & (a[j] >> i) & 1));
                continue;
            }
            if (((a[j] >> i) & 1) || ((b[j] >> i) & 1))
            {
            }
            else
            {
                isPossible = 0;
                break;
            }
        }
        if (!isPossible)
            continue;
        int val = 1;
        for (int j = 0; j < n; j++)
        {
            if (inverted[j] != -1)
            {
                if (inverted[j] == 1)
                    val = ((val & (b[j] >> i) & 1));
                else
                    val = ((val & (a[j] >> i) & 1));
                continue;
            }
            if (((a[j] >> i) & 1) && ((b[j] >> i) & 1))
            {
            }
            else if (((a[j] >> i) & 1))
                inverted[j] = 0;
            else if (((b[j] >> i) & 1))
                inverted[j] = 1, mn++;
            else
            {
                val = 0;
                break;
            }
        }
        ans += (val * (1ll << i));
    }
    cout << ans << " " << mn << '\n';
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}