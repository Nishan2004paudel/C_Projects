#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;  

void push(int value){
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Stack Overflow (Memory allocation failed)\n");
    }
    newNode -> data =value;
    newNode -> next = top;
    top = newNode;

    printf("Pushed %d onto stack \n", value);
}

void pop(){
    if (top== NULL){
        printf("Stack Underflow (Empty Stack)\n");
        return;
    }
    struct Node *temp = top;
    int poppedValue = temp -> data;
    top = top -> next;
    free(temp);
    printf("Popped %d from stack\n", poppedValue);
}

void peek(){
    if (top == NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

void display(){
    if (top == NULL){
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack elements: \n");

    while (temp!= NULL){
        printf("%d\n", temp-> data);
        temp = temp-> next;
    }
}

int main(){
    int choice, value;
    do{
        printf("\n---------Stack Menu --------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1: 
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3: 
                peek();
                break;
            case 4: 
                display();
                break;
            case 5:
                printf("Exiting.........\n");
                break;
            default:
                printf("Invalid choice\n");

        }

    }while (choice !=5);
    return 0;
}


