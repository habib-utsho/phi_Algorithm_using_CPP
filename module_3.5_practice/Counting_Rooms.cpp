// https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>;
using namespace std;

char grid[1005][1005];
bool visited[1005][1005];
int r, c;

vector<pair<int, int>> directions = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

bool valid(int i, int j)
{
    if (i >= r || i < 0 || j >= c || j < 0)
        return false;
    return true;
}

void DFS(int si, int sj)
{

    // cout << si << " " << sj << " :" << grid[si][sj] << endl;
    visited[si][sj] = true;

    for (int i = 0; i < directions.size(); i++)
    {
        int ci = si + directions[i].first;
        int cj = sj + directions[i].second;

        if (!visited[ci][cj] && valid(ci, cj) && grid[ci][cj] == '.')
            DFS(ci, cj);
    }
}

int main()
{

    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];

    // cout << "Total dot count: " << totalDot << endl;
    // cout << "Total room: " << totalRoom << endl;

    int totalRoom = 0;
    for (int i = 0; i < r; i++)
    {

        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                totalRoom++;
                DFS(i, j);
            }
        }
    }

    cout << totalRoom << endl;

    return 0;
}