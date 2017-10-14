#include<stdio.h>
#include<stdlib.h>



struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;


NODE* createNode(int data)
{
    NODE* recent;
    recent = (NODE*)malloc(sizeof(NODE));
    recent->data = data;
    recent->next = NULL;

    return recent;
}

NODE* createList()
{

    NODE* head, *temp;
    temp = head = createNode(5);

    temp->next = createNode(6);
    temp = temp -> next;

    temp ->next = createNode(7);
    temp = temp -> next;

    temp -> next = createNode(8);
    temp = temp -> next;

    temp -> next = createNode(9);
    temp = temp -> next;

    temp -> next = createNode(10);
    temp = temp-> next;

    return head;

}



void printList(NODE* head)
{
    while(head != NULL)
    {
        printf("%d->", head->data);


        head = head->next;
    }
}


NODE* reverseLinkedList(NODE* head)
{
    NODE* currentNode, *previousNode = NULL, *nextNode;
    currentNode = head; //mark current node

    while(currentNode != NULL)
    {
        nextNode = currentNode->next; //catch next node
        currentNode->next = previousNode; //reverse link for the current node
        previousNode = currentNode; //make the current node as previous node
        currentNode = nextNode; //move the current node forward
    }


    head = previousNode; //make the last node as head node now

    return head;
}

int main()
{
    NODE* head;
    head = createList();

    printList(head);

    printf("\n");

    head = reverseLinkedList(head);

    printList(head);

    return 0;
}
