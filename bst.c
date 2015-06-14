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
    if (element->key_value == id_value) return 0;
    else if (element->key_value < id_value)return -1;
    else return 1;
}

struct Node *Return_Node(struct Node **root, int val, int key_val){

    if (val < 0){
        if ((*root)->left_branch == NULL){   // enter new node
            (*root)->left_branch = Create_Element(key_val);
            return 0;
        }
        else return (*root)->left_branch;
    }else{
        if ((*root)->right_branch == NULL){   // enter new node
            (*root)->right_branch = Create_Element(key_val);
            return 0;
        }
        else return (*root)->right_branch;
    }
}

void Insert_Element(struct Node **root, int id_value)
{
    int a = 0;
    int state = 0;
    struct Node *tmp = NULL;
    printf("BEGIN ADR %p %p\n", (void *)&root, root);
    if ((*root) == NULL){
        (*root) = Create_Element(id_value);
        printf("First Element\n");
        printf("BEGIN ADR %p %p\n", (void *)&root, root);
    }else if (*root != NULL){
        printf("Second Element\n");
        state = Compare_Keys(&(*root), id_value);
        tmp = Return_Node(&(*root), state, id_value);
    }else{
        (*root) = Create_Element(id_value);
    }
    /*
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
    */
}
