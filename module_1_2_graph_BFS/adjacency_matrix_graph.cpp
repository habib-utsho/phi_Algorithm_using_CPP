#include <bits/stdc++.h>;
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];

    // Long cut to set 0 to all values
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         adj_mat[i][j] = 0;
    //     }
    // }
    // Shortcut to set 0 to all values
    memset(adj_mat, 0, sizeof(adj_mat));

    // Diagonal to 1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                adj_mat[i][j] = 1;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1; // This line is for undirected graph, if this is a directed graph then this line is not needed.
    }

    // Print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}