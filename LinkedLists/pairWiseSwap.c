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

/*
void pairWiseSwap(NODE* head)
{


    NODE* currentNode , *previousNode = NULL, *nextNode;
    currentNode = head;
    int k = 2;
    int count = 0;

    while(count < k && currentNode!=NULL)
    {
        nextNode = currentNode->next; //c = a, a = b, b = a ,a =c
        currentNode->next = previousNode;
        previousNode = currentNode;

        currentNode = nextNode;
        count++;

    }

    if(nextNode!=NULL)
        pairWiseSwap(head);

}
*/

void pairWiseSwap(NODE* head)
{
    NODE* temp , *temp2;

    temp = head->next;
    temp2 =temp->next;


    while(temp2!=NULL)
    {
        temp = head->next;
        temp2 =temp->next;

        temp->next = head;
        head->next = temp2;

        head = temp2;
    }

}


int main()
{
    NODE* head;

    head = createList();

    printList(head);
    printf("\n");

    pairWiseSwap(head);

    printList(head);

    return 0;
}
