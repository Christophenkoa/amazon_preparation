// Online C compiler to run C program online
#include <stdio.h>

struct Node {
    int data;
    struct Node *next ;
    //struct Node *prev ;
};

struct Node *head;
void InsertBeg(int x);
void InsertEnd(int x);
void InsertAt(int pos, int x);
void Print();
void Delete(int pos);
void RevList_Iter();
void RevList_Recur();
int main() {
    // Write C code here
    head = NULL;
    InsertBeg(1);
    InsertBeg(4);
    InsertBeg(6);
    
    Print();
    
    InsertEnd(3);
    
    Print();
    
    InsertAt(1,9);
    
    Print();
    
    Delete(2);
    
    Print();
    
    RevList_Iter();
    
    Print();
    
    RevList_Recur(head);
    
    Print();
    
    return 0;
}

void InsertBeg(int x) {
    struct Node *newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void InsertEnd(int x) {
    struct Node *temp = head;
    struct Node *newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    
    if(head == NULL){
        head = temp;
        return;
    }
    while(temp->next) {
        temp = temp->next;
    }
    
    temp->next = newNode;
}

void InsertAt(int pos, int x) {
    struct Node *current = head;
    struct Node *next = NULL;
    struct Node *newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode->data = x;
    
    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    
    int i;
    
    for(i = 1; i<pos-1; i++) {
        if(current == NULL)
            return;
        current = current->next;
    }
    next = current->next;
    newNode->next = next;
    current->next = newNode;
}

void Delete(int pos){
    if(head == NULL)
        return;
        
    struct Node *current = head; 
    struct Node *next = NULL;
    struct Node *previous = NULL;
    
    if(pos == 1) {
        head = current->next;
        free(current);
    }else {
        int i;
        
        for(i=1; i<pos-1; i++) {
            if(current == NULL)
                return;
            current = current->next;
        }
        
        previous = current;
        current = current->next;
        next = current->next;
        
        previous->next = next;
        
        free(current);
    }
}

void Print() {
    struct Node *temp = head;
    printf("List is: ");
    while(temp) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    
    printf("\n");
}


void RevList_Iter(){
    if(head == NULL)
        return;
        
    struct Node *current = head; 
    struct Node *next = NULL;
    struct Node *previous = NULL; 
    
    while(current) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    
    head = previous;
}

void RevList_Recur(struct Node *p) {
    if(p == NULL)
        return;
    if(p->next == NULL) {
        head = p;
        return;
    }
    
    RevList_Recur(p->next);
    
    p->next->next = p;
    p->next = NULL;
    
}
