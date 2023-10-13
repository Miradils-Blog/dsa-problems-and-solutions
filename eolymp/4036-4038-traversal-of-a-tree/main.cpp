#include <bits/stdc++.h>

using namespace std;

class Node
{

public:
    int val;
    Node *left, *right;

    Node(int n)
    {
        val = n;
        left = right = NULL;
    }
};

class Tree
{

public:
    Node *head;

    Tree()
    {
        head = NULL;
    }

    void insert(int n)
    {
        insert(head, n);
    }

    void insert(Node *&node, int n)
    {

        if (node == NULL)
        {
            node = new Node(n);
            return;
        }

        if (n < node->val)
            insert(node->left, n);
        else
            insert(node->right, n);
    }
};

void PreOrder(Node *node)
{
    if (node == NULL)
        return;

    printf("%d ", node->val);
    PreOrder(node->left);
    PreOrder(node->right);
}

void PostOrder(Node *node)
{
    if (node == NULL)
        return;

    PostOrder(node->left);
    PostOrder(node->right);
    printf("%d ", node->val);
}

int main()
{
    int n, a;
    Tree t;
    // freopen("in.txt", "r", stdin);

    scanf("%d", &n);

    while (n--)
    {
        scanf("%d", &a);
        t.insert(a);
    }

    // PreOrder(t.head);
    PostOrder(t.head);
    printf("\n");

    return 0;
}