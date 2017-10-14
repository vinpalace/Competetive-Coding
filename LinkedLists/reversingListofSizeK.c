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


NODE* reverseLinkedofSetSize(NODE* head, int k)
{

    NODE *nextNode, *previousNode = NULL, *currentNode = head;
    int count = 0;

    while(count < k && currentNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;

        currentNode = nextNode;

        count++;
    }

    if(nextNode != NULL)
        head->next = reverseLinkedofSetSize(nextNode, k);

    return previousNode;
}


int main()
{

    NODE* head;
    head = createList();

    printList(head);

    head = reverseLinkedofSetSize(head, 3);

    printf("\n");
    printList(head);

    return 0;
}
