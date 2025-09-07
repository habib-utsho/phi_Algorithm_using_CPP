// https : // www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-07/challenges/count-apartments

#include <bits/stdc++.h>;
using namespace std;

bool visited[1005][1005];
char grid[1005][1005];
int r, c;

bool valid(int i, int j)
{
    if (i >= r || i < 0 || j >= c || j < 0)
        return false;
    return true;
}
vector<pair<int, int>> directions = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

void DFS(int si, int sj)
{
    visited[si][sj] = true;

    for (int i = 0; i < directions.size(); i++)
    {
        int ci = si + directions[i].first;
        int cj = sj + directions[i].second;
        if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == '.')
        {
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

    memset(visited, false, sizeof(visited));

    int totalApartments = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!visited[i][j] && grid[i][j] == '.')
            {
                totalApartments++;

                DFS(i, j);
            }
        }
    }

    cout << totalApartments << endl;

    return 0;
}