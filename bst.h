#ifndef BST_H
#define BST_H

typedef struct node {
  int value;
  struct node *left;
  struct node *right;
} node;

typedef node *tree;

tree greater(tree root);
tree insert(tree root, int value);
tree delete(tree root, int value);
void inOrderTreeWalk(tree root);
void preOrderTreeWalk(tree root);

#endif