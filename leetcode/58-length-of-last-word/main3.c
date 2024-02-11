#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s)
{
    int count = 0;
    int i = strlen(s) - 1;

    // we can check this without checking `i`
    // because, there is always at least one word
    while (s[i] == ' ')
        --i;

    while (i >= 0 && s[i] != ' ')
        ++count, --i;

    return count;
}

int main(void)
{
    freopen("in.txt", "r", stdin);

    char s[10001];
    gets(s);
    printf("%d", lengthOfLastWord(s));

    fclose (stdin);
    return 0;
}