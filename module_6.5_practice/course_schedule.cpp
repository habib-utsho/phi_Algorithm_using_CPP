// https://leetcode.com/problems/course-schedule/description/

#include <bits/stdc++.h>;
using namespace std;

int numCourses, e;
vector<vector<int>> adj_list(2005);
bool cycle;
bool vis[2005];
bool pathVis[2005];

void DFS(int src)
{
    vis[src] = true;
    pathVis[src] = true;

    for (int child : adj_list[src])
    {
        if (vis[child] && pathVis[child])
            cycle = true;
        if (!vis[child])
            DFS(child);
    }

    pathVis[src] = false; // When backward the recursion then should path visit false
}

int main()
{
    cin >> numCourses >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }

    memset(vis, false, sizeof(vis));
    memset(pathVis, false, sizeof(pathVis));

    for (int i = 0; i < numCourses; i++)
    {
        cout << i << " : ";
        for (int val : adj_list[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < numCourses; i++)
        if (!vis[i])
            DFS(i);

    if (cycle)
        cout << "Cycle detected";
    else
        cout << "Cycle not detected";
    return 0;
}