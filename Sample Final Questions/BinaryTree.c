/*

* Erfan Sabouri Shirazi
* 9532578

*/

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};


struct Node *add(int data , struct Node *root){
    if(root == NULL){
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->right = NULL;
        temp->left = NULL;
        return temp;
    }
    else if(data > root->data)
        root->right = add(data , root->right);
    else if(data < root->data)
        root->left = add(data , root->left);
    return root;
}

int search(int data , struct Node *root){
    if(root == NULL)
        return 0;
    int retval;
    if(data == root->data)
        return 1;
    if(data > root->data)
        retval = search(data , root->right);
    if(data < root->data)
        retval = search(data , root->left);
    return retval;
}

void clear_tree(struct Node *root){
    if(root == NULL)
        return;
    
    clear_tree(root->right);
    clear_tree(root->left);
    printf("\nDeleting node: %d", root->data); 
    free(root);
}


void print_tree_h(struct Node *root , int space){
    if (root == NULL)
        return; 

    space += 10; 
    print_tree_h(root->right, space); 

    printf("\n"); 
    int i;
    for (i = 2; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data);
    

    print_tree_h(root->left, space); 
}

void print_tree(struct Node *root) {
    print_tree_h(root , 0);
}



int save_children(struct Node *root , int children[],int k){
    if(root == NULL)
        return k ;
    k = save_children(root->right ,children , k);
    k = save_children(root->left ,children , k);
    children[k] = root->data;
    printf("%d\n" , root->data);
    printf("k = %d\n" , k);
    k++;
    return k;

}

int count_nodes(struct Node *root , int k){
    if(root == NULL)
        return k;
    k = count_nodes(root->right , k);
    k = count_nodes(root->left , k);
    k++;
    return k;
}

struct Node * delete(int data , struct Node *root){
    int count_of_children = count_nodes(root , 0);
    int children[count_of_children];
    save_children(root,children,0);
    int i , j = 0;
    int new_children[count_of_children - 1];
    for(i=0; i<count_of_children; i++){
        if(children[i] != data)
            new_children[j++] = children[i];
    }
    struct Node *new_root = NULL;
    while(j>0){
        new_root = add(new_children[j] , new_root);
        j--;
    }
    return new_root; 
}

int main(int argc, char const *argv[]){
    
    struct Node *root = NULL;

    root = add(100,root);
    root = add(110,root);
    root = add(80,root);
    root = add(50,root);
    root = add(160,root);
    root = add(30,root);

    print_tree(root);
    root = delete(50,root);
    print_tree(root);
    return 0;
}
