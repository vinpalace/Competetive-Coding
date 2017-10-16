#include<stdio.h>
#include<stdlib.h>



struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;

int detectIntersection(NODE* head1, NODE* head2);
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


int main()
{

    NODE *head1, *head2;

    head1 = createList();
    head2 = createList2();

    printList(head1);
    printf("\n");
    printList(head2);

    int value = detectIntersection(head1, head2);

    if(value == 1)
        printf("\nIntersection found\n");
    else
        printf("\nNot found\n");
    return 0;

}


int detectIntersection(NODE* head1, NODE* head2)
{


    int length1, length2;
    length1 = getLength(head1);
    length2 = getLength(head2);

    NODE* temp;
    temp = head2;
    int i, j;
    for(i = 0; i < length1; i++)
    {
        for(j = 0; j < length2; j++)
        {
            if(head1 == temp)
                return 1;

            temp = temp->next;


            if(temp == NULL)
                temp = head2;

        }

        head1 = head1 -> next;
        

    }

    return 0;
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
