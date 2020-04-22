/* Normal Linked List */

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};


/* Insert At  */
struct Node * insert_at(int value , struct Node *head , int house){
    struct Node *temp = head;
    struct Node *temp2;
    struct Node *newVal;
    newVal = (struct Node *)malloc(sizeof(struct Node));
    newVal->data = value;
    int counter = 0;
    while(counter != house - 1 ){
        head = head->next;
        counter++;
    }
    temp2 = head->next;
    head->next = newVal;
    newVal->next = temp2;
    return temp;
}

/* edit nth value */
struct Node * edit(int house, int newValue,struct Node *head){
    struct Node *temp = head;
    int counter = 0;
    for(counter = 0 ; counter != house ; counter++){
        head = head -> next;
    }
    head->data = newValue;
    return temp;
}


/* delete by index (delete at) */
struct Node * delete_by_index(int index , struct Node *head){
    int counter = 0;
    struct Node *temp = head;
    struct Node *temp2= (struct Node *)malloc(sizeof(struct Node));

    while(counter != index - 1){
        head = head->next;
        counter++;
    }
    temp2 = head->next;
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
            free(temp2);
            return temp;
        }
        head = head->next;
    }
    return temp;
}

/* SEARCH */
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


/* ADD LAST */
struct Node *add(int data , struct Node *head){
    struct Node *temp = head;
    struct Node *newVal;
    newVal = (struct Node *)malloc(sizeof(struct Node));

    //(*newVal).data = data;
    newVal->data = data;
    //(*newVal).next = NULL;
    newVal->next = NULL;

    if(head == NULL)
        return newVal;
    else{
        while(head->next != NULL)
            //head = (*head).next;
            head = head->next;
        //(*head).next = newVal;
        head->next = newVal;
        return temp;
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
    new_head = (struct Node *)malloc(sizeof(struct Node));

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
        new_head = head->next;
        free(head);
        return new_head;
    }
}

/* DELETE LAST */
struct Node *delete_last(struct Node *head){
    struct Node *temp = head;
    /* if there is only one item in the list, remove it */
    if(head->next == NULL){
        free(head);
        return temp;
    }
    /* if there is more than one item in the list, remove the last one */
    else{
        while(head->next->next != NULL)
            head = head->next;
        head->next = NULL;
        head = head->next;
        free(head);
        return temp;
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

/* PRINT */
void printList(struct Node *head){
    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
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

    second->data = 2; //assign data to second node
    second->next = third;

    third->data = 3; //assign data to third node
    third->next = NULL;

    printList(head);
    printf("\n");
    printf("Second List(Adding 4,5,6,7): ");
    head = add(7,head);
    head = add(6,head);
    head = add(5,head);
    head = add(4,head);
    printList(head);
    printf("\n");
    printf("Sorting : ");
    bubbleSort(head);
    printList(head);
    printf("\n");
    




    return 0;
}

