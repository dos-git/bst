#include "bst.h"
#include <stddef.h>

int main()
{
    struct Node *root = NULL, *tmp = NULL;
    //printf("SIZE ROOT %d\n", (int) sizeof(*root));

    Insert_Element(&root, 8);
    Insert_Element(&root, 19);

    Insert_Element(&root, 10);
    Insert_Element(&root, 20);
    Insert_Element(&root, 11);
    Insert_Element(&root, 12);

    //root->left_branch->parent = NULL;

    printf("ROOT       %p\n", root);
    printf("\nROOT VAL %d\n", root->key_value);
//    printf("ROOT       %p\n", root->right_branch);
//    printf("\nROOT VAL %d\n", root->right_branch->key_value);

    //root->right_branch->parent = NULL;
    RR(&root->right_branch, 19);

    //Rem_2(&root->right_branch);
    //Rem_2(&root);
/*
    if (root->right_branch != NULL){
        printf("REMOVE RIGHT ROOT..............\n");
        //free(root->right_branch);
    }
*/
    if (root != NULL){
        printf("REMOVE ROOT..............\n");
       // free(root);
    }


    return 0;
}
/*
    RR(&root->left_branch, 3);
    //printf("\nROOT %p\n", (*root));       ERROR JAK ROOT JEST NULL

    return 0;

//    printf("\nLEFT location %p\n", root->left_branch);
//    printf("\nLEFT %d\n", root->key_value);
    //printf("\nLEFT VAL %d\n", root->left_branch->key_value);


    printf("\nROOT AFTER %d\n", root);
    if(root){

        printf("NOT EMPTY\n");
       // free(root);
    }else  printf("EMPTY\n");

/*
    Insert_Element(&root, 8);
    Insert_Element(&root, 4);
    Insert_Element(&root, 3);
   // Insert_Element(&root, 6);
    struct Node *res = NULL;
    printf("BEGIN ROOT %p\n", root->left_branch);
    res = root->left_branch;
    root->left_branch = NULL;
    res->parent = NULL;
    res = Reverse_Removing(&res);

*/

    //free(root);
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
/*
    return 0;
}
*/
