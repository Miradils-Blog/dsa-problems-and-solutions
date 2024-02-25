#include <stdio.h>

int main()
{
    int x, bac = 0;

    scanf("%d", &x);

    while(x)
    {
        if (x & 1)
            ++bac;

        x >>= 1;
    }

    printf("%d\n", bac);

    return 0;
}