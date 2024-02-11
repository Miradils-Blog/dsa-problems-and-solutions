#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s)
{
    char* word = strtok(s, " ");
    char *last_word = NULL;

    while (word != NULL)
    {
        last_word = word;
        word = strtok(NULL, " ");
    }

    return strlen(last_word);
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