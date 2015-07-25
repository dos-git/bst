#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"
#include "bst.h"
#include "bst.c"

/*
#init_suit - the suite initialization function.
             Here we can do some stuff that help us durin a test, i.e try to
             open a file which we will be testing in our test function.
             Returns zero on success, non-zero otherwise.
*/
int init_suite(void)  { return 0; }

/*

#clean_suite - the suite cleanup function.
               Starts clean up procedure if there is somehing to be done,
               i.e. close a file, free memory etc.
               Returns zero on success, non-zero otherwise.
*/
int clean_suite(void) { return 0; }


/* ****************************************
                NIL
              /    \
            NIL    NIL
****************************************** */
void test_Empty_Tree_Removing_Elements(){
    puts("\n--------------------test_Empty_Tree_Removing_Elements--------------------\n\n");
    int res = 0;
    struct Node *root = NULL;
    root =  Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
    res = Remove_Node(&root, 10);
    CU_ASSERT(root == NULL);
    CU_ASSERT(res == -1);
}

/* ****************************************
                10
              /    \
            NIL    NIL
****************************************** */
void test_Tree_One_Node(){
    puts("\n--------------------test_Tree_One_Node--------------------\n\n");
    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);
    res = Remove_Node(&root, 10);
    CU_ASSERT(res == 0);
    CU_ASSERT(root == NULL);

    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);
    root =  Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
    CU_ASSERT(res == 0);

    /* remove node that does not exist */
    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);
    res = Remove_Node(&root, 1);
    CU_ASSERT(res == -1);
    CU_ASSERT_NOT_EQUAL(root, NULL);

    res = Remove_Node(&root, 10);
    CU_ASSERT(res == 0);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                10
              /    \
            7      NIL
          /   \
        NIL   NIL
****************************************** */
void test_LB_REVERSE_RMV_1(){
    puts("\n--------------------test_LB_REVERSE_RMV_1--------------------\n\n");
    struct Node *root = NULL;

    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 7);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->key_value == 7);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                10
              /    \
            7      NIL
          /   \
        5     NIL
       / \
    NIL   NIL
****************************************** */
void test_LB_REVERSE_RMV_2(){
    puts("\n--------------------test_LB_REVERSE_RMV_2--------------------\n\n");
    struct Node *root = NULL;

    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 7);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->key_value == 7);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);

    Insert_Element(&root, 5);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->key_value == 5);
    CU_ASSERT(root->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch == NULL);

    root = Reverse_Removing(&root);

    CU_ASSERT(root == NULL);
}

/* ****************************************
                10
              /    \
            7      NIL
          /   \
        5     NIL
       / \
      3   NIL
     / \
   NIL NIL
****************************************** */
void test_LB_REVERSE_RMV_3(){
    puts("\n--------------------test_LB_REVERSE_RMV_3--------------------\n\n");
    struct Node *root = NULL;

    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 7);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->key_value == 7);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);

    Insert_Element(&root, 5);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->key_value == 5);
    CU_ASSERT(root->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 3);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->key_value == 3);
    CU_ASSERT(root->left_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                15
              /    \
            7      NIL
          /   \
        5     NIL
       / \
      3   4
     / \ / \
    N  N N  N
****************************************** */
void test_LB_REVERSE_RMV_4(){
    puts("\n--------------------test_LB_REVERSE_RMV_4--------------------\n\n");
    struct Node *root = NULL;

    Insert_Element(&root, 15);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 15);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 7);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->key_value == 7);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);

    Insert_Element(&root, 5);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->key_value == 5);
    CU_ASSERT(root->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 3);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->key_value == 3);
    CU_ASSERT(root->left_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 6);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch->key_value == 6);
    CU_ASSERT(root->left_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                15
              /    \
            7      NIL
          /   \
        5      10
       / \     / \
      3   4   N   N
     / \ / \
    N  N N  N
****************************************** */
void test_LB_REVERSE_RMV_5(){
    puts("\n--------------------test_LB_REVERSE_RMV_5--------------------\n\n");
    struct Node *root = NULL;

    Insert_Element(&root, 15);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 15);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 7);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->key_value == 7);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);

    Insert_Element(&root, 5);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->key_value == 5);
    CU_ASSERT(root->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->right_branch->key_value == 10);
    CU_ASSERT(root->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 3);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->key_value == 3);
    CU_ASSERT(root->left_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 6);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch->key_value == 6);
    CU_ASSERT(root->left_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                15
              /    \
            7      NIL
          /   \
        5      10
       / \     / \
      3   4   8   N
     / \ / \ / \
    N  N N  NN  N
****************************************** */
void test_LB_REVERSE_RMV_6(){
    puts("\n--------------------test_LB_REVERSE_RMV_6--------------------\n\n");
    struct Node *root = NULL;

    Insert_Element(&root, 15);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 15);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 7);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->key_value == 7);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);

    Insert_Element(&root, 5);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->key_value == 5);
    CU_ASSERT(root->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->right_branch->key_value == 10);
    CU_ASSERT(root->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 8);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->right_branch->left_branch->key_value == 8);
    CU_ASSERT(root->left_branch->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 3);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->key_value == 3);
    CU_ASSERT(root->left_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 6);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch->key_value == 6);
    CU_ASSERT(root->left_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                15
              /    \
            7      NIL
          /   \
        5      10
       / \     / \
      3   4   8   N
     / \ / \ / \
    N  N N  NN  N
****************************************** */
void test_LB_REVERSE_RMV_7(){
    puts("\n--------------------test_LB_REVERSE_RMV_7--------------------\n\n");

    struct Node *root = NULL;

    Insert_Element(&root, 15);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 15);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 7);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->key_value == 7);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);

    Insert_Element(&root, 5);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->key_value == 5);
    CU_ASSERT(root->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->right_branch->key_value == 10);
    CU_ASSERT(root->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 8);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->right_branch->left_branch->key_value == 8);
    CU_ASSERT(root->left_branch->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 3);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->key_value == 3);
    CU_ASSERT(root->left_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 6);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch->key_value == 6);
    CU_ASSERT(root->left_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                15
              /    \
            7      NIL
          /   \
        5      10
       / \     / \
      3   4   N   13
     / \ / \      / \
    N  N N  N    N   N
****************************************** */
void test_LB_REVERSE_RMV_8(){
    puts("\n--------------------test_LB_REVERSE_RMV_8--------------------\n\n");

    struct Node *root = NULL;

    Insert_Element(&root, 15);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 15);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 7);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->key_value == 7);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);

    Insert_Element(&root, 5);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->key_value == 5);
    CU_ASSERT(root->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->right_branch->key_value == 10);
    CU_ASSERT(root->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 13);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch->key_value == 13);
    CU_ASSERT(root->left_branch->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 3);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->key_value == 3);
    CU_ASSERT(root->left_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 6);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch->key_value == 6);
    CU_ASSERT(root->left_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                15
              /    \
            7      NIL
          /   \
        5      10
       / \     / \
      3   4   N   13
     / \ / \      / \
    N  N N  N    N   14
                    /  \
                   N    N
****************************************** */
void test_LB_REVERSE_RMV_9(){
    puts("\n--------------------test_LB_REVERSE_RMV_9--------------------\n\n");

    struct Node *root = NULL;

    Insert_Element(&root, 15);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 15);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 7);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->key_value == 7);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);

    Insert_Element(&root, 5);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->key_value == 5);
    CU_ASSERT(root->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->right_branch->key_value == 10);
    CU_ASSERT(root->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 13);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch->key_value == 13);
    CU_ASSERT(root->left_branch->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 14);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch->right_branch->key_value == 14);
    CU_ASSERT(root->left_branch->right_branch->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 3);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->key_value == 3);
    CU_ASSERT(root->left_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 6);
    CU_ASSERT_NOT_EQUAL(root->left_branch, NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch->key_value == 6);
    CU_ASSERT(root->left_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}


/* ****************************************
                15
              /    \
            N      22
                  /   \
                 N     N
****************************************** */
void test_RB_REVERSE_RMV_1(){
    puts("\n--------------------test_RB_REVERSE_RMV_1--------------------\n\n");

    struct Node *root = NULL;

    Insert_Element(&root, 15);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 15);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 22);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                15
              /    \
             N     22
                  /   \
                 N    28
                     /  \
                    N    N
****************************************** */
void test_RB_REVERSE_RMV_2(){
    puts("\n--------------------test_RB_REVERSE_RMV_2--------------------\n\n");

    struct Node *root = NULL;

    Insert_Element(&root, 15);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 15);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 22);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 28);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->key_value == 28);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                15
              /    \
             N     22
                  /   \
                 N    28
                     /  \
                    N    38
                        /  \
                       N    N
****************************************** */
void test_RB_REVERSE_RMV_3(){
    puts("\n--------------------test_RB_REVERSE_RMV_3--------------------\n\n");

    struct Node *root = NULL;

    Insert_Element(&root, 15);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 15);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 22);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 28);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->key_value == 28);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 38);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->key_value == 38);
    CU_ASSERT(root->right_branch->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                15
              /    \
             N     22
                  /   \
                 N    28
                     /  \
                    24    38
                   / \   / \
                  N   N N   N
****************************************** */
void test_RB_REVERSE_RMV_4(){
    puts("\n--------------------test_RB_REVERSE_RMV_4--------------------\n\n");

    struct Node *root = NULL;

    Insert_Element(&root, 15);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 15);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 22);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 28);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->key_value == 28);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 24);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->left_branch->key_value == 24);
    CU_ASSERT(root->right_branch->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 38);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->key_value == 38);
    CU_ASSERT(root->right_branch->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                15
              /    \
             N     22
                  /   \
                 17    28
                / \   /  \
               N   N 24   38
                     / \   / \
                    N   N N   N
****************************************** */
void test_RB_REVERSE_RMV_5(){
    puts("\n--------------------test_RB_REVERSE_RMV_5--------------------\n\n");

    struct Node *root = NULL;

    Insert_Element(&root, 15);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 15);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 22);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 17);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->left_branch->key_value == 17);
    CU_ASSERT(root->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch == NULL);


    Insert_Element(&root, 28);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->key_value == 28);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 24);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->left_branch->key_value == 24);
    CU_ASSERT(root->right_branch->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 38);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->key_value == 38);
    CU_ASSERT(root->right_branch->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                15
              /    \
             N     22
                  /   \
                 17    28
                / \   /  \
               16  N 24   38
              /  \  / \   / \
             N   N  N  N N   N
****************************************** */
void test_RB_REVERSE_RMV_6(){
    puts("\n--------------------test_RB_REVERSE_RMV_6--------------------\n\n");

    struct Node *root = NULL;

    Insert_Element(&root, 15);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 15);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 22);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 17);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->left_branch->key_value == 17);
    CU_ASSERT(root->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 16);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->left_branch->left_branch->key_value == 16);
    CU_ASSERT(root->right_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 28);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->key_value == 28);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 24);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->left_branch->key_value == 24);
    CU_ASSERT(root->right_branch->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 38);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->key_value == 38);
    CU_ASSERT(root->right_branch->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                15
              /    \
             N     22
                  /   \
                 17    28
                / \   /  \
               N 19   24   38
                 /\   /\   /\
                N  N N  N N  N
****************************************** */
void test_RB_REVERSE_RMV_7(){
    puts("\n--------------------test_RB_REVERSE_RMV_7--------------------\n\n");

    struct Node *root = NULL;

    Insert_Element(&root, 15);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 15);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 22);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 17);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->left_branch->key_value == 17);
    CU_ASSERT(root->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 19);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch->key_value == 19);
    CU_ASSERT(root->right_branch->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 28);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->key_value == 28);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 24);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->left_branch->key_value == 24);
    CU_ASSERT(root->right_branch->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 38);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->key_value == 38);
    CU_ASSERT(root->right_branch->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                15
              /    \
             N     22
                  /   \
                 17    28
                / \   /  \
               N 19   24   38
                 /\   /\   /\
                18 N N  N N  N
                /\
               N  N
****************************************** */
void test_RB_REVERSE_RMV_8(){
    puts("\n--------------------test_RB_REVERSE_RMV_8--------------------\n\n");

    struct Node *root = NULL;

    Insert_Element(&root, 15);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 15);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 22);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 17);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->left_branch->key_value == 17);
    CU_ASSERT(root->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 19);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch->key_value == 19);
    CU_ASSERT(root->right_branch->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 18);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch->left_branch->key_value == 18);
    CU_ASSERT(root->right_branch->left_branch->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch->left_branch->right_branch == NULL);


    Insert_Element(&root, 28);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->key_value == 28);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 24);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->left_branch->key_value == 24);
    CU_ASSERT(root->right_branch->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 38);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->key_value == 38);
    CU_ASSERT(root->right_branch->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}



/* ****************************************
                10
              /    \
            NIL    22
                  /   \
                21   28x
****************************************** */
void test_RIGHT_BRANCH_3(){

    int res = 0;
    struct Node *root = NULL;

    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 22);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 21);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch-> left_branch->key_value == 21);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 28);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->key_value == 28);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);
    Remove_Node(&root, 28);
    Reverse_Removing(&root);
}

/* ****************************************
                10
              /    \
            NIL    22
                  /   \
                21   28x
****************************************** */
void test_RIGHT_BRANCH_4(){

    int res = 0;
    struct Node *root = NULL;

    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 22);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 21);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch-> left_branch->key_value == 21);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 28);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->key_value == 28);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);
    Remove_Node(&root, 21);
    Reverse_Removing(&root);
}

/* ****************************************
                10
              /    \
            NIL    22
                  /   \
                21   28x
****************************************** */
void test_RIGHT_BRANCH_5(){

    int res = 0;
    struct Node *root = NULL;

    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 22);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 21);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch-> left_branch->key_value == 21);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 19);

    Insert_Element(&root, 28);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->key_value == 28);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);
    Remove_Node(&root, 28);
    Reverse_Removing(&root);
}

/* ****************************************
                10
              /    \
            NIL    22
                  /   \
                20x    28
                /
              19
****************************************** */
void test_RIGHT_BRANCH_6(){

    int res = 0;
    struct Node *root = NULL;

    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 22);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 20);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch-> left_branch->key_value == 20);
    CU_ASSERT(root->right_branch->right_branch == NULL);
    Insert_Element(&root, 19);
    Insert_Element(&root, 28);
    CU_ASSERT(root->right_branch->key_value == 22);
    printf("RIGHT LEFT %d\n",root->right_branch->left_branch->key_value );
    CU_ASSERT(root->right_branch->left_branch->left_branch->key_value == 19);
    CU_ASSERT(root->right_branch->right_branch->key_value == 28 );

    Insert_Element(&root, 29);
    Remove_Node(&root, 20);
    CU_ASSERT(root->right_branch->key_value == 22);
    CU_ASSERT(root->right_branch->left_branch->key_value == 19);
    CU_ASSERT(root->right_branch->right_branch->key_value == 28 );
    Reverse_Removing(&root);
}


//void test_Remove_Node_1(){


/* ****************************************
                10
              /    \
            7        18
          /   \    /    \
         5     8  17     19
       /   \   \           \
      3     6   9           21
                           /
                          20
****************************************** */
void test_Remove_Node_1(){
    struct Node *root = NULL;
    printf("\nSTARTTTTttttttttttttttTTTTTTTT \n%p\n", root);
    Insert_Element(&root, 10);
    Insert_Element(&root, 7);
    Insert_Element(&root, 8);
    Insert_Element(&root, 5);
    Insert_Element(&root, 3);
    Insert_Element(&root, 6);
    Insert_Element(&root, 8);
    Insert_Element(&root, 9);
    Remove_Node(&root, 7);
    Remove_Node(&root, 5);
    //CU_ASSERT(root->left_branch->key_value == 5);
    //CU_ASSERT(root->left_branch->left_branch->key_value == 3);
    root = Reverse_Removing(&root);
    //printf("\n\n\n%d\n\n\n", root->key_value);
    printf("\n\n\n%p\n\n\n", root);
    CU_ASSERT(root == NULL);

}

int Return_One(){ return 1; }
int Return_Two(){ return 2; }

void test_Return_One(){ CU_ASSERT(Return_One()== 1); }

int main(){

    CU_pSuite pSuite = NULL;

    /* Initialize CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add suite to registry */
    pSuite = CU_add_suite("Basic_Test_Suite", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add tests to suite */

    //if{

    if(
        /* testing left branch */
        (NULL == CU_add_test(pSuite, "test_Tree_One_Node", test_Tree_One_Node)) ||
        (NULL == CU_add_test(pSuite, "test_Empty_Tree_Removing_Elements", test_Empty_Tree_Removing_Elements)) ||
        (NULL == CU_add_test(pSuite, "test_LB_REVERSE_RMV_1", test_LB_REVERSE_RMV_1)) ||
        (NULL == CU_add_test(pSuite, "test_LB_REVERSE_RMV_2", test_LB_REVERSE_RMV_2)) ||
        (NULL == CU_add_test(pSuite, "test_LB_REVERSE_RMV_3", test_LB_REVERSE_RMV_3)) ||
        (NULL == CU_add_test(pSuite, "test_LB_REVERSE_RMV_4", test_LB_REVERSE_RMV_4)) ||
        (NULL == CU_add_test(pSuite, "test_LB_REVERSE_RMV_5", test_LB_REVERSE_RMV_5)) ||
        (NULL == CU_add_test(pSuite, "test_LB_REVERSE_RMV_6", test_LB_REVERSE_RMV_6)) ||
        (NULL == CU_add_test(pSuite, "test_LB_REVERSE_RMV_7", test_LB_REVERSE_RMV_7)) ||
        (NULL == CU_add_test(pSuite, "test_LB_REVERSE_RMV_8", test_LB_REVERSE_RMV_8)) ||
        (NULL == CU_add_test(pSuite, "test_LB_REVERSE_RMV_9", test_LB_REVERSE_RMV_9)) ||
        /* testing right branch */
        (NULL == CU_add_test(pSuite, "test_RB_REVERSE_RMV_1", test_RB_REVERSE_RMV_1)) ||
        (NULL == CU_add_test(pSuite, "test_RB_REVERSE_RMV_2", test_RB_REVERSE_RMV_2)) ||
        (NULL == CU_add_test(pSuite, "test_RB_REVERSE_RMV_3", test_RB_REVERSE_RMV_3)) ||
        (NULL == CU_add_test(pSuite, "test_RB_REVERSE_RMV_4", test_RB_REVERSE_RMV_4)) ||
        (NULL == CU_add_test(pSuite, "test_RB_REVERSE_RMV_5", test_RB_REVERSE_RMV_5)) ||
        (NULL == CU_add_test(pSuite, "test_RB_REVERSE_RMV_6", test_RB_REVERSE_RMV_6)) ||
        (NULL == CU_add_test(pSuite, "test_RB_REVERSE_RMV_7", test_RB_REVERSE_RMV_7)) ||
        (NULL == CU_add_test(pSuite, "test_RB_REVERSE_RMV_8", test_RB_REVERSE_RMV_8))
    ){

    //test_RB_REVERSE_RMV_1
//    if(NULL == CU_add_test(pSuite, "test_LEFT_BRANCH_1", test_LEFT_BRANCH_1)){
//    if(NULL == CU_add_test(pSuite, "test_RIGHT_BRANCH_1", test_RIGHT_BRANCH_1)){
        //if(NULL == CU_add_test(pSuite, "test_RIGHT_BRANCH_2", test_RIGHT_BRANCH_2)){
  /*
test_LB_REVERSE_RMV_4
  test_LB_REVERSE_RMV_1
        (NULL == CU_add_test(pSuite, "test_LEFT_BRANCH_1", test_LEFT_BRANCH_1)) ||
        (NULL == CU_add_test(pSuite, "test_RIGHT_BRANCH_1", test_RIGHT_BRANCH_1)) ||
        (NULL == CU_add_test(pSuite, "test_RIGHT_BRANCH_2", test_RIGHT_BRANCH_2)) ||
        (NULL == CU_add_test(pSuite, "test_RIGHT_BRANCH_3", test_RIGHT_BRANCH_3)) ||
        (NULL == CU_add_test(pSuite, "test_RIGHT_BRANCH_4", test_RIGHT_BRANCH_4)) ||
        (NULL == CU_add_test(pSuite, "test_RIGHT_BRANCH_5", test_RIGHT_BRANCH_5)) ||
        (NULL == CU_add_test(pSuite, "test_RIGHT_BRANCH_6", test_RIGHT_BRANCH_6)))
*/
        CU_cleanup_registry();
        return CU_get_error();
    }


    /* Run tests using Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");

/*
     // Run all tests using the automated interface - silence mode
    CU_automated_run_tests();
    CU_list_tests_to_file();
*/


    //Run all tests using the console interface - a new shell will be available
//    CU_console_run_tests();

    /* Clean up registry and return */
    CU_cleanup_registry();
    return CU_get_error();
}
