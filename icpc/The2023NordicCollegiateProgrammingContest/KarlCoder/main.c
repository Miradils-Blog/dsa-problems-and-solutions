#include <stdio.h>

int main()
{
    long long ind = 2, res, nonzeroind = 1;
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("buf[%lld]\n", ind);

    int bufval;

    while ((res = scanf("%d", &bufval)) == 1)
    {
        if (bufval > 0)
        {
            nonzeroind = ind;
            ind = (2 * ind + 1);
            printf("buf[%lld]\n", ind);
        }
        else
        {
            while (ind - nonzeroind > 1)
            {
                long long newind = (nonzeroind + ind) / 2;
                printf("buf[%lld]\n", newind);

                scanf("%d", &bufval);

                if (bufval)
                    nonzeroind = newind;
                else
                    ind = newind;
            }

            printf("strlen(buf) = %lld\n", nonzeroind + 1);
            return 0;
        }
    }

    return 0;
}