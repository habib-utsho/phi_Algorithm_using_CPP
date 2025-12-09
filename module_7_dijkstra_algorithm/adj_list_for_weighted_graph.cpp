#include <bits/stdc++.h>;
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj_list[n];
    while (e--)
    {
        int a, b, c;

        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
    }
    
    return 0;
}