#include "bst.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node *Create_Element(int value)
{
    struct Node *new_element = (struct Node *)malloc(sizeof(struct Node));
    new_element->left_branch = NULL;
    new_element->right_branch = NULL;
    new_element->key_value = value;

    return new_element;
}

int Compare_Keys(struct Node *element, int id_value)
{
    if ((element->left_branch != NULL) && (element->key_value < id_value))
        return 1;
    else if ((element->left_branch != NULL) && (element->key_value > id_value))
        return -1;
    else return 0;
}

void Insert_Element(struct Node **root, int id_value)
{
    int a = 0;

    if (*root != NULL){
        printf("ROOT : %d, ID : %d\n", (*root)->key_value, id_value);
        a = Compare_Keys((*root), id_value);
        printf("res %d\n", a);
        if (a < id_value)
            (*root)->left_branch = Create_Element(id_value);
        else
            (*root)->right_branch = Create_Element(id_value);

    }else{
        (*root) = Create_Element(id_value);
    }
}
