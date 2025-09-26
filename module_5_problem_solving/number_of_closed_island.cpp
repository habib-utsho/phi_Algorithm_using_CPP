// https://leetcode.com/problems/number-of-closed-islands/description/

#include <bits/stdc++.h>;
using namespace std;

int m, n;
vector<vector<int>> grid(105);
vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
bool visited[305][305];
bool valid(int i, int j)
{
    if (i >= m || i < 0 || j >= n || j < 0)
        return false;
    return true;
}

void DFS(int si, int sj, bool &isIsland)
{
    visited[si][sj] = true;

    for (int i = 0; i < directions.size(); i++)
    {
        int ci = si + directions[i].first;
        int cj = sj + directions[i].second;
        if (!valid(ci, cj))
            isIsland = false;
        else if (!visited[ci][cj] && grid[ci][cj] == 0)
        {
            DFS(ci, cj, isIsland);
        }
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;
            grid[i].push_back(val);
        }

    memset(visited, false, sizeof(visited));

    int totalIsland = 0;
    bool isIsland = true;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (valid(i, j) && !visited[i][j] && grid[i][j] == 0)
            {
                isIsland = true;
                DFS(i, j, isIsland);

                if (isIsland)
                    totalIsland++;
            }
        }
    }

    cout << totalIsland << endl;

    // for (int i = 0; i < m; i++)
    // {

    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}