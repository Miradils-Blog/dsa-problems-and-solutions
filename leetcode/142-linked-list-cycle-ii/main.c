#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast = head, *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            slow = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }

            return slow;
        }
    }

    return NULL; // no loop found
}

int main()
{
    struct ListNode *list = malloc(sizeof(struct ListNode));
    list->val = 3;
    list->next = malloc(sizeof(struct ListNode));
    list->next->val = 2;
    list->next->next = malloc(sizeof(struct ListNode));
    list->next->next->val = 0;
    list->next->next->next = malloc(sizeof(struct ListNode));
    list->next->next->val = -4;
    
    // list->next->next->next = list->next; // loop
    list->next->next->next = NULL;  // no loop

    struct ListNode *res = detectCycle(list);
    struct ListNode *head = list;
    

    for (int i = 0; head != NULL; ++i, head = head->next)
    {
        if (head == res)
        {
            printf("tail connects to node index %d\n", i);
            break;
        }  
    }

    if (head == NULL)
        printf("no cycle\n");

    return 0;
}