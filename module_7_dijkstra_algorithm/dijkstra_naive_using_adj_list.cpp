#include <bits/stdc++.h>;
using namespace std;
vector<pair<int, int>> adj_list[105];

int dis[105];

void dijkstra(int src) //O(VE)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;

    while (!q.empty()) // O(N) or O(V)
    {
        pair<int, int> parentPair = q.front();
        q.pop();
        int parentNode = parentPair.first;
        int parentDistance = parentPair.second;

        // cout << parentNode << " " << parentDistance << " ";

        for (auto child : adj_list[parentNode]) //O(E)
        {
            int childNode = child.first;
            int childDistance = child.second;

            // if path relaxation possible then update distance and push to queue
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
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;

        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " -> ";
    //     for (auto p : adj_list[i])
    //     {
    //         cout << p.first << " " << p.second << ", ";
    //     }
    //     cout << endl;
    // }

    // memset(dis, INT_MAX, sizeof(dis)); // memset can't work with INT_MAX

    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    dijkstra(0);

    for (int i = 0; i < n; i++)
        cout << i << " -> " << dis[i] << endl;

    return 0;
}