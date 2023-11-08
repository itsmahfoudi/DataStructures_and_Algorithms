#include <stdio.h>
#include <stdlib.h>

typedef struct BstNode BstNode;
struct BstNode {
    int value;
    BstNode *left;
    BstNode *right;
};
BstNode* getnode(int value){
    BstNode *node = (BstNode*)malloc(sizeof(BstNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void insert(BstNode *root,int value) {
    if (root == NULL) {
        root = getnode(value);
        return;
    }
    if (value < root->value) {
        if (root->left == NULL) {
            root->left = getnode(value);
        } else {
            insert(root->left, value);
        }
    } else {
        if (root->right == NULL) {
            root->right = getnode(value);
        } else {
            insert(root->right, value);
        }
    }
}
void display(BstNode *root){ 
    if (root == NULL) {
        return;
    }
    printf("%d ", root->value);
    display(root->left);
    display(root->right); 
}
int main() {
    BstNode *rootptr = NULL;
    insert(rootptr,10);
    insert(rootptr,5);
    insert(rootptr,15);
    insert(rootptr,7);
    display(rootptr);
}