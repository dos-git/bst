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
    printf("Creating NEW ELEMENT %d\n\n", value);

    return new_element;
}

int Compare_Keys(struct Node *element, int id_value)
{
    printf("Comparing %d : %d\n", element->key_value, id_value);
    if (element->key_value == id_value) return 0;
    else if (element->key_value > id_value)return -1;
    else return 1;
}

//struct Node *Return_Node(struct Node **root, int val, int key_val){
void Return_Node(struct Node **root, int comparision_state, int new_key_val){

    if (comparision_state < 0){
    printf("\t<<<<\n");
        if ((*root)->left_branch == NULL){   // enter new node
            (*root)->left_branch = Create_Element(new_key_val);
            (*root)->parent = NULL;

        }
        else {
            comparision_state = Compare_Keys((*root)->left_branch, new_key_val);
            if (comparision_state != 0){
                Return_Node(&(*root)->left_branch, comparision_state, new_key_val);
            }else{
                printf("Element exist!!!\n");
            }
        }
    }else{
        printf("\t>>>>\n");
        if ((*root)->right_branch == NULL){   // enter new node
            (*root)->right_branch = Create_Element(new_key_val);
            (*root)->parent = NULL;
        }
        else{
            comparision_state = Compare_Keys((*root)->right_branch, new_key_val);
            if (comparision_state != 0){
                Return_Node(&(*root)->right_branch, comparision_state, new_key_val);
            }else{
                printf("Element exist!!!\n");
            }
        }
    }
}

int Insert_Element(struct Node **root, int id_value)
{
    int state = 0;
    struct Node *tmp = NULL;
    if ((*root) == NULL){
        (*root) = Create_Element(id_value);
        (*root)->parent = NULL;
        printf("First Element\n");
        return 0;
    }else{
        state = Compare_Keys((*root), id_value);
        if (state != 0){
            Return_Node(&(*root), state, id_value);
        }else{
            printf("ALREADY EXIISTS\n\n");
            return 0;
        }
    }
}

/*
#Check_Branches_for_Nodes - checks if node has left or right branch
*/
int Check_Branches_for_Nodes(struct Node *root)
{
    if ((root->left_branch == NULL) && (root->right_branch == NULL)) return 0;
    else if (root->left_branch != NULL) return -1;
    else return 1;
}

/*
#Find_Node_by_ID - searchs for a node defined by a given key_id
*/
struct Node *Find_Node_by_ID(struct Node **root, int key_id)
{
    printf("Finding...\n");
    int state = 0;
    state = Compare_Keys((*root), key_id);
    if (state == -1) return Find_Node_by_ID(&(*root)->left_branch, key_id);
    else if (state == 1) return Find_Node_by_ID(&(*root)->right_branch, key_id);
    else return (*root);
}


struct Node *Remove_Node(struct Node **root, int key_id)
{
    struct Node *start_node = NULL;
    start_node = Find_Node_by_ID(&(*root), key_id);

    if (start_node->parent->left_branch->key_value == key_id)
        start_node->parent->left_branch == NULL;
    else
        start_node->parent->right_branch == NULL;
    start_node->parent = NULL;


}

struct Node *Reverse_Removing(struct Node **root)
{
    if ((*root)->parent == NULL){
        free((*root)->parent);
    }

    if((*root)->left_branch == NULL){
        if((*root)->right_branch == NULL){
            if((*root)->parent->left_branch->key_value == (*root)->key_value)
            // remove left
                free((*root)->parent->left_branch);
            else
            // remove right
                free((*root)->parent->right_branch);
            return NULL;
        }else{
            return (*root)->right_branch;
        }
    }
    else return (*root)->left_branch;
}

