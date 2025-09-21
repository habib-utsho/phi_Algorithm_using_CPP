// https://leetcode.com/problems/max-area-of-island/description/

#include <bits/stdc++.h>;
using namespace std;

int r, c;
vector<vector<int>> adj_list(1005);
bool visited[1005][1005];
vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

bool valid(int i, int j)
{
    if (i >= r || i < 0 || j < 0 || j >= c)
        return false;
    return true;
}

void DFS(int si, int sj, int &tempMaxCellIsland)
{
    tempMaxCellIsland++;
    visited[si][sj] = true;
    for (int i = 0; i < directions.size(); i++)
    {
        int ci = si + directions[i].first;
        int cj = sj + directions[i].second;
        if (valid(ci, cj) && !visited[ci][cj] && adj_list[ci][cj] == 1)
        {
            DFS(ci, cj, tempMaxCellIsland);
        }
    }
}

int main()
{
    cin >> r >> c;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            int val;
            cin >> val;
            adj_list[i].push_back(val);
        }

    memset(visited, false, sizeof(visited));

    // for (int val : grid[0])
    // {
    //     cout << val << " ";
    // }

    int maxCellIsland = 0;
    int tempMaxCellIsland = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (valid(i, j) && !visited[i][j] && adj_list[i][j] == 1)
            {
                DFS(i, j, tempMaxCellIsland);
                maxCellIsland = max(maxCellIsland, tempMaxCellIsland);
                tempMaxCellIsland = 0;
            }
        }
        cout << endl;
    }

    cout << maxCellIsland;

    return 0;
}