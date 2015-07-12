#include "bst.h"
#include <stddef.h>


int main()
{
    struct Node *root = NULL;

    Insert_Element(&root,20);
    Insert_Element(&root,15);

    Insert_Element(&root,17);
    Insert_Element(&root,16);
    Insert_Element(&root,19);
    Insert_Element(&root,18);
    Insert_Element(&root,21);
    Remove_Node(&root, 20);
    Reverse_Removing(&root);
    /*
    Insert_Element(&root,20);
    Insert_Element(&root,15);

    Insert_Element(&root,17);
    Insert_Element(&root,16);
    Insert_Element(&root,19);
    Insert_Element(&root,18);


    //Remove_Node(&root, 15);

    Remove_Node(&root, 20);
    //Reverse_Removing(&root);
*/


/*  test for removing node that have both branches childs
    Insert_Element(&root,20);
    Insert_Element(&root,15);
    Insert_Element(&root,10);
    Insert_Element(&root,17);
    Insert_Element(&root,16);
    Insert_Element(&root,19);
    Insert_Element(&root,18);
    Insert_Element(&root,7);
    Insert_Element(&root,8);
    Insert_Element(&root,5);
    Insert_Element(&root,9);
    //Reverse_Removing(&root);
    Remove_Node(&root, 15);
    //Reverse_Removing(&root);
*/

    /*
    Insert_Element(&root,10);
    Insert_Element(&root,4);
    Insert_Element(&root,5);
    Insert_Element(&root,2);
    Insert_Element(&root,1);
    struct Node *tmp =Find_Node_by_ID(&root, 18);

    Insert_Element(&root,17);
    Insert_Element(&root,15);
    Insert_Element(&root,11);
    Insert_Element(&root,12);
    Insert_Element(&root,3);
    Insert_Element(&root,9);
    Insert_Element(&root,14);
    Insert_Element(&root,22);

*/

    return 0;
}

