#include<stdio.h>
#include<stdlib.h>



struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;

int detectIntersectionImproved(NODE* head1, NODE* head2);
int getLength(NODE* head);


NODE* createNode(int data)
{
    NODE* recent;
    recent = (NODE*)malloc(sizeof(NODE));
    recent->data = data;
    recent->next = NULL;

    return recent;
}

NODE* intersection;

NODE* createList()
{

    NODE* head, *temp;

    temp = head = createNode(5);

    temp->next = createNode(6);
    temp = temp -> next;

    temp ->next = createNode(7);
    temp = temp -> next;

    intersection = createNode(8);
    temp -> next = intersection;
    temp = temp -> next;

    temp -> next = createNode(9);
    temp = temp -> next;

    temp -> next = createNode(10);
    temp = temp-> next;

    return head;

}



NODE* createList2()
{

    NODE* head, *temp;
    temp = head = createNode(1);

    temp->next = createNode(2);
    temp = temp -> next;

    temp ->next = createNode(3);
    temp = temp -> next;

    temp -> next = intersection;
    temp = temp -> next;



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



int getLength(NODE* head)
{
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

int detectIntersectionImproved(NODE* head1, NODE* head2)
{
    int length1 = getLength(head1);
    int length2 = getLength(head2);

    int d;

    if(length1 > length2)
    {
        d = length1 - length2;
        
    }
}
