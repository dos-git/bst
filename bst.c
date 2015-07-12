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
    printf("Creating NEW ELEMENT %d  %p\n", value, new_element);

    return new_element;
}

int Compare_Keys(struct Node *element, int id_value)
{
    printf("Comparing %d : %d\n", element->key_value, id_value);
    if (element == NULL){
        puts("NULLLLLLLLLLLLL!\n");
        return -2;
    }
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
        printf("\t>>>>\n");
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
        printf("INSERT NODE            %p\n", (*root));
        (*root)->parent = NULL;
        printf("First Element\n");
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
    printf("Finding...\n");
    int state = 0;
    state = Compare_Keys((*root), key_id);
    printf("STATE %d\n", state);
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
    struct Node *start_node = NULL, *child = NULL, *root_right = NULL, *last_right = NULL;
    start_node = Find_Node_by_ID(&(*root), key_id);

    /* tree is empty */
    if (start_node == NULL){
        return 1;
    }

    /* remove first node */
    if (start_node->parent == NULL){
        printf("Removing root node...\n");

        root_right = start_node->right_branch;
        child = start_node->left_branch;
        child->parent = NULL;
        last_right = Get_Last_Right_Node(&child);

        printf("LAST RIGHT VALUE      %d\n", last_right->key_value);
        printf("LAST RIGHT BRANCH      %p\n", last_right->right_branch);
        printf("ROOT_RIGHT       %p\n", root_right);

        last_right->right_branch = root_right;
        root_right->parent = last_right;
        //last_right->right_branch = root_right;
        (*root)->left_branch = NULL;
        (*root)->right_branch = NULL;
        free((*root));
        printf("Child valueeeee   %d\n", child->right_branch->right_branch->key_value);
        printf("Child valueeeee   %d\n", child->right_branch->right_branch->right_branch->key_value);
        (*root) = child;

        //Reverse_Removing(&child);

        return 0;
    }

    if (start_node->left_branch != NULL){
        child =  start_node->left_branch;
        start_node->parent->left_branch = child;
        child->parent = start_node->parent;
        start_node->parent = NULL;

        printf("RIGHT %d\n", start_node->right_branch->parent->key_value);
        start_node->right_branch->parent=NULL;
        printf("RIGHT %p\n", start_node->right_branch->parent);
        printf("RIGHT %d\n", start_node->right_branch->key_value);

        //Reverse_Removing(&start_node->right_branch);

        free(start_node);

        //Reverse_Removing(&child);
        return 0;
    }else{
        printf("Child is nULLL!\n");
        if(start_node->right_branch != NULL){
            // check if parent left is not null, if is take a right one
            child = start_node->right_branch;
            start_node->parent->left_branch = child;
            child->parent = start_node->parent;
            start_node->parent = NULL;
            free(start_node);
            return 0;
        }
    }


/*
    if (start_node->parent->left_branch->key_value == key_id)
        start_node->parent->left_branch == NULL;
    else
        start_node->parent->right_branch == NULL;
*/
    //start_node->parent = NULL;
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
    if ( ((*root)->parent == NULL)  &&  ((*root)->left_branch == NULL) && ((*root)->right_branch == NULL) ) {
        printf("\nRemove that bitch   %p\n", (*root));
        printf("FREE %d\n", (*root)->key_value);
        free((*root));
        (*root) = NULL;
        return NULL;
    }
    /* left branch is NULL */
    if((*root)->left_branch == NULL){
        printf("LEFT  NULL\n");
        if((*root)->right_branch == NULL){
            printf("RIGHT NULL\n");
            tmp = (*root)->parent;
            //(*root)->parent = NULL;
            printf("FREE %d\n", (*root)->key_value);
            free((*root));

            /* recursive algorithm recuires setting to NULL a branch's pointer that has
               pointed to a removed node */
            if (tmp->left_branch != NULL) tmp->left_branch = NULL;
            else tmp->right_branch = NULL;

            return Reverse_Removing(&tmp);
        }else{
            printf("LEFT  NULL RIGHT NOT NULL\n");
            /* left branch node is NULL but right has some node */
            return Reverse_Removing(&(*root)->right_branch);
        }
    }else{
        printf("LEFT  NOT NULL\n");
        /* continue the rule(*) in order to find the end of tree */
        return Reverse_Removing(&(*root)->left_branch);
    }
}

/*
#Get_Last_Right_Node - returns the last node localized on the right branch
                        of a given tree's node.
*/
struct Node *Get_Last_Right_Node(struct Node **root){
    printf("get last... %d\n", (*root)->key_value);
    if((*root)->right_branch != NULL) return Get_Last_Right_Node(&(*root)->right_branch);
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

