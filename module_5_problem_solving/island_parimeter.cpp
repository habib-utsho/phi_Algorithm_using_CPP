// https://leetcode.com/problems/island-perimeter/description/

#include <bits/stdc++.h>;
using namespace std;

int island[105][105];
bool visited[105][105];
int n, m;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

int perimeter = 0;

void DFS(int si, int sj)
{
    // cout << si << " - " << sj << endl;
    visited[si][sj] = true;
    for (int i = 0; i < directions.size(); i++)
    {
        int ci = si + directions[i].first;
        int cj = sj + directions[i].second;
        if (!valid(ci, cj) || island[ci][cj] == 0)
        {
            perimeter++;
        }
        else if (valid(ci, cj) && !visited[ci][cj] && island[ci][cj] == 1)
        {
            DFS(ci, cj);
        }
    }
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> island[i][j];

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //         cout << island[i][j] << ' ';
    //     cout << endl;
    // }

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visited[i][j] && island[i][j] == 1)
            {
                DFS(i, j);
            }

    cout << perimeter << endl;

    return 0;
}