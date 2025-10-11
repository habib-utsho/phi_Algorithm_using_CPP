// https://cses.fi/problemset/task/1192
#include <bits/stdc++.h>;
using namespace std;

int r, c;
char grid[1005][1005];
int vis[1005][1005];
vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool valid(int si, int sj)
{
    if (si >= r || si < 0 || sj >= c || sj < 0)
        return false;

    return true;
}

void DFS(int si, int sj)
{
    vis[si][sj] = true;

    for (int i = 0; i < directions.size(); i++)
    {
        int ci = si + directions[i].first;
        int cj = sj + directions[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            DFS(ci, cj);
        }
    }
}

int main()
{

    cin >> r >> c;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    int roomCounts = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                roomCounts++;
                DFS(i, j);
            }
        }
    }

    cout << roomCounts;

    return 0;
}