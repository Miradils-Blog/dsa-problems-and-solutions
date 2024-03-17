#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

struct coin_stack {
    int h; // height
    int i; // index
};

int comp(struct coin_stack *a, struct coin_stack *b)
{
    return b->h - a->h;
}

int main(void)
{
    int n, h;
    int maxh = 0, total = 0;
    scanf("%d", &n);

    struct coin_stack *arr = (struct coin_stack *) calloc(n, sizeof(struct coin_stack));

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &h);
        maxh = max(maxh, h);
        total += h;

        arr[i].h = h;
        arr[i].i = i + 1;
    }

    if (total % 2 || maxh > (total / 2))
        printf("no\n");
    else if (n == 2)
        for (int i = 0; i < arr[0].h; ++i)
            printf("1 2\n");
    else
    {
        qsort(arr, n, sizeof(struct coin_stack), comp);
        int sortcnt = 4;

        printf("yes\n");
        while(total)
        {
            printf("%d %d\n", arr[0].i, arr[1].i);
            --arr[0].h;
            --arr[1].h;

            // printf("DEBUG: %d %d\n", arr[0].h, arr[1].h);

            if (arr[1].h < arr[2].h)
            {
                qsort(arr, sortcnt, sizeof(struct coin_stack), comp);
                ++sortcnt;
            }
            
            total -= 2;
        }
    }

    return 0;
}