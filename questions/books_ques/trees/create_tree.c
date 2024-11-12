// CREATE A BINARY SEARCH TREE 
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

// DECLARATIONS OF THE STRUCTURE 
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} Node;

// FUNCTION PROTOTYPES 
Node *node (int value);
Node *create_tree (Node *,int);
Node pre_order (Node *);
Node post_order (Node *);
Node in_order (Node *);
void search_value (Node *,int);

// MAIN FUNCTION OF THE PROGRAM 
int main (int argc, char * argv[]) {
  Node *root = NULL; // ROOT OF THE TREE IS NULL 
  int arr [] = {26,18,30,17,19,32,20};
  int size = sizeof (arr) / sizeof (int);
  for (int i = 0; i < size; i++) {
    root = create_tree (root,arr [i]); // CREATE TREE AND ASSIGN IT'S VALUES TO NODE OF THE TREE 
  }
  printf ("\nTraverse tree in pre-order manner : ");
  pre_order (root);
  printf ("\nTraverse tree in in - order manner : ");
  in_order (root);
  printf ("\nTraverse tree in post order manner : ");
  post_order (root);

  // SEARCH FOR A PARTICULAR VALUE IN A TREE 
  search_value (root,2319);
  return 0;
}
// FUNCTION DEFINITIONS 
Node *node (int value) {
  Node *new_node = (Node *) malloc (sizeof (Node));
  if (new_node != NULL) {
    new_node->data = value;
    new_node->left = new_node->right = NULL;
  }
  else {
   fprintf (stderr,"\nDynamic memory not allocated for it !");
   exit (0);
  }
  return new_node; 
}
// CREATE TREE 
Node *create_tree (Node *root,int value) {
   Node *new_node = node (value);
   if (root == NULL) {
    root = new_node;
   }
   else {
     Node *current,*parent;
     current = root;
     parent = NULL;
     while (current != NULL) {
       parent = current;
       if (value > current->data) {
         current = current->right;
         if (current == NULL) {
           parent->right = new_node;
         }
       }
       else {
        current = current->left;
        if (current == NULL)
          parent->left = new_node;
       }
     }
   }

   return root;
}
// RECURSIVELY TRAVERSE TREE IN THE PRE ORDER MANNER 
Node pre_order (Node *tree) {
  Node *current = tree;
  if (current != NULL) { // TERMINATE TRAVERSING WHEN CURRENT ENCOUNTER WITH LAST NODE OF THE TREE 
    printf ("\nValue : %d",current->data);
    pre_order (current->left);
    pre_order (current->right);
  }
}

Node in_order (Node *tree) { // RECURSIVELY TRAVERSE TREE IN THE IN ORDER MANNER 
  Node *current = tree;
  if (current != NULL) {
    in_order (current->left);
    printf ("\nValue : %d",current->data);
    in_order (current->right);
  }
}

Node post_order (Node *tree) { // RECURSIVELY TRAVERSE TREE IN THE POST ORDER MANNER 
  Node *current = tree;
  if (current != NULL) {
    post_order (current->left);
    post_order (current->right);
    printf ("\nValue : %d",current->data);
  }
}

void search_value (Node *tree,int value) { // RECURSIVELY SEARCHING A TREE FOR KNOWING THERE IS VALUE IN THE TREE OR NOT IN THE TREE
  Node *current = tree;
  if (current == NULL) 
   printf ("\nValue isn't in the tree"), exit (-1);
  if (current->data == value) {
    printf ("\nYes value is found in the tree");
    return;
  }
  if (current->data != value) {
    if (value > current->data)
      search_value (current->right,value);
    else 
      search_value (current->left,value);
  }
}