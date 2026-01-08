#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    
    return newNode;
}

struct Node* insert(struct Node *root, int value){
    if (root == NULL){
        return createNode(value);
    }

    if (value < root-> data){
        root -> left = insert(root-> left, value);
    }else if (value > root -> data){
        root -> right = insert(root-> right, value);
    }
    return root;
}

void inorder(struct Node *root){
    if (root == NULL){
        return ;
    }

    inorder(root -> left);
    printf("%d ", root-> data);
    inorder(root -> right);
}

void preorder(struct Node *root){
    if (root == NULL){
        return;
    }

    printf("%d ", root -> data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root){
    if (root == NULL){
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    printf("%d ", root -> data);
}
struct Node* search(struct Node *root, int key){
    if (root == NULL || root -> data == key){
        return root;
    }

    if (key < root -> data){
        return search(root -> left, key);
    }else {
        return search(root -> right, key);
    }
}

struct Node* findMin(struct Node *root){
    while (root -> left != NULL)
        root = root-> left;
    return root;
}

struct Node* deleteNode(struct Node *root, int key){
    if (root == NULL)
        return root;
    if (key< root-> data)
        root -> left = deleteNode(root->left, key);
    else if(key> root-> data)
        root ->right = deleteNode(root->right, key);
    else{
        if (root -> left == NULL){
            struct Node *temp = root -> right;
            free(root);
            return temp;
        }else if(root -> right == NULL){
            struct Node *temp = root -> left;
            free(root);
            return temp;
        }else{
            struct Node *temp = findMin(root -> right);
            root -> data = temp -> data;
            root -> right = deleteNode(root -> right, temp ->data);
        }
    }
    return root;
}




int main(){
    struct Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 7);

    int key =7;
    struct Node *found = search(root,key);
    if (found!= NULL){
        printf("\n Found %d in the BST\n", found-> data);
    }else {
        printf("\n%d not found in the BST\n",key);
    }

    printf("Inorder before deletion: ");
    inorder(root);

    root = deleteNode(root, 5);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    return 0;

}