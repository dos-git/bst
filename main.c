#include "bst.h"
#include <stddef.h>

int main()
{
    struct Node *root = NULL;
    Insert_Element(&root,10);
    Insert_Element(&root,4);
    Insert_Element(&root,5);
    Insert_Element(&root,2);
    Insert_Element(&root,1);
    Insert_Element(&root,17);
    Insert_Element(&root,15);
    Insert_Element(&root,11);
    Insert_Element(&root,12);
    Insert_Element(&root,3);
    Insert_Element(&root,9);
    Insert_Element(&root,14);
    Insert_Element(&root,22);
    Reverse_Removing(&root);


    return 0;
}

