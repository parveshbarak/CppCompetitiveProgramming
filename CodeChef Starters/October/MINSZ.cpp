#include <bits/stdc++.h>
#ifdef GOURISHANKER
#define IO                                                \
    freopen("/media/gouri/Heart/inputf.in", "r", stdin);  \
    freopen("/media/gouri/Heart/errorf.in", "w", stderr); \
    freopen("/media/gouri/Heart/outputf.in", "w", stdout);
#include "/media/gouri/Heart/myheader.h"
#define print(args...) riint(_LINE_, #args, args)
#else
#define print(x, ...)
#define IO
using namespace std;
#endif
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
int main(int argc, char const *argv[])
{
    IO;
    FastIO;
    clock_t start = clock();
    int t;
    cin >> t;
    while (t--)
    {
        long long c;
        vector<long long> bits;
        cin >> c;
        int number = c;
        while (c)
        {
            bits.push_back(c & 1);
            c >>= 1;
        }

        if(number==0) {
            cout << 2 << "\n";
            cout << 1 << " " << 1 << "\n";
        }
        else {
            vector<long long> p; int ct =0; int par = 1,op=0;

            for(int i=bits.size()-1;i>=0;i--) {
                if(op+bits[i] == 1) {
                    p.push_back(i+1); ct++; 
                    if(op == 1) op=0;
                    else op=1;
                }
            }

            cout << ct << "\n";
            for(long long i=0;i<p.size();i++) {
                cout << p[i] << " ";
                cout << (1<<p[i]) - 1) << " ";
            }
            cout << "\n";
        }
    }

    float time = (float)(clock() - start) / CLOCKS_PER_SEC;
    cerr << "Program executed sucessfully in: " << time << " seconds";
    return 0;
}