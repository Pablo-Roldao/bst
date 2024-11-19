#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

tree insert(tree root, int value) {
  if (root == NULL) {
    tree newNode = (tree) malloc(sizeof(node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
  
    return newNode;
  }
  
  if (value <= root->value) {
    root->left = insert(root->left, value);
  } else {
    root->right = insert(root->right, value);
  }

  return root;
}

tree delete(tree root, int value) {
  if (root != NULL) {
    if (root->value == value) {
      if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
      }
      
      if (root->left != NULL && root->right == NULL) {
        tree rootToReplace = root->left;
        free(root);
        return rootToReplace;
      }
      
      if (root->right != NULL && root->left == NULL) {
        tree rootToReplace = root->right;
        free(root);
        return rootToReplace;
      }
      
      root->value = greater(root->left)->value;
      root->left = delete(root->left, root->value);
      
      return root;
    } else {
      if (value <= root->value) {
        root->left = delete(root->left, value);
      } else {
        root->right = delete(root->right, value);  
      }

      return root;
    }
  }
  
  return NULL;
}

void inOrderTreeWalk(tree root) {
  if (root != NULL) {
    inOrderTreeWalk(root->left);
    printf("%d ", root->value);
    inOrderTreeWalk(root->right);
  }
}

void preOrderTreeWalk(tree root) {
  if (root != NULL) {
    printf("%d ", root->value);
    preOrderTreeWalk(root->left);
    preOrderTreeWalk(root->right);
  }
}

tree greater(tree root) {
  if (root == NULL) {
    return NULL;
  }

  tree greater = root;
  
  while (root->right != NULL) {
    greater = root->right;
  }
  
  return greater;
}
