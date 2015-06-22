#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

struct Node
{
    int key_value;
    struct Node *left_branch;
    struct Node *right_branch;
    struct Node *parent;
};

int Insert_Element(struct Node **, int id_value);
struct Node *Create_Element(int value);


#endif
