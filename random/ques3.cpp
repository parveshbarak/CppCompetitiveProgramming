#include <bits/stdc++.h>
using namespace std;

vector<int> splitAtSpace(string str)
{
    vector<int> var;
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            var.push_back((stoi(temp)));
            temp = "";
        }
        else
            temp += str[i];
    }
    var.push_back(stoi((temp)));
    return var;
}

int main()
{
    string input;
    getline(cin, input);
    vector<int> arr = splitAtSpace(input);
    vector<int> out;
    out.push_back(arr[0] * arr[1]);
    for (int i = 0; i < arr.size() - 2; i++)
    {
        out.push_back(arr[i] * arr[i + 2]);
    }
    out.push_back(arr[arr.size() - 1] * arr[arr.size() - 2]);
    for (int x : out)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}