// https://leetcode.com/problems/count-sub-islands/description/

#include <bits/stdc++.h>;
using namespace std;

int m, n;
vector<vector<int>> grid(505);
vector<vector<int>> grid2(505);
vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
bool visited[505][505];
// bool visited2[505][505];
bool valid(int i, int j)
{
    if (i >= m || i < 0 || j >= n || j < 0)
        return false;
    return true;
}

void DFS(int si, int sj, bool &isValidIsland)
{
    visited[si][sj] = true;
    if (grid[si][sj] != grid2[si][sj])
        isValidIsland = false;
    for (int i = 0; i < directions.size(); i++)
    {
        int ci = si + directions[i].first;
        int cj = sj + directions[i].second;
        if (valid(ci, cj) && !visited[ci][cj] && grid2[ci][cj] == 1)
        {
            DFS(ci, cj, isValidIsland);
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

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;
            grid2[i].push_back(val);
        }

    int totalIsland = 0;
    bool isValidIsland = true;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (valid(i, j), !visited[i][j] && grid2[i][j] == 1)
            {
                isValidIsland = true;
                DFS(i, j, isValidIsland);
                // cout << i << " " << j << " : " << isValidIsland << " " << grid[i][j] << " " << grid2[i][j] << endl;
                if (isValidIsland)
                    totalIsland++;
            }
        }
    }

    cout << totalIsland << endl;

    // cout << endl;

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << grid2[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}