// https://leetcode.com/problems/flood-fill/description/
#include <bits/stdc++.h>;
using namespace std;

int r, c;
int image[1005][1005];
bool visited[1005][1005];
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int sr, sc, prevColor, newColor;

bool valid(int i, int j)
{
    if (i >= r || i < 0 || j >= c || j < 0)
        return false;
    return true;
}

void DFS(int si, int sj)
{
    image[si][sj] = newColor;
    visited[si][sj] = true;

    for (int i = 0; i < directions.size(); i++)
    {
        int cr = si + directions[i].first;
        int cl = sj + directions[i].second;
        if (!visited[cr][cl] && valid(cr, cl) && image[cr][cl] == prevColor)
        {
            DFS(cr, cl);
        }
    }
}
void DFSPrint(int si, int sj)
{
    cout << "R" << si << "C" << sj << ": " << image[si][sj] << endl;
    visited[si][sj] = true;

    for (int i = 0; i < directions.size(); i++)
    {
        int cr = si + directions[i].first;
        int cl = sj + directions[i].second;
        if (!visited[cr][cl] && valid(cr, cl))
        {
            DFSPrint(cr, cl);
        }
    }
}

int main()
{

    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> image[i][j];

    cin >> sr >> sc >> newColor;
    memset(visited, false, sizeof(visited));

    prevColor = image[sr][sc];
    DFS(sr, sc);

    // Print
    memset(visited, false, sizeof(visited));
    DFSPrint(sr, sr);
    return 0;
}