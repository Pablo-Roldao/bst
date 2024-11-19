#include <stdio.h>
#include "bst.h"

int main() {
  int option;
  tree tree = NULL;
  
  do {
    scanf("%d", &option);
    
    switch (option) {
      case 1: {
        int value;
        scanf("%d", &value);
        tree = insert(tree, value);
        break;
      }
      case 2: {
        printf("[ ");
        preOrderTreeWalk(tree);
        printf("]\n");
        break;
      }
      case 3: {
        printf("[ ");
        inOrderTreeWalk(tree);
        printf("]\n");
        break;
      }
      case 4: {
        int value;
        scanf("%d", &value);
        tree = delete(tree, value);
        break;
      }
    }
  } while (option != 99);
  
  return 0;
}
