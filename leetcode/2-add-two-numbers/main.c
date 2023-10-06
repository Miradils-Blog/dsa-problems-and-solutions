#include <stdio.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *tail = malloc(sizeof(struct ListNode));
    struct ListNode *head = tail;

    int a, b, c, carry = 0;

    while (l1 || l2 || carry == 1)
    {
        a = (l1) ? l1->val : 0;
        b = (l2) ? l2->val : 0;
        c = (a + b + carry);

        carry = c / 10;

        tail->next = malloc(sizeof(struct ListNode));
        tail->next->val = c % 10;
        tail = tail->next;

        if (l1)
            l1 = l1->next;

        if (l2)
            l2 = l2->next;
    }

    return head->next;
}

int main(void)
{
    struct ListNode *l1 = malloc(sizeof(struct ListNode));
    l1->val = 2;
    l1->next = malloc(sizeof(struct ListNode));
    l1->next->val = 4;
    l1->next->next = malloc(sizeof(struct ListNode));
    l1->next->next->val = 3;

    struct ListNode *l2 = malloc(sizeof(struct ListNode));
    l2->val = 5;
    l2->next = malloc(sizeof(struct ListNode));
    l2->next->val = 6;
    l2->next->next = malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    struct ListNode *res = addTwoNumbers(l1, l2);

    while (res)
    {
        printf("%d", res->val);
        res = res->next;
    }

    return 0;
}