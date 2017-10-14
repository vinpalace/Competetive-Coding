#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;

NODE* createNode(int data)
{
    NODE* temp;

    temp = (NODE*)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

void printList(NODE* head)
{
    while(head != NULL)
    {
        printf("%d->", head->data);


        head = head->next;
    }
}

int getLength(NODE* head)
{
    int count = 0;
    while(head != NULL)
    {

        count++;
        head = head -> next;

    }
    return count;
}



int main()
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

    printList(head);

    int mid, i;

    mid = getLength(head) / 2;

    for(i = 0; i <= mid - 1; i++)
        head = head->next;

    printf("The middle element is %d", head -> data);
    return 0;
}
