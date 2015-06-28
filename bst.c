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

int Insert_Element(struct Node **root, int id_value)
{
    int state = 0;
    struct Node *tmp = NULL;
    if ((*root) == NULL){
        (*root) = Create_Element(id_value);
        printf("INSERT NODE            %p\n", (*root));
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


struct Node *RR(struct Node **root, int remove_id){

/*
    printf("\nRRRRRRRRRR BEGIN NODE   %p\n", (*root));
    printf("\nRRRRRRRRRR BEGIN NODE L %p\n", (*root)->left_branch);
    printf("\nRRRRRRRRRR BEGIN NODE R %p\n", (*root)->right_branch);
*/
    struct Node *tmp;
    if ( ((*root)->parent == NULL)  &&  ((*root)->left_branch == NULL) && ((*root)->right_branch == NULL) )  {
        printf("\nRemove that bitch   %p\n", (*root));
        free((*root));
        (*root) = NULL;
        return NULL;
    }
//    printf("\nRRRRRRRRRR BEGIN NODE 2222222 %p\n", (*root));
    printf("\n");
    if((*root)->left_branch == NULL){
        printf("LEFT  NULL\n");
        if((*root)->right_branch == NULL){
            printf("RIGHT NULL\n");
            printf("ROOOOOOT  %p PARENT  %p\n", (*root), (*root)->parent);
            tmp = (*root)->parent;                                      // do lewego cos jest nie tak.............
            printf("FREE      %p\n", (*root));

            //tmp->left_branch = NULL;
            //tmp->right_branch = NULL;
            if(tmp->right_branch != NULL && tmp->left_branch != NULL) {
                printf("NULLER NOT BOTH\n");
                tmp->left_branch = NULL;
            }
            else if(tmp->right_branch != NULL) {tmp->right_branch = NULL;
                printf("NULLER NOT RIGHT\n");
            }
            else {tmp->left_branch = NULL;
                printf("NULLER NOT LEFT\n");
            }
            //if((*root)->parent->right_branch == NULL) tmp->left_branch = NULL;
            //else tmp->right_branch = NULL;
            free((*root));
            (*root) = NULL;
            printf("BRANCH TMP NODE  %p LEFT  %p  RIGHT  %p\n", tmp, tmp->left_branch, tmp->right_branch);
            //if(tmp->right_branch != NULL) tmp->right_branch = NULL;
            //if(tmp->left_branch != NULL)  tmp->left_branch = NULL;
            //printf("BRANCH NODE            %p\n", (*root));
            //printf("BRANCH NODE PARENT %p\n", (*root)->parent);
            return RR(&tmp, 8);//
        }else{
            printf("LEFT  NULL RIGHT NOT NULL\n");
            return RR(&(*root)->right_branch, 8);
        }
    }
    else{
        printf("LEFT  NOT NULL\n");
        //return RR(&(*root)->right_branch, 8);
        return RR(&(*root)->left_branch, 8);
        /*
        if ((*root)->rigth_branch == NULL)){
            return RR(&(*root)->left_branch);
        }else{
            tmp = (*root)->parent;
            free((*root));
            (*root) = NULL;
            return NULL;
         }
        */
    }
}



struct Node *Reverse_Removing(struct Node **root)
{
     struct Node *tmp;
    printf("\nROOT %p\n", (*root));
    printf("\nVALUE %d\n", (*root)->key_value);
//    printf("LB %p\n", (*root)->left_branch);
//    printf("RB %p\n", (*root)->right_branch);
//    printf("PARENT VALUE %d\n", (*root)->parent->key_value);
  //  printf("PARENT VALUE %d\n", (*root)->parent);

//    if ( ((*root)->parent == 0)  && ((*root)->left_branch == 0) && ((*root)->right_branch == 0) )  {
    if ( ((*root)->parent == 0)  && ( ((*root)->left_branch == 0) || ((*root)->left_branch == NULL) ) )  {
    //if ( ((*root)->parent == 0) )  {
        printf("PARTEN NULL\n");
        //free((*root)->left_branch);
        //free((*root)->right_branch);
        free((*root));
        return NULL;
    }

    if((*root)->left_branch == NULL){
        if((*root)->right_branch == NULL){
            if((*root)->parent->left_branch->key_value == (*root)->key_value){
                printf("remove left\n");
                //printf("REMOVING  %p\n", (*root)->left_branch);
                printf("REMOVING  %p\n", (*root));
                tmp = (*root)->parent;
                //free((*root)->parent->left_branch);
                free((*root));
                (*root) = NULL;
                printf("ROOT LEFT %p\n", (*root)->left_branch);
                printf("ROOT %p\n", (*root));
                printf("\nVALUE %d\n", (*root)->key_value);
                //(*root)->parent->left_branch = NULL;
                return Reverse_Removing(&tmp);
                }
            else{
                printf("remove right\n");
                free((*root)->parent->right_branch);
                (*root)->parent->right_branch = NULL;
                return Reverse_Removing(&(*root)->parent);
                }
            return NULL;
        }else{
            return Reverse_Removing(&(*root)->right_branch);
        }
    }
    else{
        printf("PARENT NOT NULL\n");
        printf("LB %p\n", (*root)->left_branch);
         if (( (*root)->parent == 0 ) &&  ((*root)->left_branch == NULL)){
            printf("PARENT NULL\n");
            free((*root));
            (*root) = NULL;
            return NULL;
         }
        return Reverse_Removing(&(*root)->left_branch);
        }
}




void Rem_2(struct Node **root){

    //printf("\nROOT %p\n", (*root));
    //printf("\nROOT %d\n", (*root)->key_value);
    //free((*root)->left_branch);
    //free((*root)->right_branch);
    free(*root);
    (*root) = NULL;
    //printf("\nROOT %d\n", (*root)->key_value);
    //printf("\nROOT %d\n", (*root)->key_value);

}
