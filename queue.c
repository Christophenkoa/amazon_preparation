#include <stdio.h>
#include <stdlib.h>

/*********************************
    Array implementation
*********************************/

#define MAX_SIZE 1000

int Queue[MAX_SIZE];
int rear = -1;
int front = -1;

int IsEmpty() {
    if(rear == -1 && front == -1)
        return 1;
    else
        return 0;
}

int IsFull() {
    if((rear + 1)% MAX_SIZE == front)
        return 1;
    else
        return 0;
}

void Enqueue(int x) {
    if(IsFull())
        return;

    if(front == -1)
        front ++;

    rear = (rear +1) % MAX_SIZE;
    Queue[rear] = x;
}

void Dequeue() {
    if(IsEmpty())
        return;

    if(front == rear){
        rear = front = -1;
        return;
    }

    front = (front + 1) % MAX_SIZE;
}

int Front() {
    if(IsEmpty()){
        printf("No front element in an empty queue\n");
        return -1;
    }
    return Queue[front];    
}

void Print() {

    if(IsEmpty()) {
        printf("Empty queue \n");
        return;
    }

    int i;

    printf("The Queue is : ");

    for(i = front; i != rear; i = (i+1) % MAX_SIZE) {
        printf("%d ", Queue[i]);
    }

    printf("%d\n", Queue[i]);
}



/*********************************
    Linked List implementation
*********************************/

//Enqueue will be performed at the end and Dequeue at the front to keep the time complexity at 1

struct Node {
    int data;
    struct Node *next;
};

struct Node* rearL = NULL;
struct Node* frontL = NULL;

int IsEmptyL() {
    if(rearL == NULL && frontL == NULL) {
        return 1;
    }

    return 0;
}

void EnqueueL(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if(rearL == NULL && frontL == NULL)
        rearL = frontL = newNode;
    else {
        rearL->next = newNode;
        rearL = newNode;
    }
}

void DequeueL() {
    if(IsEmptyL()) {
        printf("Queue is Empty, You can't dequeue \n");
        return;
    }

    struct Node *temp  = frontL;

    if(rearL == frontL )
        frontL = rearL = NULL;
    else {
        frontL = temp->next;
    }

    free(temp);
}

void PrintL() {
    if(frontL == NULL) {
        printf("Empty Queue \n");
        return;
    }

    struct Node *temp = frontL;

    printf("Queue is: ");

    while(frontL) {
        printf("%d ", frontL->data);
        frontL = frontL->next;
    }

    printf("\n");
}


int main() {
    //Array
    printf("Array queue implementation \n\n");

    Print();

    Enqueue(1);
    Enqueue(10);

    Print();

    printf("The top element is: %d \n", Front());

    Dequeue();

    Print();


    // Queue using Linked List 

     // Linked List
    printf("\n\n Linked List stack implementation \n\n"); 

    PrintL();

    EnqueueL(1);
    EnqueueL(18);

    PrintL();

    DequeueL();

    PrintL();
}
