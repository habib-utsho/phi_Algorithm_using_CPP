// https://leetcode.com/problems/battleships-in-a-board/description/
#include <bits/stdc++.h>;
using namespace std;

int r, c;
char grid[205][205];
bool vis[205][205];

vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool valid(int m, int n)
{
    if (m >= r || m < 0 || n >= c || n < 0)
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

        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 'X')
            DFS(ci, cj);
    }
}

int main()
{

    cin >> r >> c;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    int battleShipCount = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!vis[i][j] && grid[i][j] == 'X')
            {
                DFS(i, j);
                battleShipCount++;
            }
        }
    }

    cout << battleShipCount << endl;

    return 0;
}