// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/
#include <bits/stdc++.h>;
using namespace std;

int r, c;
int grid[105][105];
bool vis[105][105];

vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool valid(int m, int n)
{
    if (m >= r || m < 0 || n >= c || n < 0)
        return false;
    return true;
}

int maxFish = 0;
int maxFishCount = 0;

void DFS(int si, int sj)
{
    // cout << grid[si][sj] << " ";
    maxFishCount += grid[si][sj];
    // cout << si << " " << sj << endl;
    vis[si][sj] = true;

    for (int i = 0; i < directions.size(); i++)
    {
        int ci = si + directions[i].first;
        int cj = sj + directions[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != 0)
        {
            // vis[ci][cj] = true;
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
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {

            if (!vis[i][j] && grid[i][j] != 0)
            {
                // cout << " i: " << i << " J: " << j << " :" << vis[i][j] << " " << endl;
                maxFishCount = 0;
                // cout << grid[i][j] << " ";
                DFS(i, j);
                maxFish = max(maxFish, maxFishCount);
            }
        }
    cout << maxFish;

    return 0;
}