#include "bst.h"
#include <stddef.h>

// test

int main()
{
    struct Node *root = NULL;

    Insert_Element(&root, 10);
    Insert_Element(&root, 7);
    Insert_Element(&root, 8);
    Insert_Element(&root, 15);
    Insert_Element(&root, 13);
    Insert_Element(&root, 11);
    Insert_Element(&root, 14);
    root = Reverse_Removing(&root);

    return 0;
}

