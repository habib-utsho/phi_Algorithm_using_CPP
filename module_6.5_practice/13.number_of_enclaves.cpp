// https://leetcode.com/problems/number-of-enclaves/description/
#include <bits/stdc++.h>;
using namespace std;
int r, c;
int grid[205][205];
bool vis[205][205];

vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool valid(int m, int n)
{
    if (m >= r || m < 0 || n >= c || n < 0)
        return false;
    return true;
}

int landCountThatNotTouchesBoundary = 0;
int landCountThatNotTouchesBoundaryPerIteration = 0;
int boundaryTouchesFlag = false;
void DFS(int si, int sj)
{
    vis[si][sj] = true;
    landCountThatNotTouchesBoundaryPerIteration++;
    // cout << grid[si][sj] << " ";

    for (int i = 0; i < directions.size(); i++)
    {
        int ci = si + directions[i].first;
        int cj = sj + directions[i].second;
        if (!valid(ci, cj))
        {
            boundaryTouchesFlag = true;
        }

        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
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
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                landCountThatNotTouchesBoundaryPerIteration = 0, boundaryTouchesFlag = false;
                DFS(i, j);
                if (!boundaryTouchesFlag)
                    landCountThatNotTouchesBoundary += landCountThatNotTouchesBoundaryPerIteration;
            }
            // cout << endl;
        }
    }

    cout << landCountThatNotTouchesBoundary << endl;

    return 0;
}