#include <stdio.h>
#include <stdlib.h>

#define MAX 1000001

int *parent;

typedef struct
{
    int x, y, danger;
} edge;

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

    if (x1 != y1) // sanity check, make sure you are not connecting already connected
        parent[x1] = y1;
}

int comp(const void *e1, const void *e2)
{
    return ((edge *)e1)->danger - ((edge *)e2)->danger;
}

int main()
{
    edge *edges;

    int n, m, i;
    scanf("%d %d", &n, &m);

    parent = (int *)malloc((n + 1) * sizeof(int));
    edges = (edge *)malloc(m * sizeof(edge));

    // In the beginning, each node is its parent
    for (i = 1; i <= n; ++i)
        parent[i] = i;

    for (i = 0; i < m; ++i)
        scanf("%d %d %d", &edges[i].x, &edges[i].y, &edges[i].danger);

    qsort(edges, m, sizeof(edge), comp); // sort by ascending danger

    for (i = 0; i < m; ++i)
    {
        unite(edges[i].x, edges[i].y);

        if (repr(1) == repr(n)) // update parents, and check if 1 and n is connected
            break;
    }

    printf("%d\n", edges[i].danger);

    free(parent);
    free(edges);

    return 0;
}