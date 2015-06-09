#include "bst.h"
#include <stddef.h>

int main()
{
    struct Node *root = NULL;
    Insert_Element(&root, 6);
    Insert_Element(&root, 6);
    Insert_Element(&root, 5);
    Insert_Element(&root, 7);

    return 0;
}
