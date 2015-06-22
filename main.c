#include "bst.h"
#include <stddef.h>

int main()
{
    struct Node *root = NULL, *tmp = NULL;
    Insert_Element(&root, 8);
    struct Node *res = NULL;

    res = Reverse_Removing(&root);

    /*
    Insert_Element(&root, 8);
    Insert_Element(&root, 5);
    Insert_Element(&root, 6);
    Insert_Element(&root, 4);
    Insert_Element(&root, 11);
    Insert_Element(&root, 4);
    Insert_Element(&root, 10);
    Insert_Element(&root, 15);
    Insert_Element(&root, 9);
    Insert_Element(&root, 15);

    tmp = Find_Node_by_ID(&root, 4);
*/

    return 0;
}
