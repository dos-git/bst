#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"
#include "bst.h"
#include "bst.c"


char *lines_20 = "--------------------";
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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
                15
              /    \
             N     22
                  /   \
                 17    28
                / \   /  \
               N 19   24   38
                 /\   /\   /\
                18 N N  N 30  N
                /\       /  \
               N  N     N    N
****************************************** */
void test_RB_REVERSE_RMV_9(){
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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

    Insert_Element(&root, 30);
    CU_ASSERT_NOT_EQUAL(root->right_branch, NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->left_branch->key_value == 30);
    CU_ASSERT(root->right_branch->right_branch->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->left_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}


/* TESTING REMOVE_NODE */


/* ****************************************
                NIL
              /    \
            NIL    NIL
****************************************** */
void test_Empty_Tree_Remove_Node(){
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);


    int res = 0;
    struct Node *root = NULL;
    res = Remove_Node(&root, 10);
    CU_ASSERT(root == NULL);
    CU_ASSERT(res == -1);
}

/* ****************************************
                10
              /    \
            NIL    NIL
****************************************** */
void test_Tree_One_Node_Remove(){
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

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
            5x       N
           / \
          N   N
****************************************** */
void test_LB_REMOVE_NODE_1(){
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);


    Insert_Element(&root, 5);
    CU_ASSERT(root->left_branch->key_value == 5);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);

    res = Remove_Node(&root, 5);
    CU_ASSERT(res == 0);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                10
              /    \
            5x       N
           / \
          2   N
         / \
        N   N
****************************************** */
void test_LB_REMOVE_NODE_2(){
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 5);
    CU_ASSERT(root->left_branch->key_value == 5);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);

    Insert_Element(&root, 2);
    CU_ASSERT(root->left_branch->left_branch->key_value == 2);
    CU_ASSERT(root->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch == NULL);

    res = Remove_Node(&root, 5);
    CU_ASSERT(res == 0);
    CU_ASSERT(root->left_branch->key_value == 2);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);


    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                10
              /    \
            5x       N
           / \
          2   7
         / \ / \
        N  N N  N
****************************************** */
void test_LB_REMOVE_NODE_3(){
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 5);
    CU_ASSERT(root->left_branch->key_value == 5);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);

    Insert_Element(&root, 2);
    CU_ASSERT(root->left_branch->left_branch->key_value == 2);
    CU_ASSERT(root->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 7);
    CU_ASSERT(root->left_branch->right_branch->key_value == 7);
    CU_ASSERT(root->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch == NULL);

    res = Remove_Node(&root, 5);
    CU_ASSERT(res == 0);
    CU_ASSERT(root->left_branch->key_value == 2);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch != NULL);
    CU_ASSERT(root->left_branch->right_branch->key_value == 7);
    CU_ASSERT(root->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                10
              /    \
            5x       N
           / \
          2   7
         / \ / \
        N  4 N  N
          / \
         N   N
****************************************** */
void test_LB_REMOVE_NODE_4(){
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 5);
    CU_ASSERT(root->left_branch->key_value == 5);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);

    Insert_Element(&root, 2);
    CU_ASSERT(root->left_branch->left_branch->key_value == 2);
    CU_ASSERT(root->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 4);
    CU_ASSERT(root->left_branch->left_branch->right_branch->key_value == 4);
    CU_ASSERT(root->left_branch->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 7);
    CU_ASSERT(root->left_branch->right_branch->key_value == 7);
    CU_ASSERT(root->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch == NULL);

    res = Remove_Node(&root, 5);
    CU_ASSERT(res == 0);
    CU_ASSERT(root->left_branch->key_value == 2);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch != NULL);
    CU_ASSERT(root->left_branch->right_branch->key_value == 4);
    CU_ASSERT(root->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch != NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                16
              /    \
            8       N
           / \
          2   12
         / \ / \
        1  3 10x14x
       /\ /\ /\ /\
       N NN NN NN N
****************************************** */
void test_LB_REMOVE_NODE_5(){
printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 16);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 16);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 8);
    CU_ASSERT(root->left_branch->key_value == 8);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);


    Insert_Element(&root, 12);
    CU_ASSERT(root->left_branch->right_branch->key_value == 12);
    CU_ASSERT(root->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 2);
    CU_ASSERT(root->left_branch->left_branch->key_value == 2);
    CU_ASSERT(root->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 1);
    CU_ASSERT(root->left_branch->left_branch->left_branch->key_value == 1);
    CU_ASSERT(root->left_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 3);
    CU_ASSERT(root->left_branch->left_branch->right_branch->key_value == 3);
    CU_ASSERT(root->left_branch->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 10);
    CU_ASSERT(root->left_branch->right_branch->left_branch->key_value == 10);
    CU_ASSERT(root->left_branch->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 14);
    CU_ASSERT(root->left_branch->right_branch->right_branch->key_value == 14);
    CU_ASSERT(root->left_branch->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch->right_branch == NULL);

    res = Remove_Node(&root, 10);
    res = Remove_Node(&root, 14);


    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                16
              /    \
            8x       N
           / \
          N   12
             / \
            10 14
            /\ /\
            N NN N
****************************************** */
void test_LB_REMOVE_NODE_6(){
printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 16);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 16);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 8);
    CU_ASSERT(root->left_branch->key_value == 8);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);


    Insert_Element(&root, 12);
    CU_ASSERT(root->left_branch->right_branch->key_value == 12);
    CU_ASSERT(root->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 10);
    CU_ASSERT(root->left_branch->right_branch->left_branch->key_value == 10);
    CU_ASSERT(root->left_branch->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 14);
    CU_ASSERT(root->left_branch->right_branch->right_branch->key_value == 14);
    CU_ASSERT(root->left_branch->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch->right_branch == NULL);

    res = Remove_Node(&root, 8);
    CU_ASSERT(root->left_branch->key_value == 12);
    CU_ASSERT(root->left_branch->left_branch != NULL);
    CU_ASSERT(root->left_branch->right_branch != NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                16
              /    \
            8x      N
           / \
          4   N
         / \
        2   5
        /\ /\
       N N N N
****************************************** */
void test_LB_REMOVE_NODE_7(){
printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 16);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 16);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 8);
    CU_ASSERT(root->left_branch->key_value == 8);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);


    Insert_Element(&root, 4);
    CU_ASSERT(root->left_branch->left_branch->key_value == 4);
    CU_ASSERT(root->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 2);
    CU_ASSERT(root->left_branch->left_branch->left_branch->key_value == 2);
    CU_ASSERT(root->left_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 5);
    CU_ASSERT(root->left_branch->left_branch->right_branch->key_value == 5);
    CU_ASSERT(root->left_branch->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch->right_branch == NULL);


    res = Remove_Node(&root, 8);
    CU_ASSERT(root->left_branch->key_value == 4);
    CU_ASSERT(root->left_branch->left_branch != NULL);
    CU_ASSERT(root->left_branch->right_branch != NULL);


    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);


}

/* ****************************************
                16
              /    \
            8x      N
           / \
          4   12
         / \  / \
        2   5 N  N
        /\ /\
       N N N N
****************************************** */
void test_LB_REMOVE_NODE_8(){
printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 16);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 16);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 8);
    CU_ASSERT(root->left_branch->key_value == 8);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);

    Insert_Element(&root, 12);
    CU_ASSERT(root->left_branch->right_branch->key_value == 12);
    CU_ASSERT(root->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 4);
    CU_ASSERT(root->left_branch->left_branch->key_value == 4);
    CU_ASSERT(root->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 2);
    CU_ASSERT(root->left_branch->left_branch->left_branch->key_value == 2);
    CU_ASSERT(root->left_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 5);
    CU_ASSERT(root->left_branch->left_branch->right_branch->key_value == 5);
    CU_ASSERT(root->left_branch->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->left_branch->right_branch->right_branch == NULL);

    res = Remove_Node(&root, 8);

    CU_ASSERT(root->left_branch->key_value == 4);
    CU_ASSERT(root->left_branch->left_branch != NULL);
    CU_ASSERT(root->left_branch->right_branch != NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}



/* ****************************************
                10
              /    \
             N      25x
                   /  \
                  N    N
****************************************** */
void test_RB_REMOVE_NODE_1(){
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);


    Insert_Element(&root, 25);
    CU_ASSERT(root->right_branch->key_value == 25);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    res = Remove_Node(&root, 25);
    CU_ASSERT(res == 0);
    CU_ASSERT(root->right_branch == NULL);
    CU_ASSERT(root->left_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                10
              /    \
             N      25x
                   /  \
                  21   N
                 /  \
                N    N
****************************************** */
void test_RB_REMOVE_NODE_2(){
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 25);
    CU_ASSERT(root->right_branch->key_value == 25);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 21);
    CU_ASSERT(root->right_branch->left_branch->key_value == 21);
    CU_ASSERT(root->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch == NULL);

    res = Remove_Node(&root, 25);
    CU_ASSERT(res == 0);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch->key_value == 21);


    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                10
              /    \
             N      25x
                   /  \
                  21   N
                 /  \
                N    N
****************************************** */
void test_RB_REMOVE_NODE_3(){
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 25);
    CU_ASSERT(root->right_branch->key_value == 25);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 21);
    CU_ASSERT(root->right_branch->left_branch->key_value == 21);
    CU_ASSERT(root->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch == NULL);

    res = Remove_Node(&root, 25);
    CU_ASSERT(res == 0);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch->key_value == 21);


    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                10
              /    \
             N      25x
                   /  \
                  21   33
                 / \   / \
                N   24 N   N
                   /  \
                  N    N
****************************************** */
void test_RB_REMOVE_NODE_4(){
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 25);
    CU_ASSERT(root->right_branch->key_value == 25);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 21);
    CU_ASSERT(root->right_branch->left_branch->key_value == 21);
    CU_ASSERT(root->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 33);
    CU_ASSERT(root->right_branch->right_branch->key_value == 33);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 24);
    CU_ASSERT(root->right_branch->left_branch->right_branch->key_value == 24);
    CU_ASSERT(root->right_branch->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch->right_branch == NULL);

    res = Remove_Node(&root, 25);
    CU_ASSERT(res == 0);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch->key_value == 21);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->key_value == 24);
    CU_ASSERT(root->right_branch->right_branch->right_branch->key_value == 33);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                10
              /    \
             N      25x
                   /  \
                  21   33
                 / \   / \
                N   N N   N
****************************************** */
void test_RB_REMOVE_NODE_5(){
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 25);
    CU_ASSERT(root->right_branch->key_value == 25);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 21);
    CU_ASSERT(root->right_branch->left_branch->key_value == 21);
    CU_ASSERT(root->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 33);
    CU_ASSERT(root->right_branch->right_branch->key_value == 33);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);

    res = Remove_Node(&root, 25);
    CU_ASSERT(res == 0);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch->key_value == 21);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->key_value == 33);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                10
              /    \
             N      25x
                   /  \
                  N    33
                      / \
                     N   N
****************************************** */
void test_RB_REMOVE_NODE_6(){
    printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 10);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 10);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 25);
    CU_ASSERT(root->right_branch->key_value == 25);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 33);
    CU_ASSERT(root->right_branch->right_branch->key_value == 33);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);

    res = Remove_Node(&root, 25);
    CU_ASSERT(res == 0);
    CU_ASSERT(root->left_branch == NULL);

    CU_ASSERT(root->right_branch->key_value == 33);
    CU_ASSERT(root->right_branch->right_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch == NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                16
              /    \
            N       32x
                  /    \
                 N      44
                      /    \
                     40    50
                    /  \  /  \
                    N   N N   N
****************************************** */
void test_RB_REMOVE_NODE_7(){
printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 16);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 16);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 32);
    CU_ASSERT(root->right_branch->key_value == 32);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);


    Insert_Element(&root, 44);
    CU_ASSERT(root->right_branch->right_branch->key_value == 44);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 40);
    CU_ASSERT(root->right_branch->right_branch->left_branch->key_value == 40);
    CU_ASSERT(root->right_branch->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 50);
    CU_ASSERT(root->right_branch->right_branch->right_branch->key_value == 50);
    CU_ASSERT(root->right_branch->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->right_branch == NULL);

    res = Remove_Node(&root, 32);
    CU_ASSERT(root->right_branch->key_value == 44);
    CU_ASSERT(root->right_branch->left_branch != NULL);
    CU_ASSERT(root->right_branch->right_branch != NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                16
              /    \
            N       32x
                  /    \
                 24     44
               /    \   / \
              20    30 40  50
             /  \  / \ / \ / \
             N   N N N N N N N
****************************************** */
void test_RB_REMOVE_NODE_8(){
printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 16);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 16);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 32);
    CU_ASSERT(root->right_branch->key_value == 32);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);


    Insert_Element(&root, 24);
    CU_ASSERT(root->right_branch->left_branch->key_value == 24);
    CU_ASSERT(root->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 20);
    CU_ASSERT(root->right_branch->left_branch->left_branch->key_value == 20);
    CU_ASSERT(root->right_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 30);
    CU_ASSERT(root->right_branch->left_branch->right_branch->key_value == 30);
    CU_ASSERT(root->right_branch->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 44);
    CU_ASSERT(root->right_branch->right_branch->key_value == 44);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 40);
    CU_ASSERT(root->right_branch->right_branch->left_branch->key_value == 40);
    CU_ASSERT(root->right_branch->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 50);
    CU_ASSERT(root->right_branch->right_branch->right_branch->key_value == 50);
    CU_ASSERT(root->right_branch->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->right_branch == NULL);

    res = Remove_Node(&root, 32);
    CU_ASSERT(res == 0);
    CU_ASSERT(root->right_branch->key_value == 24);
    CU_ASSERT(root->right_branch->left_branch != NULL);
    CU_ASSERT(root->right_branch->right_branch != NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                16
              /    \
             8      32x
                  /    \
                 24     44
               /    \   / \
              20    30 40  50
             /  \  / \ / \ / \
             N   N N N N N N N
****************************************** */
void test_RB_REMOVE_NODE_9(){
printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 16);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 16);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 32);
    CU_ASSERT(root->right_branch->key_value == 32);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);

    Insert_Element(&root, 8);
    CU_ASSERT(root->left_branch->key_value == 8);
    CU_ASSERT(root->left_branch->left_branch == NULL);
    CU_ASSERT(root->left_branch->right_branch == NULL);

    Insert_Element(&root, 24);
    CU_ASSERT(root->right_branch->left_branch->key_value == 24);
    CU_ASSERT(root->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 20);
    CU_ASSERT(root->right_branch->left_branch->left_branch->key_value == 20);
    CU_ASSERT(root->right_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 30);
    CU_ASSERT(root->right_branch->left_branch->right_branch->key_value == 30);
    CU_ASSERT(root->right_branch->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 44);
    CU_ASSERT(root->right_branch->right_branch->key_value == 44);
    CU_ASSERT(root->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch == NULL);

    Insert_Element(&root, 40);
    CU_ASSERT(root->right_branch->right_branch->left_branch->key_value == 40);
    CU_ASSERT(root->right_branch->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 50);
    CU_ASSERT(root->right_branch->right_branch->right_branch->key_value == 50);
    CU_ASSERT(root->right_branch->right_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch->right_branch->right_branch == NULL);

    res = Remove_Node(&root, 32);
    CU_ASSERT(res == 0);
    CU_ASSERT(root->right_branch->key_value == 24);
    CU_ASSERT(root->right_branch->left_branch != NULL);
    CU_ASSERT(root->right_branch->right_branch != NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}

/* ****************************************
                16
              /    \
            N       32x
                  /    \
                 24     N
               /    \
              20    30
             /  \  /  \
             N   N N   N
****************************************** */
void test_RB_REMOVE_NODE_10(){
printf("\n%s%s%s\n", lines_20, __func__, lines_20);

    int res = 0;
    struct Node *root = NULL;
    Insert_Element(&root, 16);
    CU_ASSERT_NOT_EQUAL(root, NULL);
    CU_ASSERT(root->key_value == 16);
    CU_ASSERT(root->left_branch == NULL);
    CU_ASSERT(root->right_branch == NULL);

    Insert_Element(&root, 32);
    CU_ASSERT(root->right_branch->key_value == 32);
    CU_ASSERT(root->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->right_branch == NULL);


    Insert_Element(&root, 24);
    CU_ASSERT(root->right_branch->left_branch->key_value == 24);
    CU_ASSERT(root->right_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 20);
    CU_ASSERT(root->right_branch->left_branch->left_branch->key_value == 20);
    CU_ASSERT(root->right_branch->left_branch->left_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->left_branch->right_branch == NULL);

    Insert_Element(&root, 30);
    CU_ASSERT(root->right_branch->left_branch->right_branch->key_value == 30);
    CU_ASSERT(root->right_branch->left_branch->right_branch->left_branch == NULL);
    CU_ASSERT(root->right_branch->left_branch->right_branch->right_branch == NULL);

    res = Remove_Node(&root, 32);
    CU_ASSERT(root->right_branch->key_value == 24);
    CU_ASSERT(root->right_branch->left_branch != NULL);
    CU_ASSERT(root->right_branch->right_branch != NULL);

    root = Reverse_Removing(&root);
    CU_ASSERT(root == NULL);
}




int Return_One(){ return 1; }


void test_Return_One(){ CU_ASSERT(Return_One()== 1); }

int main(){

    CU_pSuite pSuite_1 = NULL, pSuite_2 = NULL;

    /* Initialize CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add suite to registry */
    pSuite_1 = CU_add_suite("Test_Suite_Revers_Removing", init_suite, clean_suite);
    if (NULL == pSuite_1) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    pSuite_2 = CU_add_suite("Test_Suite_Remove_Node", init_suite, clean_suite);
    if (NULL == pSuite_2) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add tests to suite */
    if(
        /* testing reverse removing on left branch of tree*/
        (NULL == CU_add_test(pSuite_1, "test_Tree_One_Node", test_Tree_One_Node)) ||

        (NULL == CU_add_test(pSuite_1, "test_LB_REVERSE_RMV_1", test_LB_REVERSE_RMV_1)) ||
        (NULL == CU_add_test(pSuite_1, "test_LB_REVERSE_RMV_2", test_LB_REVERSE_RMV_2)) ||
        (NULL == CU_add_test(pSuite_1, "test_LB_REVERSE_RMV_3", test_LB_REVERSE_RMV_3)) ||
        (NULL == CU_add_test(pSuite_1, "test_LB_REVERSE_RMV_4", test_LB_REVERSE_RMV_4)) ||
        (NULL == CU_add_test(pSuite_1, "test_LB_REVERSE_RMV_5", test_LB_REVERSE_RMV_5)) ||
        (NULL == CU_add_test(pSuite_1, "test_LB_REVERSE_RMV_6", test_LB_REVERSE_RMV_6)) ||
        (NULL == CU_add_test(pSuite_1, "test_LB_REVERSE_RMV_7", test_LB_REVERSE_RMV_7)) ||
        (NULL == CU_add_test(pSuite_1, "test_LB_REVERSE_RMV_8", test_LB_REVERSE_RMV_8)) ||
        (NULL == CU_add_test(pSuite_1, "test_LB_REVERSE_RMV_9", test_LB_REVERSE_RMV_9)) ||
        /* testing reverse removing on right branch of tree */
        (NULL == CU_add_test(pSuite_1, "test_RB_REVERSE_RMV_1", test_RB_REVERSE_RMV_1)) ||
        (NULL == CU_add_test(pSuite_1, "test_RB_REVERSE_RMV_2", test_RB_REVERSE_RMV_2)) ||
        (NULL == CU_add_test(pSuite_1, "test_RB_REVERSE_RMV_3", test_RB_REVERSE_RMV_3)) ||
        (NULL == CU_add_test(pSuite_1, "test_RB_REVERSE_RMV_4", test_RB_REVERSE_RMV_4)) ||
        (NULL == CU_add_test(pSuite_1, "test_RB_REVERSE_RMV_5", test_RB_REVERSE_RMV_5)) ||
        (NULL == CU_add_test(pSuite_1, "test_RB_REVERSE_RMV_6", test_RB_REVERSE_RMV_6)) ||

        (NULL == CU_add_test(pSuite_1, "test_RB_REVERSE_RMV_7", test_RB_REVERSE_RMV_7)) ||

        (NULL == CU_add_test(pSuite_1, "test_RB_REVERSE_RMV_8", test_RB_REVERSE_RMV_8)) ||

        (NULL == CU_add_test(pSuite_1, "test_RB_REVERSE_RMV_9", test_RB_REVERSE_RMV_9))

        /* testind removing of particular node of tree */
    )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if(
        /* testing reverse removing on left branch of tree*/
        (NULL == CU_add_test(pSuite_2, "test_Empty_Tree_Remove_Node", test_Empty_Tree_Remove_Node)) ||
        (NULL == CU_add_test(pSuite_2, "test_Tree_One_Node_Remove", test_Tree_One_Node_Remove)) ||

        (NULL == CU_add_test(pSuite_2, "test_LB_REMOVE_NODE_1", test_LB_REMOVE_NODE_1)) |
        (NULL == CU_add_test(pSuite_2, "test_LB_REMOVE_NODE_2", test_LB_REMOVE_NODE_2)) ||
        (NULL == CU_add_test(pSuite_2, "test_LB_REMOVE_NODE_3", test_LB_REMOVE_NODE_3)) ||
        (NULL == CU_add_test(pSuite_2, "test_LB_REMOVE_NODE_4", test_LB_REMOVE_NODE_4)) ||

        (NULL == CU_add_test(pSuite_2, "test_LB_REMOVE_NODE_5", test_LB_REMOVE_NODE_5)) ||
        (NULL == CU_add_test(pSuite_2, "test_LB_REMOVE_NODE_6", test_LB_REMOVE_NODE_6)) ||
        (NULL == CU_add_test(pSuite_2, "test_LB_REMOVE_NODE_7", test_LB_REMOVE_NODE_7)) ||
        (NULL == CU_add_test(pSuite_2, "test_LB_REMOVE_NODE_8", test_LB_REMOVE_NODE_8)) ||

        (NULL == CU_add_test(pSuite_2, "test_RB_REMOVE_NODE_7", test_RB_REMOVE_NODE_7)) ||
        (NULL == CU_add_test(pSuite_2, "test_RB_REMOVE_NODE_8", test_RB_REMOVE_NODE_8)) ||
        (NULL == CU_add_test(pSuite_2, "test_RB_REMOVE_NODE_9", test_RB_REMOVE_NODE_9)) ||
        (NULL == CU_add_test(pSuite_2, "test_RB_REMOVE_NODE_10", test_RB_REMOVE_NODE_10)) ||

        (NULL == CU_add_test(pSuite_2, "test_RB_REMOVE_NODE_1", test_RB_REMOVE_NODE_1)) ||
        (NULL == CU_add_test(pSuite_2, "test_RB_REMOVE_NODE_2", test_RB_REMOVE_NODE_2)) ||
        (NULL == CU_add_test(pSuite_2, "test_RB_REMOVE_NODE_3", test_RB_REMOVE_NODE_3)) ||
        (NULL == CU_add_test(pSuite_2, "test_RB_REMOVE_NODE_4", test_RB_REMOVE_NODE_4)) ||
        (NULL == CU_add_test(pSuite_2, "test_RB_REMOVE_NODE_5", test_RB_REMOVE_NODE_5)) ||
        (NULL == CU_add_test(pSuite_2, "test_RB_REMOVE_NODE_6", test_RB_REMOVE_NODE_6))


    ){
        CU_cleanup_registry();
        return CU_get_error();
    }


    /* Run tests using Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    /* Run all suits = run all tests */
    CU_basic_run_tests();
    /* Run specified suite */
    //CU_basic_run_suite(pSuite_1);
    //CU_basic_run_suite(pSuite_2);
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
