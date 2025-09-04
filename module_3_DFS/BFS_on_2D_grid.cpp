#include <bits/stdc++.h>;
using namespace std;

char grid[105][105];
int dest[105][105];
bool visited[105][105];

int n, m;
vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void BFS(int si, int sj) // O(N*M)
{
    // cout << si << " " << sj << endl;
    visited[si][sj] = true;
    dest[si][sj] = 0;

    queue<pair<int, int>> q;
    q.push({si, sj});

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        cout << "row: " << par_i << " col: " << par_j << " --> " << grid[par_i][par_j] << endl;

        for (int i = 0; i < direction.size(); i++)
        {
            int ci = par_i + direction[i].first;
            int cj = par_j + direction[i].second;
            if (valid(ci, cj) && !visited[ci][cj])
            {
                // BFS(ci, cj);
                q.push({ci, cj});
                visited[ci][cj] = true;
                dest[ci][cj] = dest[par_i][par_j] + 1;
            }
            // cout << ci << " " << cj << endl;
            // cout << "row: " << ci << " col: " << cj << "---> " << grid[ci][cj] << endl;
        }
    }
}
main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    memset(visited, false, sizeof(visited));
    memset(dest, -1, sizeof(dest));
    BFS(si, sj);

    cout << grid[si][sj] << " to " << grid[di][dj] << " shortest distance is: " << dest[di][dj] << endl;

    return 0;
}