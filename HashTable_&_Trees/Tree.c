#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct TreeStruct Tree;
struct TreeStruct {
  int data;
  Tree* left;
  Tree* right;
  Tree* parent;
};

Tree* newTree(int data);
void insertTree(Tree* parent, Tree* tree);
int max(int a, int b);
bool isLeft(Tree* tree);
void printTree(Tree* tree, const char* traversal);
void replaceNode(Tree* originalNode, Tree* replacingNode);
void unlinkChild(Tree* child);
void deleteNode(Tree* tree);
int treeHeight(Tree* tree);
int nodesNmber(Tree* tree);

int main(int argc, const char** argv) {
  Tree* tree1 = newTree(11);
  Tree* tree2 = newTree(7);
  Tree* tree3 = newTree(20);
  Tree* tree4 = newTree(3);
  Tree* tree5 = newTree(9);
  Tree* tree6 = newTree(17);
  Tree* tree7 = newTree(23);
  Tree* tree8 = newTree(2);
  Tree* tree9 = newTree(8);
  Tree* tree10 = newTree(10);
  Tree* tree11 = newTree(19);
  Tree* tree12 = newTree(28);

  insertTree(tree1, tree2);
  insertTree(tree1, tree3);
  insertTree(tree2, tree4);
  insertTree(tree2, tree5);
  insertTree(tree3, tree6);
  insertTree(tree3, tree7);
  insertTree(tree4, tree8);
  insertTree(tree5, tree9);
  insertTree(tree5, tree10);
  insertTree(tree6, tree11);
  insertTree(tree7, tree12);

  printf("                      11\n");
  printf("                    /   \\\n");
  printf("                  /      \\\n");
  printf("                /         \\\n");
  printf("              /            \\\n");
  printf("             7             20\n");
  printf("           /   \\          /   \\\n");
  printf("          3     9        17    23\n");
  printf("        /     /   \\       \\      \\\n");
  printf("       2     8    10      19     28");
  printf("\n\n");
  /*
                      11
                    /   \
                  /      \
                /         \
              /            \
             7             20
           /   \          /   \
          3     9        17    23
        /     /   \       \      \
       2     8    10      19     28
  */

  printf("Inorder   : ");
  printTree(tree1, "inorder");
  printf("\n");
  printf("Preorder  : ");
  printTree(tree1, "preorder");
  printf("\n");
  printf("Postorder : ");
  printTree(tree1, "postorder");
  printf("\n\n");

  printf("Delete 7\n");
  deleteNode(tree2);
  printf("Inorder   : ");
  printTree(tree1, "inorder");
  printf("\n");
  printf("Delete 20\n");
  deleteNode(tree3);
  printf("Inorder   : ");
  printTree(tree1, "inorder");
  printf("\n\n");

  printf("Tree Height : %d", treeHeight(tree1));
  printf("\n\n");

  printf("Nodes number : %d", nodesNmber(tree1));
  printf("\n\n");

  return 0;
}
Tree* newTree(int data) {
  Tree* tree = (Tree*)malloc(sizeof(*tree));
  tree->data = data;
  tree->left = NULL;
  tree->right = NULL;
  tree->parent = NULL;
  return tree;
}
void insertTree(Tree* parent, Tree* tree) {
  tree->parent = parent;
  if (tree->data < parent->data) {
    parent->left = tree;
  } else if (tree->data > parent->data) {
    parent->right = tree;
  }
}
void printTree(Tree* tree, const char* traversal) {
  if (tree != NULL) {
    if (traversal == "inorder") {
      // Left, Root, Right
      printTree(tree->left, traversal);
      printf("%d  ", tree->data);
      printTree(tree->right, traversal);
    } else if (traversal == "preorder") {
      // Root, Left, Right
      printf("%d  ", tree->data);
      printTree(tree->left, traversal);
      printTree(tree->right, traversal);
    } else if (traversal == "postorder") {
      // Left, Right, Root
      printTree(tree->left, traversal);
      printTree(tree->right, traversal);
      printf("%d  ", tree->data);
    }
  }
}
bool isLeft(Tree* tree) {
  return (tree->parent->left == tree);
}
void replaceNode(Tree* originalNode, Tree* replacingNode) {
  Tree* parent = originalNode->parent;
  if (isLeft(originalNode)) {
    parent->left = replacingNode;
  } else {
    parent->right = replacingNode;
  }
}
void unlinkChild(Tree* child) {
  // unlink child from its parent
  Tree* parent = child->parent;
  if (isLeft(child)) {
    parent->left = NULL;
  } else {
    parent->right = NULL;
  }
}
void deleteNode(Tree* tree) {
  Tree* parent = tree->parent;
  Tree* left = tree->left;
  Tree* right = tree->right;

  if (left == NULL && right == NULL) {
    unlinkChild(tree);
    free(tree);
  } else if (left == NULL) {
    insertTree(parent, right);
    free(tree);
  } else if (right == NULL) {
    insertTree(parent, left);
    free(tree);
  } else {
    Tree* extremLeft = right;
    while (extremLeft->left != NULL) {
      extremLeft = extremLeft->left;
    }
    // copy extremLeft value to original tree
    tree->data = extremLeft->data;
    // replace extremLeft with its right child
    replaceNode(extremLeft, extremLeft->right);

    free(extremLeft);
  }
}
int max(int a, int b) {
  return (a > b) ? a : b;
}
int treeHeight(Tree* tree) {
  if (tree == NULL) {
    return 0;
  } else {
    return max(treeHeight(tree->left), treeHeight(tree->right)) + 1;
  }
}
int nodesNmber(Tree* tree) {
  if (tree == NULL) {
    return 0;
  } else {
    return (nodesNmber(tree->left) + nodesNmber(tree->right) + 1);
  }
}
