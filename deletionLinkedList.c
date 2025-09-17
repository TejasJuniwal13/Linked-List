#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* create_Node(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* delete_beg(Node*start){
    Node* ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

Node* delete_end(Node*start){
    Node* ptr, *preptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = NULL;
    free(ptr);
    return start;
    
}


Node* delete_after(Node* start){
    Node* ptr, *preptr;
    
    int num;
    printf("enter the number before node\n");
    scanf("%d", &num);
    
    ptr = start;
    preptr=ptr;
    while (preptr->data != num)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;    

}

void print_list(Node* head){
    Node* current = head;

    while (current!=NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
    
}

void free_list(Node* head){
    Node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){

    Node* Head = create_Node(10);
    Head->next = create_Node(20);
    Head->next->next = create_Node(30);
    Head->next->next->next = create_Node(40);
    Head->next->next->next->next = create_Node(50);

    printf("Deletion at beginnning\n");
    Head = delete_beg(Head);

    printf("Deletion at ending\n");
    Head = delete_end(Head);

    printf("Deletion after the given num\n");
    Head = delete_after(Head);

    print_list(Head);
    free_list(Head);

    return 0;
}