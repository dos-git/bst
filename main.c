#include "bst.h"
#include <stddef.h>

int main()
{
    struct Node *root = NULL;
    printf("BEGIN ADR %p %p\n", (void *)&root, root);
    Insert_Element(&root, 6);
    printf("BEGIN ADR %p %p\n", (void *)&root, root);
    Insert_Element(&root, 5);
/*    Insert_Element(&root, 7);
    Insert_Element(&root, 6);
    Insert_Element(&root, 5);
    Insert_Element(&root, 7);
*/
    return 0;
}
