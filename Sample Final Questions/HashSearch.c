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


/* ADD LAST */
struct Node *add(int data , struct Node *head){
    if(head == NULL){
        struct Node * new_head = (struct Node *)malloc(sizeof(struct Node));
        new_head -> data = data;
        new_head -> next = NULL;
        return new_head;
    }
    else{
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        struct Node *temp = head;
        new_node -> data = data;
        new_node -> next = NULL;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        return head;
        
    }
}

void hash_add(int number , struct Node * array[]){
    array[number % 10] = add(number , array[number % 10]);
}

int hash_search(int number , struct Node * array[]){
    int hashed_number = number % 10;
    struct Node * head = array[hashed_number];
    return search(number , head);
}

int main(int argc, char const *argv[]){
    struct Node * array[11] = {NULL};
    hash_add(2,array);
    hash_add(22,array);
    hash_add(5,array);
    hash_add(6,array);
    hash_add(7,array);
    printf("%d\n" , array[2]->data);
    printf("%d\n" , array[2]->next->data);
    printf("%d\n" , array[5]->data);
    printf("%d\n" , hash_search(22,array));
    printf("%d\n" , hash_search(23,array));

    
    
    return 0;
}
