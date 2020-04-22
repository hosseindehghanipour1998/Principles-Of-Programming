/* Doubly Linked List */


#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

/* Insert At  */
struct Node *insert_at(struct Node *head , int newValue , int house){
    struct Node *temp = head;
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    int counter;

    if(head == NULL){
        new->data = newValue;
        new->next = NULL;
        new->prev = NULL;
        return temp;
    }

    if(house == 0){
        //printf("ok");
        new->data = newValue;
        new->next = head;
        new->prev = NULL;
        head->prev = new;
        return new;
    }
    else{
        for(counter = 0 ; counter < house - 1  ; counter++){
            head = head->next;
        }
        new->data = newValue;
        new->next = head->next;
        head->next = new;
        new->prev = head;
        return temp;
    }
    
}

/* edit value of house nth*/
struct Node *edit(struct Node *head , int newValue , int house){
    int counter;
    struct Node *temp = head;
    for(counter = 0 ; counter != house ; counter++){
        head = head->next;
    }
    head->data = newValue;
    return temp;
}

/* delete by index (delete at) */
struct Node *delete_by_index(int index , struct Node *head){
    int counter = 0;
    struct Node *temp = head;
    struct Node *temp2;

    while(counter != index - 1){
        head = head->next;
        counter++;
    }
    temp2 = head->next;
    head->next->next->prev = head;
    head->next = head->next->next;
    free(temp2);
    return temp;
}

/* delete by data */
struct Node * delete_by_value(int number , struct Node *head){
    struct Node *temp = head;
    struct Node *temp2= (struct Node *)malloc(sizeof(struct Node));
    while(head->next != NULL){
        if(head->next->data == number){
            temp2 = head->next;
            head->next = head->next->next;
            head->next->next->prev = head;
            free(temp2);
            return temp;
        }
        head = head->next;
    }
    return temp;
}

/* search */
int search(int number , struct Node *head){
    if(head == NULL){
        return 0;
    }
    else{
        while(head->next != NULL){
            if(number == head->data)
                return 1;
            head = head->next;
        }
        if(number == head->data)
                return 1;

        return 0;
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
    while(temp->next != NULL){
        temp = temp->next;
        counter++;
    }
    return ++counter;
}


void swap(struct Node *a, struct Node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 

/* Bubble sort */
void bubbleSort(struct Node *head) { 
    int swapped = 1; 
    struct Node *temp1; 
    struct Node *temp2 = NULL; 
  
    /* Checking for empty list or only one element */
    if (head == NULL || head->next == NULL) 
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

/* print list */
void printList(struct Node *head){
    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}


int main(int argc, char const *argv[]){
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // allocate 3 nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    printf("First List: ");
    head->data = 1; //assign data in first node
    head->next = second; // Link first node with second
    head->prev = NULL; // Link first node with second

    second->data = 2; //assign data to second node
    second->next = third;
    second->prev = head;

    third->data = 3; //assign data to third node
    third->next = NULL;
    third->prev = second;

    printList(head);
    printf("\n");

    head = insert_at(head, 100 ,0);
    printList(head);
    printf("\n");
    head = edit(head, 255 ,2);
    printList(head);
    printf("\n");
    head = delete_by_index(1,head);
    printList(head);
    printf("\n");

    return 0;
}
