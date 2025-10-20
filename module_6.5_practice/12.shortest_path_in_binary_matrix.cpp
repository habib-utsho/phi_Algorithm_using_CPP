// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

#include <bits/stdc++.h>;
using namespace std;

int r, c;
int grid[105][105];
int level[105][105];

bool valid(int s, int j)
{
    if (s >= r || s < 0 || j >= c || j < 0)
        return false;
    return true;
}

vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};

void BFS(int si, int sj)
{
    queue<pair<int, int>> q;
    level[si][sj] = 1;
    q.push({si, sj});

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        // cout << par_i << " " << par_j << ": " << grid[par_i][par_j] << " level: " << level[par_i][par_j] << endl;

        for (pair<int, int> direction : directions)
        {
            int ci = par_i + direction.first;
            int cj = par_j + direction.second;
            // cout << ci << "  " << cj << endl;
            // cout << valid(ci, cj) << " " << level[ci][cj] << endl;
            if (valid(ci, cj) && level[ci][cj] == -1 && grid[ci][cj] == 0)
            {
                q.push({ci, cj});
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{

    cin >> r >> c;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];

    memset(level, -1, sizeof(level));
    if (grid[0][0] == 0)
        BFS(0, 0);

    cout << level[r - 1][c - 1];
    return 0;
}