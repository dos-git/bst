#include "bst.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node *Create_Element(int value)
{
    struct Node *new_element = (struct Node *)malloc(sizeof(struct Node));
    new_element->left_branch = NULL;
    new_element->right_branch = NULL;
    new_element->parent = NULL;
    new_element->key_value = value;
    return new_element;
}

int Compare_Keys(struct Node *element, int id_value)
{
    if (element == NULL){
        return -2;
    }
    if (element->key_value == id_value) return 0;
    else if (element->key_value > id_value)return -1;
    else return 1;
}

//struct Node *Return_Node(struct Node **root, int val, int key_val){
void Return_Node(struct Node **root, int comparision_state, int new_key_val){

    if (comparision_state < 0){
        if ((*root)->left_branch == NULL){   // enter new node
            (*root)->left_branch = Create_Element(new_key_val);
            (*root)->left_branch->parent = (*root);

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
        if ((*root)->right_branch == NULL){   // enter new node
            (*root)->right_branch = Create_Element(new_key_val);
            (*root)->right_branch->parent = (*root);
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

void Insert_Element(struct Node **root, int id_value)
{
    int state = 0;
    if ((*root) == NULL){
        (*root) = Create_Element(id_value);
        (*root)->parent = NULL;
    }else{
        state = Compare_Keys((*root), id_value);
        if (state != 0){
            Return_Node(&(*root), state, id_value);
        }else{
            printf("ALREADY EXIISTS\n\n");
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
    if((*root) == NULL){
        return NULL;
    }
    int state = 0;
    state = Compare_Keys((*root), key_id);
    if(state == -2) return NULL;
    else if (state == -1) return Find_Node_by_ID(&(*root)->left_branch, key_id);
    else if (state == 1) return Find_Node_by_ID(&(*root)->right_branch, key_id);
    else return (*root);
}


/*

0 - removed
1 - tree does not have nodes
*/
int Remove_Node(struct Node **root, int key_id)
{
    /* Tree is empty */
    if ((*root) == NULL) return -1;

    struct Node *start_node = NULL, *child = NULL, *root_right = NULL, *root_left = NULL, *rooot = NULL, *last_right = NULL, *last_left = NULL;
    start_node = Find_Node_by_ID(&(*root), key_id);

    /* Element was not found on tree */
    if (start_node == NULL) return -1;

    /* Remove first node */
    if (start_node->parent == NULL){
        /* Check if right branch is empty */
        if ((*root)->right_branch != NULL){

            root_right = start_node->right_branch;
            child = start_node->left_branch;
            child->parent = NULL;
            last_right = Get_Last_Right_Node(&child);

            last_right->right_branch = root_right;
            root_right->parent = last_right;
            (*root)->left_branch = NULL;
            (*root)->right_branch = NULL;
            free((*root));
            (*root) = child;

            return 0;
        }else{
            /* Left and right branch are empty */
            if ((*root)->left_branch == NULL){
                free((*root));
                (*root) = NULL;
                return 0;
            }else{
                /* Right branch is empyt, left is not */
                child = start_node->left_branch;
                child->parent = NULL;
                (*root)->left_branch = NULL;
                (*root)->right_branch = NULL;
                free((*root));
                (*root) = child;
                return 0;
            }
        }
    }
    /* Try to remove node that are level or more below from a first node */
    /* Check if left_branch is empty */
    if (start_node->left_branch == NULL){
        if(start_node->right_branch == NULL){
            /* Left and right branch are empty */
            if(start_node->parent->left_branch != NULL) start_node->parent->left_branch = NULL;
            else start_node->parent->right_branch = NULL;
            start_node->parent == NULL;
            free(start_node);
            return 0;
        }else{
            /* Left branch is empty, right is not */
            root_right = start_node->right_branch;
            root_left = start_node->left_branch;
            if(start_node->parent->left_branch != NULL){
                if (root_left == NULL){
                    start_node->parent->left_branch = root_right;
                    root_right->parent = start_node->parent;
                }
            }else{
                root_right->parent = start_node->parent;    // if root_right != null
                start_node->parent->right_branch = root_right;
            }
            start_node->parent = NULL;
            start_node->left_branch = NULL;
            start_node->right_branch = NULL;
            free(start_node);
        }
    }else{
        if(start_node->right_branch == NULL){
        /* Left branch is not empty, right branch is empty */
            root_left = start_node->left_branch;
            if(start_node->parent->left_branch != NULL){
                start_node->parent->left_branch = root_left;
                }
            else{
                start_node->parent->right_branch = root_left;
            }
            root_left->parent = start_node->parent;
            start_node->parent = NULL;
            free(start_node);
            return 0;

        }else {
        /* Left branch is not empty, Right branch is not empty */
            int start_val = start_node->key_value;
            root_right = start_node->right_branch;
            root_left = start_node->left_branch;
            rooot = start_node->parent;
            /* Check which parent branch left or right pointer start node->parent refers */
            if(start_node->parent->left_branch != NULL){
            /* Parent's node refers to the left branch */
                /* Here is continuation of the main check */
                if(start_node->parent->left_branch->key_value == start_node->key_value){
                    rooot->left_branch = root_left;
                    root_left->parent = rooot;
                    last_right = Get_Last_Right_Node(&root_left);
                    last_right->right_branch = root_right;
                    root_right->parent = last_right;
                    free(start_node);
                    return 0;
                }else{ //TODO add case for
                    /* Parent's node refers to the right branch */
                    rooot->right_branch = root_left;
                    root_left->parent = rooot;
                    last_right = Get_Last_Right_Node(&root_left);
                    last_right->right_branch = root_right;
                    root_right->parent = last_right;
                    free(start_node);
                    return 0;
                }
            }else{
                /* Parent's node refers to the right branch */
                rooot->right_branch = root_left;
                root_left->parent = rooot;
                last_right = Get_Last_Right_Node(&root_left);
                last_right->right_branch = root_right;
                root_right->parent = last_right;
                free(start_node);
                return 0;
            }
        }
    }
}


/*
Reverse_Removing -  removes tree's nodes from a given starting point node.
                    Function follows the rule(*) - "check the most left branch
                    for a node removal", so it will start removing from the
                    most faraway left node.
*/
struct Node *Reverse_Removing(struct Node **root){

    struct Node *tmp;
    /* main root taken for removal should have all pointers equal NULL */
    if ((*root) == NULL) { printf("RROOOOTT is NNUULLL\n"); return (*root); }

    if ( ((*root)->parent == NULL)  &&  ((*root)->left_branch == NULL) && ((*root)->right_branch == NULL) ) {
        free((*root));
        (*root) = NULL;
        tmp = NULL;
        return (*root);
    }
    /* left branch is NULL */
    if((*root)->left_branch == NULL){
        if((*root)->right_branch == NULL){
            int val = (*root)->key_value;
            tmp = (*root)->parent;
            (*root)->parent = NULL;

            if(tmp->left_branch != NULL){
                if (tmp->left_branch->key_value == val) {
                    free((*root));
                    (*root) = NULL;
                    tmp->left_branch = NULL;
                }
                else {      //  TODO this is probably not needed <<<<<<<<<<<<<<<<<<<<<<<<<<<< check it out
                    free((*root));
                    (*root) = NULL;
                    tmp->right_branch = NULL;
                    }
            }  else if((tmp->right_branch != NULL) && (tmp->right_branch->key_value == val)){
                    free((*root));
                    (*root) = NULL;
                    tmp->right_branch = NULL;
            }
            return Reverse_Removing(&tmp);

        }else{
            /* left branch node is NULL but right has some node */
            return Reverse_Removing(&(*root)->right_branch);
        }
    }else{
        /* continue the rule(*) in order to find the end of tree */
        return Reverse_Removing(&(*root)->left_branch);
    }
}

/*
#Get_Last_Right_Node - returns the last node localized on the right branch
                        of a given tree's node.
*/
struct Node *Get_Last_Right_Node(struct Node **root){
    // check if root is not null
    if((*root)->right_branch != NULL) return Get_Last_Right_Node(&(*root)->right_branch);
    else return (*root);
}

/*
#Get_Last_Left_Node - returns the last node localized on the left branch
                      of a given tree's node.
*/
struct Node *Get_Last_Left_Node(struct Node **root){
    printf("get last... %d\n", (*root)->key_value);

    // check if root is not null
    if((*root)->left_branch != NULL) return Get_Last_Left_Node(&(*root)->left_branch);
    else return (*root);
}

void PP(struct Node **node)
{
    if((*node) != NULL){
        printf("AFTERR PARENT %p %d", (*node), (*node)->key_value);
        if((*node)->left_branch != NULL){
             printf(" LEFT  %p %d ", (*node)->left_branch,(*node)->left_branch->key_value);
        }else printf(" LEFT  %p", (*node)->left_branch);

        if((*node)->right_branch != NULL){
             printf(" RIGHT %p %d ", (*node)->right_branch,(*node)->right_branch->key_value);
        }else printf(" RIGHT %p", (*node)->right_branch);

    }else printf("PARENT NULL\n");
    printf("\n");

}


void PRINT_ROOT_AND_PARENT(struct Node **root){

    if((*root) == NULL){
        printf("\nROOT IS NULLLLLLLLLL\n");
    }else{
        printf("ROOT    %p  %d", (*root), (*root)->key_value);
        if((*root)->parent == NULL){
            printf("\nPARENT IS NULLLLLLLLLL\n");
        }else{
            printf("\nPARENT  %p  %d\n", (*root)->parent, (*root)->parent->key_value);
        }
    }
}

