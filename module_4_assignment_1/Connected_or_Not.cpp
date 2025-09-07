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
    }

    int query;
    cin >> query;
    bool isVisited = false;
    while (query--)
    {
        int src, dest;
        cin >> src >> dest;
        isVisited = false;
        if (src == dest)
            isVisited = true;
        else
            for (int child : adj_list[src])
            {
                if (child == dest)
                {
                    isVisited = true;
                    break;
                }
            }

        if (isVisited)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}