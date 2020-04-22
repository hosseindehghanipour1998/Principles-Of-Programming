/* Doubly-Circular Linked List */


#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

/* 1.add */

struct Node *add(struct Node *head , int data){
    struct Node *new_node;
    struct Node *temp = head;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    if(head == NULL){
        head->data = data;
        head->next = head;
        head->prev = head;
        return head;
    }
    else{
        while(temp->next != head)
            temp = temp->next;
        new_node->data = data;
        new_node->next = head;
        new_node->prev = temp;
        temp->next = new_node;
        return head;
    }
}

/* 2.edit value of house nth*/
struct Node *edit(struct Node *head , int newValue , int house){
    int counter;
    struct Node *temp = head;
    for(counter = 0 ; counter != house ; counter++){
        temp = temp->next;
    }
    temp->data = newValue;
    return head;
}

/* 3.delete by index (delete at) */
struct Node *delete_by_index(struct Node *head,int index){
    int counter = 0;
    struct Node *temp = head;
    struct Node *prev_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *next_node = (struct Node *)malloc(sizeof(struct Node));

    while(counter != index){
        temp = temp->next;
        counter++;
    }
    prev_node = temp->prev;
    next_node = temp->next;
    prev_node->next = next_node;
    next_node->prev = prev_node;
    free(temp);
    return head;
}

/* 4.delete by data */
struct Node * delete_by_data(int data , struct Node *head){
    struct Node *temp = head;
    struct Node *prev_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *next_node = (struct Node *)malloc(sizeof(struct Node));
    if(head->next == head && head->data == data){
        head->data = '\0';
        head->next = head->prev = NULL;
        return head;
    }
    else{
        while(temp->next != head){
            if(temp->data == data){
                prev_node = temp->prev;
                next_node = temp->next;
                prev_node->next = next_node;
                next_node->prev = prev_node;
                free(temp);
                return head;
            }
            temp = temp->next;
        }
        if(temp->data == data){
                prev_node = temp->prev;
                next_node = temp->next;
                prev_node->next = next_node;
                next_node->prev = prev_node;
                free(temp);
                return head;
            }
        return head;
    }
}


/* 5.search */
int search(int number , struct Node *head){
    struct Node *temp = head;
    if(head == NULL){
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


/* 6.Insert At  */
struct Node *insert_at(struct Node *head , int newValue , int house){
    struct Node *temp = head;
    struct Node *new;
    struct Node *current_node;
    struct Node *next_node;
    new = (struct Node *)malloc(sizeof(struct Node));
    current_node = (struct Node *)malloc(sizeof(struct Node));
    next_node = (struct Node *)malloc(sizeof(struct Node));
    int counter;

    if(head == NULL){
        new->data = newValue;
        new->next = new;
        new->prev = new;
        return new;
    }

    if(house == 0){
        new->data = newValue;
        new->next = head;
        new->prev = head->prev;
        head->prev = new;
        return new;
    }
    else{
        for(counter = 0 ; counter < house - 1  ; counter++){
            head = head->next;
        }
        current_node = head;
        next_node = head->next;

        new->data = newValue;
        new->next = next_node;
        new->prev = current_node;
        head->next = new;
        next_node ->prev = new;
        return temp;
    }
    
}


/* 7.add_last */

struct Node *add_last(struct Node *head , int data){
    struct Node *new_node;
    struct Node *temp = head;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    if(head == NULL){
        head->data = data;
        head->next = head;
        head->prev = head;
        return head;
    }
    else{
        while(temp->next != head)
            temp = temp->next;
        new_node->data = data;
        new_node->next = head;
        new_node->prev = temp;
        temp->next = new_node;
        return head;
    }
}


/* 8.add_first */

struct Node *add_first(struct Node *head , int data){
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    if(head == NULL){
        head->data = data;
        head->next = head;
        head->prev = head;
        return head;
    }
    else{
        new_node->data = data;
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev = new_node;
        return new_node;
    }
}

/* 9.clear */
void delete_list(struct Node *head){
    struct Node *temp = head;
    while(temp->next != head){
        free(head);
        temp = temp->next;
    }
    free(head);
}

/* 10.get (return value of nth house) */
int get(int house , struct Node *head){
    struct Node *temp = head;
    int counter = 0;
    while(counter != house){
        temp = temp->next;
        counter++;
    }
    return temp->data;
}



/* 11.length */
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

/* 12.Bubble sort */
void bubbleSort(struct Node *head) { 
    int swapped = 1; 
    struct Node *temp1; 
    struct Node *temp2 = NULL; 
  
    /* Checking for empty list or only one element */
    if (head == NULL || head->next == head) 
        return; 
    while(swapped == 1){
        swapped = 0; 
        temp1 = head; 
        while (temp1->next != head) { 
            if (temp1->data > temp1->next->data) {  
                swap(temp1, temp1->next); 
                swapped = 1; 
            } 
            temp1 = temp1->next; 
        }
        temp2 = temp1; 
    } 
}

/* 13.print list */
void printList(struct Node *head){
    struct Node *temp = head;
    while (temp->next != head){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}


int main(int argc, char const *argv[]){
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    printf("First List: ");
    head->data = 1; 
    head->next = second; 
    head->prev = third; 

    second->data = 2; 
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = head;
    third->prev = second;

    printList(head);
    printf("\n");
    insert_at(head , 13 , 1);
    printList(head);
    printf("\n");
    insert_at(head , 55 , 2);
    printList(head);
    printf("\n");
    head = add(head , 10);
    printList(head);
    printf("\n");
    head = edit(head,77,3);
    printList(head);
    printf("\n");
    bubbleSort(head);
    printList(head);
    printf("\n TEST \n");
    return 0;
}
