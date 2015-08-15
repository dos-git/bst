#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

struct Node
{
    int key_value;
    struct Node *left_branch;
    struct Node *right_branch;
    struct Node *parent;
};

struct Node *Create_Element(int);
void Insert_Element(struct Node **, int);
void Return_Node(struct Node **, int, int);
void Insert_Element(struct Node **, int);
int Check_Branches_for_Nodes(struct Node *);
struct Node *Find_Node_by_ID(struct Node **, int);
struct Node *Reverse_Removing(struct Node **);
struct Node *Get_Last_Left_Node(struct Node **);
struct Node *Get_Last_Right_Node(struct Node **);
int Remove_Node(struct Node **, int);

int Return_one();
#endif
