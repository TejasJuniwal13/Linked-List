#include <stdio.h>
#include <stdlib.h>

//declare linked list 
typedef struct Node{
    int data;
   struct Node* next;
}Node;


//create node function
Node* createNode(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}



int count(Node* head){
    int count = 0;
    Node* current = head;

    while(current != NULL){
        count++;
        current = current->next;
    }

    return count;

}


void printList(Node* head){
    Node* current = head;

    while (current!=NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
    
}


int main(){

    Node* Head = createNode(10);
    Head->next = createNode(20);    
    Head->next->next = createNode(30);
    Head->next->next->next = createNode(40);
    Head->next->next->next->next = createNode(50);
    printList(Head);

    int total_Nodes = count(Head);
    printf("The total number of nodes in the linked list are %d \n", total_Nodes);

    return 0;
}