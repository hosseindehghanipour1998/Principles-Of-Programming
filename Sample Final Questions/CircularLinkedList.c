/* Circular Linked List */


#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};


/* Insert At  */
struct Node * insert_at(int value , struct Node *head , int house){
    struct Node *temp = head;
    struct Node *new_node;
    struct Node *prev_node;
    struct Node *next_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    int counter = 0;
    while(counter != house - 1 ){
        temp = temp->next;
        counter++;
    }
    next_node = temp->next;
    temp->next = new_node;
    new_node->next = next_node->next;
    free(next_node);
    return head;
}

/* edit nth value */
struct Node * edit(int house, int newValue,struct Node *head){
    struct Node *temp = head;
    int counter = 0;
    for(counter = 0 ; counter != house ; counter++){
        temp = temp -> next;
    }
    temp->data = newValue;
    return head;
}


/* delete by index (delete at) */
struct Node * delete_by_index(int index , struct Node *head){
    int counter = 0;
    struct Node *temp = head;
    struct Node *next_node;

    while(counter != index - 1){
        temp = temp->next;
        counter++;
    }
    next_node = temp->next;
    temp->next = next_node->next;
    free(next_node);
    return head;
}

/* delete by data */
struct Node * delete_by_value(int number , struct Node *head){
    struct Node *temp = head;
    struct Node *next_node;
    while(temp->next != head){
        if(temp->next->data == number){
            next_node = temp->next;
            temp->next = next_node->next;
            free(next_node);
            return head;
        }
        temp = temp->next;
    }
    return head;
}

/* SEARCH */
int search(int number , struct Node *head){
    struct Node *temp = head;
    if(temp == NULL){
        return 0;
    }
    else{
        while(temp->next != head){
            if(number == temp->data)
                return 1;
            temp = temp->next;
        }
        if(number == temp->data)
                return 1;

        return 0;
    }
}


/* ADD LAST */
struct Node *add(int data , struct Node *head){
    struct Node *temp = head;
    struct Node *newVal;
    newVal = (struct Node *)malloc(sizeof(struct Node));

    if(temp == NULL){
        newVal->data = data;
        newVal->next = temp;
        return newVal;
    }
        
    else{
        while(temp->next != head){
            temp = temp->next;
        }
            
        temp->next = newVal;
        newVal->data = data;
        newVal->next = head;
        return head;
    }
}

/* add first */

struct Node *add_first(int newValue , struct Node *head){
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = newValue;
    temp->next = head;
    return temp;
}

/* DELETE FIRST */
struct Node *delete_first(struct Node *head){

    struct Node *new_head;
    struct Node *temp = head;
    struct Node *last_node;

    if(head == NULL){
        printf("The list is empty.");
        return new_head;
    }
    else if(head->next == NULL){
        free(head);
        new_head = NULL;
        return new_head;
    }
    else{
        while(temp->next != head)
            temp = temp->next;
        last_node = temp;
        new_head = head->next;
        last_node->next = new_head;
        free(head);
        return new_head;
    }
}

/* DELETE LAST */
struct Node *delete_last(struct Node *head){
    struct Node *temp = head;
    struct Node *last_node;
    /* if there is only one item in the list, remove it */
    if(temp->next == head){
        free(head);
        return head;
    }
    /* if there is more than one item in the list, remove the last one */
    else{
        while(temp->next->next != head)
            temp = temp->next;
        last_node = temp->next;
        temp->next = head;
        free(last_node);
        return head;
    }
}

/* DELETE LIST */
void delete_list(struct Node *head){
    struct Node *temp;
    while(head->next != NULL){
        temp = head->next;
        free(head);
        head = temp;
    }
    free(head);
    temp->next = NULL;
}

/* get (return value of nth house) */
int get(int house , struct Node *head){
    struct Node *temp = head;
    int counter = 0;
    while(counter != house){
        temp = temp->next;
        counter++;
    }
    return temp->data;
}



/* length */
int listlen(struct Node *head){
    struct Node *temp = head;
    int counter = 0;
    while(temp->next != head){
        temp = temp->next;
        counter++;
    }
    return ++counter;
}

/* function to swap data of two nodes a and b*/
void swap(struct Node *a, struct Node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 

/* Bubble sort */
void bubbleSort(struct Node *head) { 
    int swapped = 1; 
    struct Node *temp1; // current node
    struct Node *temp2 = head; // before current node
  
    /* Checking for empty list or only one element */
    if (head == NULL || head->next == head) 
        return; 
    while(swapped != 0){
        swapped = 0; 
        temp1 = head; 
        while (temp1->next != temp2) { 
            if (temp1->data > temp1->next->data) {  
                swap(temp1, temp1->next); 
                swapped = 1; 
            } 
            temp1 = temp1->next; 
        } 
        temp2 = temp1; 
    } 
}

/* PRINT */
void printList(struct Node *head){
    struct Node *temp = head;
    while (temp->next != head){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}

int main(){
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    printf("First List: ");
    head->data = 5; 
    head->next = second; 

    second->data = 3; 
    second->next = third;

    third->data = 8; 
    third->next = head;

    printList(head);
    printf("\n");
    bubbleSort(head);
    printList(head);
    printf("\n");

   
    




    return 0;
}

