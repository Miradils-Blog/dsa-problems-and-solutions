#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

struct edge
{
    int x, y, danger;
} edges[MAX];

vector<int> parent;

int repr(int node)
{
    if (node == parent[node])
        return node;

    return parent[node] = repr(parent[node]);
}

void unite(int x, int y)
{
    int x1 = repr(x);
    int y1 = repr(y);

    if (x1 != y1)
        parent[x1] = y1;
}

int f(edge a, edge b)
{
    return a.danger < b.danger;
}

int main()
{
    int n, m, i;
    scanf("%d %d", &n, &m);

    parent.resize(n + 1);

    for (i = 1; i <= n; i++)
        parent[i] = i;

    for (i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].x, &edges[i].y, &edges[i].danger);

    sort(edges, edges + m, f);

    for (i = 0; i < m; i++)
    {
        unite(edges[i].x, edges[i].y);

        if (repr(1) == repr(n))
            break;
    }

    printf("%d\n", edges[i].danger);
    return 0;
}