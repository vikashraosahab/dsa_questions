/*
************ BINARY SEARCH TREE ********************
******* AND OPERATIONS PERFORAMCE BY IT ************
// CREATE A BINARY SEARCH TREE 
// INSERT ELEMENT IN THE BINARY SEARCH TREE 
// TRAVERSAL METHODS - PRE-ORDER,IN-ORDER AND POST-ORDER 
// FIND SMALLEST VALUE OF NOT IN THE TREE 
// FIND LARGEST VALUE OF THE NODE FROM THE TREE 
// DELETE ELEMENT FROM THE TREE 
// MIRROR OF THE TREE 
// TOTAL NUMBER OF NODE IN THE TREE 
// TOTAL OF EXTERNAL NODE OF THE TREE 
// TOTAL INTERNAL NODE OF THE TREE 
// TOTAL NUMBER OF NODE OF THE LEFT SUB TREE 
// TOTAL NUMBER OF NODE OF THE RIGHT SUB-TREE 
// HEIGHT OF THE TREE 
// REMOVE ALL ELEMENTS ONE BY ONE FROM THE TREE 
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

// DECLARATION OF THE STRUCTURE THAT STORE ALL DATA MEMBER OF NODE AT PLACE 
typedef struct node {
   int data;
   char *name;
   struct node *left; // LEFT POINTER OF THE NODE
   struct node *right; // RIGHT POINTER OF THE NODE 
} Node;
Node *root = NULL; // ASSIGN NULL TO THE ROOT OF THE TREE 
// FUNCTION PROTOTYPES 
Node *new_node (int); // FOR CREATION OF THE A PARTICULAR NODE EACH TIME 
Node *create_tree (Node *,int); // FOR CREATION OF THE BINARY SEARCH TREE 
Node *insert_node (Node *,int); // FOR INSERTION OF THE NEW NODE IN THE TREE 
void menu (); // SHOW MENU FOR INSTRUCTION
void process_menu (int); // PERFORM INSTRUCTION OF THE PROCESS MENU
int valid_input (); // VALIDATE INPUT USER 
void pre_order (Node *);
// MAIN FUNCTION OF THE PROGRAM 
int main (int argc, char * argv[]) {
    // VARIALBES DECLARTIONS 
    int value;
    while (1) {
      menu ();
      value = valid_input ();
      if (value == 18) break;
      process_menu (value);
    }
    return 0;
}
void menu () { // MENU CARD THAT INSTRUCT USER 
    /* 
      THERE IS ALL STATEMENT THAT PROGRAM NEED 
      IT'S A WAY THAT USER TAKE HELP AS INSTRUCTOR FROM IT
      IT'S A USER PROMPT 
    */
    printf ("\n************* Main Menu *******************");
    printf ("\n1 : CREATE TREE ");
    printf ("\n2 : Insert value");
    printf ("\n3 : Pre-order traverse");
    printf ("\n18 : Exit");
    printf ("\nEnter value according to the main menu : ");
}
void process_menu (int task) { // METHOD THAT PERFORM TASK ACCORING USER INPUT
    switch (task) {
        case 1:
          printf ("\n************** CREATION OF THE TREE **************");
          int ary[] = {10,12,18,8,6,2,3,5,1,2,3,23,52,6,123,5,6,99,132,23};
          for (int i = 0; i < sizeof (ary) / sizeof (int); i++)
          root = create_tree (root,ary [i]);
          printf ("\nDone!");
          break;
        case 2:
         printf ("\n Insert new node in the tree : ");
         int value;
         scanf ("%d",&value);
         root = insert_node (root,value);
         printf ("\nDone!");
         break;
        case 3:
         printf ("\n**************** PRE-ORDER TRAVERSING ***************");
         pre_order (root);
         printf ("\nDone !");
         break;
    }
}
int valid_input () {// METHOD THAT VALIDATE INPUT VALUES ONLY INTEGER ARE VALID 
  int value;
  while (1) {
    printf ("\nEnter value : ");
    if (scanf ("%d",&value) != 1) { // METHOD THAT CHECKING THAT VALUE IS INTEGER OR NOT INTEGER
      while (getchar () != '\n') { // IGNORE NEW LINE CHARACTER 
        fprintf (stderr,"\nEnter value is in-valid. Please enter valid input : ");
      }
    }
    else 
     return value; // RETURN VALUE WHEN USER INPUT CORRECT INPUT 
  }
}
Node *new_node (int value) { // CREATE NODE THAT STORE DATA AND POINTER 
   Node *node = (Node *) malloc (sizeof (Node));
   if (node != NULL) {
    node->data = value;
    node->name = "Vikash";
    node->left = node->right = NULL;
   }
   else 
    fprintf (stderr,"\nNode is not allocated for dynamic memory !");
   return node;
}
Node *create_tree (Node *tree,int value) { // METHOD THAT IS USED TO CREATE TREE 
  Node *node = new_node (value);
  if (node != NULL) {
    if (tree == NULL) {
      tree = node;
    }
    else {
      Node *current,*parent;
      current = tree;
      while (current != NULL) {
        parent = current;
        if (current->data > value) { // INSERT VALUE IN THE LEFT SUB-TREE 
          current = current->left;
          if (current == NULL) 
           parent->left = node;
        }
        else { // INSERT VALUE IN RIGHT SUB TREE 
          current = current->right;
          if (current == NULL) {
            parent->right = node;
          }
        }
      }
    }
  }
  return tree;
}
Node *insert_node (Node *tree,int value) {
  Node *node = new_node (value);
  if (node != NULL) {
    if (root == NULL) {
      root = node;
    }
    else {
      Node *current = root;
      if (current != NULL) {
        if (value > current->data) {
           current = current->right;
           if (current == NULL)
            current->right = node;
        }
        else {
          current = current->left;
          if (current == NULL)
            current->left = node;
        }
      }
    }
  }
  else 
   fprintf (stderr,"\nNode isn't allocate dynamic memory !");
  return tree;
}
void pre_order (Node *tree) { // TRAVERSING THE TREE IN THE PRE-ORDER FORM
  if (tree == NULL) {
    return;
  }
  printf ("\nValue : %d",tree->data); 
  pre_order (tree->left);
  pre_order (tree->right);
}
