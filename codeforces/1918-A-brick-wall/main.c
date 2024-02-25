#include <stdio.h>

int main()
{
    int n, m, t;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &n, &m);
        printf("%d\n", m / 2 * n);
    }

    return 0;
}