// https://leetcode.com/problems/surrounded-regions/description/

#include <bits/stdc++.h>;
using namespace std;

int r, c;
int grid[105][105];
bool vis[105][105];

vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool valid(int m, int n)
{
    if (m >= r || m < 0 || n >= c || n < 0)
        return false;
    return true;
}

void DFS(int si, int sj)
{
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];

    
        return 0;
}