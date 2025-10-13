// https : // www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-07/challenges/count-apartments-ii
#include <bits/stdc++.h>;
using namespace std;

int r, c;
char grid[1005][1005];
bool visited[1005][1005];
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

void DFS(int si, int sj, vector<int> &roomCount)
{
    roomCount.back()++;
    // cout << si << " " << sj << grid[si][sj] << endl;
    visited[si][sj] = true;

    for (int i = 0; i < directions.size(); i++)
    {
        int ci = si + directions[i].first;
        int cj = sj + directions[i].second;
        if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == '.')
        {
            DFS(ci, cj, roomCount);
        }
    }
}

int main()
{

    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];

    vector<int> roomCount;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!visited[i][j] && grid[i][j] == '.')
            {
                roomCount.push_back(0);
                // cout << i << " " << j << endl;
                cout << " i: " << i << " J: " << j << " :" << visited[i][j] << " " << endl;

                DFS(i, j, roomCount);
            }
        }
        // cout << endl;
    }

    sort(roomCount.begin(), roomCount.end());

    if (roomCount.size() == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        for (int value : roomCount)
        {
            cout << value << " ";
        }
    }

    return 0;
}