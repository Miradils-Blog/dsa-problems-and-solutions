#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 101
#define PRIME 31

unsigned int calc_hash(const char *str)
{
    unsigned int hash = 0;
    
    while(*str)
        hash = hash * PRIME + *str++;
        
    return hash;
}

struct LinkedList {
    int hashval;
    struct LinkedList *next;
};

void free_list(struct LinkedList *head)
{
    if (!head || !head->next)
        return;
        
    free(head->next);
    head->next = NULL;
}

// 0 - duplicate, 1 - success
int list_add(struct LinkedList *head, int hash)
{
    if (head->hashval == hash)
        return 0;
        
    if (head->next == NULL)
    {
        head->next = calloc(1, sizeof(struct LinkedList));
        head->next->hashval = hash;
        return 1;
    }
    
    return list_add(head->next, hash);
}

int main(void)
{
    struct LinkedList *list  = calloc(1, sizeof(struct LinkedList));
    
    int t, n;
    char city[21];
    scanf("%d", &t);
    int cnt;
    
    while(t--)
    {
        scanf("%d", &n);
        cnt = 0;
        while(n--)
        {
            scanf("%s", city);
            cnt += list_add(list, calc_hash(city));
        }
        
        printf("%d\n", cnt);
        free_list(list);
    }
    
    return 0;
}