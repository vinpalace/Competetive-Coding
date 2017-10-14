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

    NODE* bait;

    bait = createNode(7);

    temp ->next = bait;
    temp = temp -> next;

    temp -> next = createNode(8);
    temp = temp -> next;

    temp -> next = createNode(9);
    temp = temp -> next;

    temp -> next = createNode(10);
    temp = temp-> next;

    //temp->next = bait;

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

int detectLoop(NODE* head)
{
    NODE* walker, *jumper;

    walker = head;
    jumper = head;


    while(walker && jumper)
    {
        walker = walker -> next;
        jumper = jumper ->next -> next;

        if(walker == jumper)
            return 1;

    }

    return 0;
}



int main()
{
    NODE* head;

    head = createList();
    int boolean;

    boolean = detectLoop(head);

    if(boolean == 1)
        printf("\nLoop found\n");
    else
        printf("\nThis LL is safe\n");

}
