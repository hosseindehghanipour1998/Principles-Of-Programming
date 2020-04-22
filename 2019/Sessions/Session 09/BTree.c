

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int lower_data;
    int bigger_data;
    struct Node *left;
    struct Node *right;
    struct Node *middle;
    int data_counter;
};

struct Node *insert(struct Node *root , int data){
    if(root == NULL){
        struct Node *new_root = (struct Node *)malloc(sizeof(struct Node));
        new_root->left = new_root->right = new_root->middle = NULL;
        new_root->lower_data = data;
        new_root->data_counter = 1;
        return new_root;
    }
    else if(root->data_counter < 2){
        if(data > root->lower_data)
            root->bigger_data = data;
        else if(data < root->lower_data){
            root->bigger_data = root->lower_data;
            root->lower_data = data;
        }
        root->data_counter = 2;
        return root;
    }
    else if (data > root->bigger_data)
        root->right = insert(root->right , data);
    else if(data > root->lower_data && data < root->bigger_data)
        root->middle = insert(root->middle , data);
    else if (data < root->lower_data)
        root->left = insert(root->left , data);
    return root;

}

void free_btree(struct Node *root){
    if(root == NULL)
        return;
    if(root->left == NULL &&  root->right == NULL && root->middle == NULL){
        free(root);
        return;
    }
    free_btree(root->left);
    free_btree(root->middle);
    free_btree(root->right);
    free(root);
}

void print_btree(struct Node *root){
    if(root == NULL)
        return;
    print_btree(root->left);
    printf("%d " , root->lower_data);
    print_btree(root->middle);
    if(root -> bigger_data != 0)
        printf("%d " , root->bigger_data);
    print_btree(root->right);
}

int search(struct Node *root , int data){
    if(root == NULL)
        return 0;
    int retval;
    if(data == root->bigger_data || data == root->lower_data)
        return 1;
    else if(data < root->lower_data)
        retval = search(root->left , data);
    else if(data > root->bigger_data)
        retval = search(root->right , data);
    else
        retval = search(root->middle , data);
    return retval;
}

int count(struct Node *root , int counter){
    if(root == NULL)
        return counter;
    if(root ->bigger_data == 0)
        counter += 1;
    else
        counter += 2;
    counter = count(root->left , counter);
    counter = count(root->middle , counter);
    counter = count(root->right , counter);
}

struct Node *find_for_delete(struct Node *root , int data){
    if(root == NULL)
        return 0;
    struct Node * retNode;
    if(data == root->bigger_data || data == root->lower_data)
        return root;
    else if(data < root->lower_data)
        retNode = find_for_delete(root->left , data);
    else if(data > root->bigger_data)
        retNode = find_for_delete(root->right , data);
    else
        retNode = find_for_delete(root->middle , data);
    return retNode;
}

int save(struct Node *root , int array[] , int i){
    if(root == NULL)
        return i;
    i = save(root->left,array,i);
    array[i] = root->lower_data;
    i++;
    i = save(root->middle,array,i);
    if(root -> bigger_data != 0){
        array[i] = root->bigger_data;
        i++;
    }
    i = save(root->right,array,i);
}

struct Node *delete(struct Node *root , int data){
    struct Node * node_to_delete = find_for_delete(root , data);
    int size = count(node_to_delete,0);
    int array[size];
    save(node_to_delete , array , 0);
    free_btree(node_to_delete);
    int i,j=0;
    int new_array[size - 1];
    for(i = 0 ; i<size ; i++){
        if(array[i] != data)
            new_array[j++] = array[i];
    }
    for(i=0 ; i<size ; i++){
        root = insert(root,new_array[i]);
    }
    return root;

}



int main(int argc, char const *argv[]){
    struct Node *root = NULL;
    root = insert(root , 30);
    root = insert(root , 50);
    root = insert(root , 10);
    root = insert(root , 25);
    root = insert(root , 60);
    root = insert(root , 70);
    root = insert(root , 35);
    root = insert(root , 45);
    root = insert(root , 65);


