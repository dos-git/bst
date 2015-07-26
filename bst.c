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
    if((*root) == NULL){
        printf("FINDINGGGGGGGGGG NULLLLLLLLLLLL\n");

        return NULL;
    }
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
    /* tree is empty */
    if ((*root) == NULL) return -1;

    printf("\t\t\t\t\tREMOVE NODE :  ");
    struct Node *start_node = NULL, *child = NULL, *root_right = NULL, *root_left = NULL, *rooot = NULL, *last_right = NULL, *last_left = NULL;
    start_node = Find_Node_by_ID(&(*root), key_id);

    /* element was not found on tree */
    if (start_node == NULL) return -1;

    printf("\t\tBEG LEFT  : %p\n",start_node->left_branch );
    printf("\t\tBEG RIGHT : %p\n",start_node->right_branch );

    /* remove first node */
    if (start_node->parent == NULL){
        printf("REMOVE: MAIN ROOT NODE\n");
        if ((*root)->right_branch != NULL){
            printf("REMOVE: R_B NOT NULL\n");

            root_right = start_node->right_branch;
            child = start_node->left_branch;
            child->parent = NULL;
            last_right = Get_Last_Right_Node(&child);

            printf("REMOVE: LAST RIGHT VALUE      %d\n", last_right->key_value);
            printf("REMOVE: LAST RIGHT BRANCH      %p\n", last_right->right_branch);
            printf("REMOVE: ROOT_RIGHT       %p\n", root_right);

            last_right->right_branch = root_right;
            root_right->parent = last_right;
            //last_right->right_branch = root_right;
            (*root)->left_branch = NULL;
            (*root)->right_branch = NULL;
            free((*root));
            printf("REMOVE: Child valueeeee   %d\n", child->right_branch->right_branch->key_value);
            printf("REMOVE: Child valueeeee   %d\n", child->right_branch->right_branch->right_branch->key_value);
            (*root) = child;

            return 0;
        }else{
            printf("REMOVE: R_B IS NULL\n");
            /* left and right branch are NULL */
            if ((*root)->left_branch == NULL){
                printf("REMOVE: L_B IS NULL\n");
                free((*root));
                (*root) = NULL;
                return 0;
            }else{
                printf("REMOVE: R_B IS NOT NULL\n");
                /* right branch is null, left is not */
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

    if (start_node->left_branch == NULL){
        printf("RR: LEFT == NULL\n");
        if(start_node->right_branch == NULL){
            printf("RR: RIGHT == NULL\n");
            if(start_node->parent->left_branch != NULL) start_node->parent->left_branch = NULL;
            else start_node->parent->right_branch = NULL;
            start_node->parent == NULL;
            printf("RR: FREED %d\n", start_node->key_value);
            free(start_node);
        }else{
            printf("RR: RIGHT != NULL\n");
            root_right = start_node->right_branch;
            if(start_node->parent->left_branch != NULL)
                start_node->parent->left_branch = root_right;
            else{
                printf("HHHHHHHHHHHHHHHHHHHHHHHHH\n");  // TODO remove..........
                start_node->parent->right_branch = root_right;
                }
            root_right->parent = start_node->parent;
            start_node->parent = NULL;

            printf("RR: FREED %d\n", start_node->key_value);
            free(start_node);
        }


    }else{
        printf("RR: LEFT != NULL\n");
        if(start_node->right_branch == NULL){
            printf("RR: RIGHT == NULL\n");
            root_left = start_node->left_branch;
            if(start_node->parent->left_branch != NULL){
                printf("HHHHHHHHHHHHHHHHHHHHHHHHH  11111111111111\n");  // TODO remove..........
                start_node->parent->left_branch = root_left;
                }
            else{
                printf("HHHHHHHHHHHHHHHHHHHHHHHHH 222222222222222\n");  // TODO remove..........
                start_node->parent->right_branch = root_left;
                }
                root_left->parent = start_node->parent;
                start_node->parent = NULL;

                printf("RR: FREED %d\n", start_node->key_value);
                free(start_node);

        }else {
            printf("RR: RIGHT != NULL\n");
            int val = start_node->key_value;
            rooot = start_node->left_branch;
            root_right = start_node->right_branch;
            last_right = Get_Last_Right_Node(&rooot);
            if(rooot->parent->left_branch->key_value = val){
                printf("RR: ROOOT LEFT\n");

                start_node->parent->left_branch = rooot;
                rooot->parent = start_node->parent;
                last_right->right_branch = start_node->right_branch;

                start_node->right_branch->parent = last_right;
                free(start_node);
            }else{
                printf("RR: ROOOT RIGHT\n");
            }


        }
    }


/*
    if (start_node->left_branch != NULL){
        printf("REMOVE: L_B IS NOT NULL\n");

        root_right = start_node->right_branch;
        child = start_node->left_branch;
        printf("REMOVE: CHILD %d\n", child->key_value);
        child->parent = start_node->parent;
        printf("REMOVE: CHILD  PARENT %d\n", child->parent->key_value);
        printf("REMOVE: STSRT_NODE PARENT %d\n", start_node->parent->key_value);
        start_node->parent->left_branch = child;
        //start_node->parent->right_branch = child;
        printf("REMOVE: S_NODE PARENT LEFT %d\n", start_node->parent->left_branch->key_value);
        last_right = Get_Last_Right_Node(&child);
        printf("The LAST EXISTS!!!!!!!!!!!!!!\n");
        printf("REMOVE: LAST_RIGHT %d\n", last_right->key_value);

        if (root_right != NULL){
        printf("REMOVE: ROOT_RIGHT %d\n", root_right->key_value);
            printf("REMOVE: INSIDE>>>>>>>>>>>>>>>>>\n");
            last_right->right_branch = root_right;
            root_right->parent = last_right;
            root_right->left_branch = NULL;
        }else  start_node->parent->right_branch = NULL;


        printf("REMOVE: pooooooooooo\n");
        start_node->left_branch = NULL;
        start_node->right_branch = NULL;
        start_node->parent = NULL;

        free(start_node);
        start_node = NULL;

        return 0;
    }else{
 /*
        /* left branch is null */
 /*
        printf("REMOVE: L_B IS NULL\n");
      //  printf("Child is nULLL!\n");
        if(start_node->right_branch != NULL){
            printf("REMOVE: R_B IS NOT NULL\n");
            root_left = start_node->right_branch;
            child = start_node->right_branch;
            child->parent = start_node->parent;
            start_node->parent->right_branch = child;
            last_left = Get_Last_Left_Node(&child);
            last_left->left_branch = root_left;
            root_left->parent = last_left;

            start_node->left_branch = NULL;
            start_node->right_branch = NULL;
            start_node->parent = NULL;

            free(start_node);
            start_node = NULL;
            return 0;
        }else{
            printf("REMOVE: R_B IS NULL\n");

            if ( (start_node->parent->left_branch != NULL) &&
                (start_node->parent->left_branch->key_value == start_node->key_value) ) {
                    printf("HERERERE\n");
                    start_node->parent->left_branch = NULL;
            }

            if ( (start_node->parent->right_branch != NULL) &&
                (start_node->parent->right_branch->key_value == start_node->key_value) ) {
                    printf("HERERERER 2\n");
                    start_node->parent->right_branch = NULL;
            }

            start_node->parent = NULL;
            free(start_node);
            return 0;
        }
    }
*/
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

    printf("\t\tBEG LEFT  : %p\n",(*root)->left_branch );
    printf("\t\tBEG RIGHT : %p\n",(*root)->right_branch );
    if ( ((*root)->parent == NULL)  &&  ((*root)->left_branch == NULL) && ((*root)->right_branch == NULL) ) {
        printf("LAST FREE %d\n", (*root)->key_value);
        free((*root));
        (*root) = NULL;
        tmp = NULL;
        return (*root);
    }
    /* left branch is NULL */
    if((*root)->left_branch == NULL){
        printf("LEFT  NULL\n");
        if((*root)->right_branch == NULL){
            printf("RIGHT NULL\n");
            int val = (*root)->key_value;
            tmp = (*root)->parent;
            (*root)->parent = NULL;
            printf("TTTTTTTTTTMMMMMMMMMMMMMPPPPPPPPPPPPPPP %p\n", tmp);
            printf("TTTTTTTTTTMMMMMMMMMMMMMPPPPPPPPPPPPPPP %p\n", (*root)->parent);
            //tmp->left_branch = (*root)->parent->left_branch;
            //tmp->right_branch = (*root)->parent->right_branch;
            //printf("PARENT LEFT BRANCH %d\n", (*root)->parent->left_branch->key_value);

            printf("FREE RL : %d\n", val);


            if(tmp->left_branch != NULL){
                printf(">>ROOT_PARENT->LEFT != NULL\n"); ;
                if (tmp->left_branch->key_value == val) {
                    printf(">>ROOT_PARENT->LEFT %d %d\n", tmp->left_branch->key_value,val);
                    free((*root));
                    (*root) = NULL;
                    tmp->left_branch = NULL;
                    printf("%p\n", (*root));
                }
                else {      //  TODO this is probably not needed <<<<<<<<<<<<<<<<<<<<<<<<<<<< check it out
                    printf(">>ROOT_PARENT->LEFT == NULL\n");
                    printf(">>ROOT_PARENT->LEFT %d %d\n", tmp->left_branch->key_value,val);
                    free((*root));
                    (*root) = NULL;
                    tmp->right_branch = NULL;
                    printf("%p\n", (*root));
                    }
            }  else if((tmp->right_branch != NULL) && (tmp->right_branch->key_value == val)){
                    printf(">>ROOT_PARENT->RIGH != NULL\n"); ;

                    printf(">>ROOT_PARENT->RIGHT %d %d\n", tmp->right_branch->key_value,val); ;
                    free((*root));
                    (*root) = NULL;
                    tmp->right_branch = NULL;
                    printf("%p\n", (*root));

            }


            printf("ENDDDDDDDDDDDDDDDDD\n");
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

