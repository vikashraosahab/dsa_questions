// CREATE BINARY TREE 
#include <stdio.h>
#include <stdlib.h>

// DELCARE STRUCTURE
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} Node;

Node *create_node (int);
void in_orderTraversal (Node *tree) {
  if (tree == NULL) 
    return;
  in_orderTraversal (tree->left);
  printf ("%d ",tree->data);
  in_orderTraversal (tree->right);
}
// MAIN FUNCTION OF THE PROGRAM 
int main (int argc, char * argv[]) {
  Node *root = NULL;
  Node *new_node;
  int value;
  printf ("\nEnter value of the root : ");
  scanf ("%d",&value);
  if (value != -1) {
    new_node = create_node (value);
    if (new_node != NULL) {
      root = new_node;
    }
  }
  else {
    fprintf (stderr,"\nDynamic memory not allocated !");
    return 1;
  }
  
  while (1) {
     Node *current = root;
     Node *parent = NULL;
    printf ("\nEnter the node data : ");
    scanf ("%d",&value);
    if (value == -1) break;
    new_node = create_node (value);
    if (new_node == NULL) {
      fprintf (stderr,"\nNode isn't allocated !");
      continue;
    }
    while (current != NULL) {
      parent = current;
      if (value < current->data) {
        current = current->left;
      }
      else 
        current = current->right;
    }

    // SET NODE TO THE RIGHT PLACE 
    if (value < parent->data) {
      parent->left = new_node;
    }
    else 
     parent->right = new_node;
  }
  in_orderTraversal (root);
  return 0;
}
Node *create_node (int value) {
  Node *node = (Node *) malloc (sizeof (Node));
  if (node != NULL) {
    node->data = value;
    node->left = node->right = NULL;
  }
  else 
   printf ("\nDynamic memory doesn't allocated for the node !");
  
  // RETURN THE NODE 
  return node;
}