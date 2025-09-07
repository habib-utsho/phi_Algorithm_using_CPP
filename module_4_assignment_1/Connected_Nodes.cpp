#include <bits/stdc++.h>;
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj_list(1005);
    // vector<vector<int>> adj_list(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int query;
    cin >> query;
    bool isVisited = false;
    while (query--)
    {
        int src;
        cin >> src;
        vector<int> v = adj_list[src];
        sort(v.begin(), v.end(), greater<int>());
        if (!v.size())
            cout << -1;
        else
            for (int child : v)
            {
                cout << child << " ";
            }
        cout << endl;
    }
    return 0;
}