// https://leetcode.com/problems/number-of-islands/description/

#include <bits/stdc++.h>;
using namespace std;

int m, n;
vector<vector<int>> grid(305);
vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
bool visited[305][305];
bool valid(int i, int j)
{
    if (i >= m || i < 0 || j >= n || j < 0)
        return false;
    return true;
}

void DFS(int si, int sj)
{
    visited[si][sj] = true;
    for (int i = 0; i < directions.size(); i++)
    {
        int ci = si + directions[i].first;
        int cj = sj + directions[i].second;
        if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == '1')
            DFS(ci, cj);
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            char val;
            cin >> val;
            grid[i].push_back(val);
        }

    memset(visited, false, sizeof(visited));

    int totalIsland = 0;
    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (valid(i, j) && !visited[i][j] && grid[i][j] == '1')
            {
                totalIsland++;
                DFS(i, j);
            }
        }
    }

    cout << totalIsland;

    return 0;
}