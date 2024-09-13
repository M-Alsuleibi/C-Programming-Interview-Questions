#include<stdio.h>
#include<stdlib.h>

// linked list Node definition
struct Node {
    int val;
    struct Node* next;
};

void Pirnt(struct Node * head);
void ReversePirnt(struct Node * head);

void InsertNode(struct Node** head_ref, 
            int new_data);

int main(){
 // Start with the empty list 
  struct Node* head = NULL;

  InsertNode(&head, 6);
  InsertNode(&head, 7);
  InsertNode(&head, 1);
  InsertNode(&head, 4);
  InsertNode(&head, 8);
 
  printf("Forward print: ");    
  Pirnt(head);
  printf("\n");
  printf("Reverse print: ");    
  ReversePirnt(head);
  printf("\n");
    return 0;
}
// Recursive print
void Pirnt(struct Node *head)
{
    if (head == NULL) return;
printf("%d ",head->val);    
Pirnt(head->next);
}
// Recursive reverse print
void ReversePirnt(struct Node *head)
{
        if (head == NULL) return;
ReversePirnt(head->next);
printf("%d ",head->val);    
}



// Given a reference (pointer to pointer) to 
// the head of a list and an int, appends a 
// new node at the end  
void InsertNode(struct Node** head_ref, 
            int new_data)
{
    // 1. Allocate node 
    struct Node* new_node = 
           (struct Node*) malloc(sizeof(struct Node));
 
    // Used in step 5
    struct Node *last = *head_ref;  
 
    // 2. Put in the data  
    new_node->val  = new_data;
 
    // 3. This new node is going to be the 
    //    last node, so make next of it as NULL
    new_node->next = NULL;
 
    // 4. If the Linked List is empty, then make 
    //    the new node as head 
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
        // 5. Else traverse till the last node 
    while (last->next != NULL)
        last = last->next;
 
    // 6. Change the next of last node 
    last->next = new_node;
    return;
}
