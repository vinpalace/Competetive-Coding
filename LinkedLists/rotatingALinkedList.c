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


NODE* rotateLinkedList(NODE *head, int k)
{
    if(k == 0)
    return head;

    NODE* current = head;

    int count = 1;

    while(count < k && current != NULL)
    {
        current = current -> next;
        count++;
    }

    if(current == NULL)
        return head;


    NODE* kthNode = current;

    while(current->next != NULL)
        current = current->next;


    current->next = head;


    head = kthNode->next;

    kthNode->next = NULL;

    return head;
}


int main()
{

    NODE* head;

    head = createList();

    printList(head);

    printf("\n");

    head = rotateLinkedList(head, 4);
    printList(head);

    return 0;
}
