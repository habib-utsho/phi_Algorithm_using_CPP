// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-07/challenges/can-go-1

#include <bits/stdc++.h>;
using namespace std;

bool visited[1005][1005];
char grid[1005][1005];
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
bool possibleToVisit = false;

void DFS(int si, int sj)
{
    // cout << si << " " << sj << " :" << grid[si][sj] << endl;
    visited[si][sj] = true;
    if (grid[si][sj] == 'B')
    {
        possibleToVisit = true;
        return;
    }
    for (int i = 0; i < directions.size(); i++)
    {
        int ci = si + directions[i].first;
        int cj = sj + directions[i].second;
        if (valid(ci, cj) && !visited[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'B'))
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

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 'A')
            {
                DFS(i, j);
                break;
            }
        }
    }

    if (possibleToVisit)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}