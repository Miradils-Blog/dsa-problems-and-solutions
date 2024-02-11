#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s)
{
    char tmp[10001];
    int len = 0;

    while(sscanf(s, "%s%n", tmp, &len) > 0)
        s += len;

    return strlen(tmp);
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