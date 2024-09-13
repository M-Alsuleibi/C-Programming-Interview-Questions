#include<stdio.h>
#include<stdlib.h>
// linked list Node definition
struct Node {
    int val;
    struct Node* next;
};
//Reverse Fn return the head of the reversed version of original LL
struct Node* Reverse(struct Node* head);
//Insert Fn retrun the head of the LL
void InsertNode(struct Node** head, int val);
// This function prints contents of the ll starting from head
void printList(struct Node* head);
void deleteNode(struct Node** head_ref, int key) ;


// Driver code

int main(){
 // Start with the empty list 
  struct Node* head = NULL;

  InsertNode(&head, 6);
  InsertNode(&head, 7);
  InsertNode(&head, 1);
  InsertNode(&head, 4);
  InsertNode(&head, 8);
 
  printf("Created Linked list is: ");
  printList(head);

printf("Reverse : ");
struct Node *newHead = Reverse(head);
printList(newHead);

deleteNode(&head, 8); 
deleteNode(&head, 4); 
deleteNode(&head, 1); 
deleteNode(&head, 7); 
deleteNode(&head, 6); 
printf("Linked list after delete is: ");
  printList(head);

    return 0;
}

struct Node *Reverse(struct Node *head)
{
    struct Node* cur = head;
    struct Node* prev = NULL;
    while(cur != NULL){
        struct Node *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
        
    }
    head = prev;
    return head;
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

void printList(struct Node *head)
{
     while (head != NULL)
  {
     printf(" %d ", head->val);
     head = head->next;
  }
  printf("\n");
}

void deleteNode(struct Node** head_ref, int key) 
{ 
    // Store head node 
    struct Node *temp = *head_ref, *prev; 
  
    // If head node itself holds the key to be deleted 
    if (temp != NULL && temp->val == key) { 
        *head_ref = temp->next; // Changed head 
        free(temp); // free old head 
        return; 
    } 
  
    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (temp != NULL && temp->val != key) { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in linked list 
    if (temp == NULL) 
        return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    free(temp); // Free memory 
} 
