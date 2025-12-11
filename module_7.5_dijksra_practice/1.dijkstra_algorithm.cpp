#include <bits/stdc++.h>;
using namespace std;
vector<pair<int, int>> adj_list[10005];
vector<int> dis(10005);

void dijkstra(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;


    
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int parentNode = parent.first;
        int parentDistance = parent.second;
        // cout << parentNode << " " << parentDistance << endl;

        for (auto child : adj_list[parentNode])
        {
            int childNode = child.first;
            int childDistance = child.second;

            int newDistance = parentDistance + childDistance;
            if (newDistance < dis[childNode])
            {
                dis[childNode] = newDistance;
                q.push({childNode, newDistance});
            }
        }
    }
}

int main()
{
    int n, e, src;
    cin >> n >> e >> src;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    dijkstra(src);

    for (int i = 0; i < n; i++)
    {
        // cout << i << " -> " << dis[i] << endl;
        cout << dis[i] << " ";
    }
}