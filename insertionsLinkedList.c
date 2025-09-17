#include <stdio.h>
#include <stdlib.h>


typedef struct Node{

    int data;
    struct Node* next;

}Node;

Node*create_Node(int data){
    Node* newnode = (Node*)malloc(sizeof(Node));
     if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

//insert at begin
Node* insert_beg(Node* start){
    int num;
    printf("Enter the data\n");
    scanf("%d", &num);
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data  = num;
    new_node->next = start;
    start = new_node;
    return start;
}

// insert at end
Node* insert_end(Node* start){
    Node *ptr;
    int num;
    printf("Enter the data\n");
    scanf("%d", &num);
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = num;
    new_node->next=  NULL;
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return start;
    
}

//insert after

Node* insert_before(Node* start){

    Node* ptr, *preptr;
    int place_num;
    printf("enter the num before to place\n");
    scanf("%d", &place_num);
    int num;
    printf("enter the data\n");
    scanf("%d", &num);

    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = num;

    ptr=start;
    preptr = ptr;
    while (ptr->data != place_num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = newnode;
    newnode->next = ptr;
    return start;
    

}

Node* insert_after(Node* start){
    Node* ptr, *preptr;
    int place_num_after;
    printf("enter the num after to place\n");
    scanf("%d", &place_num_after);
    int num;
    printf("enter the data\n");
    scanf("%d", &num);

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = num;

    ptr=start;
    preptr=ptr;

    while (preptr->data != place_num_after)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    
    return start;

}


void print_list(Node* head){
    Node* current = head;

    while (current != NULL)
    {
        printf("%d->",current->data);
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

   printf("Insertion at beginning\n");
   Head =  insert_beg(Head);

   printf("Insertion at ending\n");
   Head = insert_end(Head);

   printf("Insertion at before the given num\n");
   Head = insert_before(Head);

   printf("Insertion at after the given num\n");
   Head = insert_after(Head);

   print_list(Head);
   free_list(Head);


    return 0;
}