#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node *init_node(int val)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node *));
    node->val = val;
    node->left = node->right = NULL;

    return node;
}

void insert(struct Node *node, int val)
{
    if (val < node->val)
    {
        if (node->left == NULL)
            node->left = init_node(val);
        else
            insert(node->left, val);
    }
    else
    {
        if (node->right == NULL)
            node->right = init_node(val);
        else
            insert(node->right, val);
    }
}

void preorder(struct Node *node)
{
    if (node == NULL)
        return;

    printf("%d ", node->val);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct Node *node)
{
    if (node == NULL)
        return;

    preorder(node->left);
    preorder(node->right);
    printf("%d ", node->val);
}

int main()
{
    struct Node *head = NULL;

    int t, val;
    // freopen("in.txt", "r", stdin);

    scanf("%d", &t);
    scanf("%d", &val); // get the first value

    head = init_node(val);
    --t;

    while (t--)
    {
        scanf("%d", &val);
        insert(head, val);
    }

    postorder(head);
    printf("\n");
    free(head);

    return 0;
}