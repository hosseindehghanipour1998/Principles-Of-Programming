#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

int listLen(struct Node *head){
    int counter = 1;
    while(head->next != NULL){
        counter++;
        head = head -> next;
    }
    return counter;
}


/* method 1 : using an array to save the data */
struct Node *reverse_using_array(struct Node *head){
    int len = listLen(head);
    int array[len];
    int i = 0;
    int j = 0;
    struct Node *temp = head;
    
    while(temp->next != NULL){
        array[i++] = temp->data; // saving all data in an array
        temp = temp->next;
    }
    array[i] = temp->data;
    temp = head;
    for(j=0 ; j<len ; j++){ // changing data
        temp->data = array[i--];
        temp = temp->next;
    }
    return head;
}

/* method 2 : iterative mode */
struct Node *reverse_iterative(struct Node *head){
    struct Node* prev   = NULL; 
    struct Node* current = head; 
    struct Node* next = NULL; 
    while (current != NULL) { 
        next = current->next;   
        current->next = prev;    
        prev = current; 
        current = next; 
    } 
    head = prev; 
    return head;
}

/* method 3 : implenting with a void function */ 
void reverse_iterative_void(struct Node **head_address){
    struct Node* prev   = NULL; 
    struct Node* current = *head_address; 
    struct Node* next = NULL; 
    while (current != NULL) { 
        next  = current->next;   
        current->next = prev;    
        prev = current; 
        current = next; 
    } 
    *head_address = prev; 
}


void reverse_recursive(struct Node **head ){
    struct Node *first;
    struct Node *other;
    first = *head;
    other = first->next;
    if(other == NULL)
        return;
    reverse_recursive(&other);
    first->next->next = first;
    first->next = NULL;
    *head = other;
    return;
}



void printList(struct Node *head){
    struct Node *temp = head;
    while(temp->next != NULL){
        printf("%d " , temp->data);
        temp = temp -> next;
    }
    printf("%d " , temp->data);
}

int main(int argc, char const *argv[]){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    printf("First List: ");
    head->data = 1;
    head->next = second;
    // 1->NULL

    second->data = 2;
    second->next = third;
    // 1->2->NULL

    third->data = 3; 
    third->next = fourth;
    // 1->2->3->NULL

    fourth->data = 4; 
    fourth->next = NULL;
    // 1->2->3->4->NULL

    printList(head);
    printf("\n");
    
    printf("Reversed via array:\t");
    head = reverse_using_array(head);
    printList(head);
    printf("\n");

    printf("Reversed Iterative:\t");
    head = reverse_iterative(head);
    printList(head);
    printf("\n");

    printf("Reversed Iterative 2:\t");
    reverse_iterative_void(&head);
    printList(head);
    printf("\n");

    printf("Reversed Recursive:\t");
    reverse_recursive(&head);
    printList(head);
    printf("\n");


    
}
