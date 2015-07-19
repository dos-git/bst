#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

struct Node
{
    int key_value;
    struct Node *left_branch;
    struct Node *right_branch;
    struct Node *parent;
};

void Insert_Element(struct Node **, int id_value);
struct Node *Create_Element(int value);
struct Node *Reverse_Removing(struct Node **root);
struct Node *Get_Last_Left_Node(struct Node **root);
struct Node *Get_Last_Right_Node(struct Node **root);

int Return_one();
#endif
