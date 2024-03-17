#include <stdio.h>
#include <string.h>

const char digits[10][16] = {
    {"**** ** ** ****"}, // 0
    {"  *  *  *  *  *"}, // 1
    {"***  *****  ***"}, // 2
    {"***  ****  ****"}, // 3
    {"* ** ****  *  *"}, // 4
    {"****  ***  ****"}, // 5
    {"****  **** ****"}, // 6
    {"***  *  *  *  *"}, // 7
    {"**** ***** ****"}, // 8
    {"**** ****  ****"}, // 9
};

int main(void)
{
    char bombtime[8][16];
    int digitp;  // digit poimnt
    char ws; // whitespace
    char in[4];

    for (int i = 0; i < 5; ++i)  // we need to know at which line we are to store at right address
    {
        digitp = 0; // at each line, we start storing to 0th index

        while(scanf("%3[* ]%c", in, &ws))
        {
            // printf("in = %s, c=%d\n", in, ws);
            memcpy(bombtime[digitp] + (i * 3), in, 3); // store the next three chars in `bombtime`

            if (ws == '\n')
                break;

            ++digitp;
        }
    }

    //digitp is also number of digits at this point

    int res = 0, j;

    for (int i = 0; i <= digitp; ++i)
    {
        j = 0;
        for (; j < 10; ++j)
            if (!strcmp(bombtime[i], digits[j]))
            {
                res = res * 10 + j;  // j is digit, shift res to left (* 10), and add j
                break;
            }

        if (j == 10) // No such digit found, gibberish
        {
            res = -1;
            break;
        }
    }

    printf("%s\n", (res % 6) ? "BOOM!!" : "BEER!!");

    return 0;
}