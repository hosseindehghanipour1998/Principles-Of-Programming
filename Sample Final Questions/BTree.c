#include <stdio.h>
#include <stdlib.h>

struct Node{
    int ldata;
    int bdata;
    struct Node * right;
    struct Node * middle;
    struct Node * left;
    int datacount;
};

struct Node * add(int data , struct Node *root){
    if(root == NULL){
        struct Node *new_root = (struct Node *)malloc(sizeof(struct Node));
        new_root->left = new_root->right = new_root->middle = NULL;
        new_root->ldata = data;
        new_root->bdata = 0;
        new_root->datacount = 1;
        return new_root;
    }
    if(root -> datacount < 2){
        if(root -> ldata < data)
            root->bdata = data;
        if(root -> ldata > data){
            root->bdata = root->ldata;
            root->ldata = data;
        }
        root->datacount = 2;
        return root;
    }
    if(data < root->ldata)
        root->left = add(data , root->left);
    else if(data > root->bdata)
        root->right = add(data , root->right);
    else
        root->middle = add(data , root->middle);
    return root;
}

int search(int data , struct Node *root){
    if(root == NULL)
        return 0;
    int retval;
    if(root->ldata == data || root->bdata == data)
        return 1;
    if(data > root->bdata)
        retval = search(data , root->right);
    else if(data < root->ldata)
        retval = search(data , root->left);
    else
        retval = search(data , root->middle);
    return retval;
}

void print_tree_h(struct Node *root , int space){
    if (root == NULL)
        return; 

    space += 10; 
    print_tree_h(root->right, space); 
    
    printf("\n");
    int i;
    for (i = 0; i < space; i++) 
        printf(" "); 
    printf("%d | %d\n", root->ldata , root->bdata);

    print_tree_h(root->middle, space);
    print_tree_h(root->left, space); 

}

void print_tree(struct Node *root){
    print_tree_h(root , 0);
}


int main(int argc, char const *argv[]){
    struct Node *root = NULL;
    root = add(10,root);
    root = add(20,root);
    root = add(21,root);
    root = add(30,root);
    root = add(8,root);
    root = add(7,root);
    root = add(11,root);
    root = add(15,root);
    root = add(31,root);
    root = add(32,root);
    root = add(22,root);
    root = add(23,root);
    print_tree(root);
    printf("\n%d\n" , root->ldata);
    int x = search(21 , root);
    int y = search(50 , root);
    printf("res : %d\n" , x);    
    printf("res : %d\n" , y);    
    return 0;
}
    


