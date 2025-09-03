#include <bits/stdc++.h>;
using namespace std;

char grid[105][105];
bool visited[105][105];

int n, m;
vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void DFS(int si, int sj) // O(N*M)
{
    // cout << si << " " << sj << endl;
    cout << "row: " << si << " col: " << sj << " --> " << grid[si][sj] << endl;
    visited[si][sj] = true;
    for (int i = 0; i < direction.size(); i++)
    {
        int ci = si + direction[i].first;
        int cj = sj + direction[i].second;
        if (valid(ci, cj) && !visited[ci][cj])
            DFS(ci, cj);
        // cout << ci << " " << cj << endl;
        // cout << "row: " << ci << " col: " << cj << "---> " << grid[ci][cj] << endl;
    }
}
main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int si, sj;
    cin >> si >> sj;
    memset(visited, false, sizeof(visited));
    DFS(si, sj);

    return 0;
}