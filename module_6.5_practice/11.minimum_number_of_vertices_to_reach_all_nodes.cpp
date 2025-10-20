// https : // leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
#include <bits/stdc++.h>;
using namespace std;

int main()
{

    vector<int> noParentNodes;
    int parent[100005];
    pair<int, int> edges[100005];
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[i].first = a;
        edges[i].second = b;
    }
    memset(parent, false, sizeof(parent));
    for (int i = 0; i < e; i++)
    {
        parent[edges[i].second] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (!parent[i])
            noParentNodes.push_back(i);
    }

    for (int val : noParentNodes)
    {
        cout << val << " ";
    }

    return 0;
}