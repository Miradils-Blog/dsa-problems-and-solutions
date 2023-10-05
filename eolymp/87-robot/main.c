#include <stdio.h>

int main()
{
    char in;
    int leftmost = 0, rightmost = 0, ind = 0;

    while (scanf("%c", &in) == 1 && (in == 'L' || in == 'R' || in == 'S'))
    {
        if (in == 'R')
        {
            ++ind;
            if (ind > rightmost)
                rightmost = ind;
        }
        else if (in == 'L')
        {
            --ind;
            if (ind < leftmost)
                leftmost = ind;
        }
    }

    printf("%d", rightmost - leftmost + 1);
    return 0;
}