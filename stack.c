#include <stdio.h>
#include <stdlib.h>


/*********************************
    Array implementation
*********************************/

#define MAX_SIZE 101

int top = -1;

int A[MAX_SIZE];

void Push(int x) {
    if(top == MAX_SIZE -1) {
        printf("Error: overflow \n");
        return;
    }

    A[++top] = x;
}

void Pop() {
    if(top == -1) {
        printf("There is no element to pop \n");
    }

    top --;
}

int Top() {
    if(top == -1) {
        printf("There stack is empty \n");
        return -1;
    }
    return A[top];
}

void Print() {
    int i;
    
    if(top == -1) {
        printf("The stack is empty \n");
        return;
    }

    printf("The stack is: ");
    for(i=0; i<= top; i++) {
        printf("%d ", A[i]);
    }

    printf("\n");
}


/*********************************
    Linked List implementation
*********************************/

struct Node {
    int data;
    struct Node *link;
};

struct Node* topL = NULL;

void PushL(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = topL;
    topL = temp;
}

void PopL() {
    if(topL == NULL)
        return;
    struct Node* temp = topL;
    topL = temp->link;
    free(temp);
}

void PrintL() {
    if(topL == NULL) {
        printf("Empty stack \n");
        return;
    }

    struct Node *temp = topL;

    printf("The stack is: ");

    while(temp) {
        printf("%d ", temp->data);
        temp = temp->link;
    }

    printf("\n");
}

int main() {
    //Array
    printf("Array stack implementation \n\n");

    Print();

    Push(1);
    Push(10);

    Print();

    printf("The top element is: %d \n", Top());

    Pop();

    Print();


    // Linked List
    printf("\n\n Linked List stack implementation \n\n"); 

    PrintL();

    PushL(1);
    PushL(10);

    PrintL();

    //printf("The top element is: %d \n", topL->data);

    PopL();

    PrintL();
}
