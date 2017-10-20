#include<stdio.h>
#include<stdlib.h>



struct NODE{
    int data;
    struct NODE *next;
};
typedef struct NODE NODE;


NODE* createNODE(int data)
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
    temp = head = createNODE(5);

    temp->next = createNODE(4);
    temp = temp -> next;

    /*
    temp ->next = createNODE(7);
    temp = temp -> next;

    temp -> next = createNODE(8);
    temp = temp -> next;

    temp -> next = createNODE(9);
    temp = temp -> next;

    temp -> next = createNODE(10);
    temp = temp-> next;

    return head;
    */
    return head;
}


NODE* createlist2()
{
    NODE* head, *temp;
    temp = head = createNODE(5);

    temp->next = createNODE(4);
    temp = temp->next;

    temp->next = createNODE(3);
    temp = temp->next;

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
    while(head != NULL)
    {
    count++;
    head = head->next;
    }

    return count;
}

NODE*  addTwoLists(NODE* first, NODE* second){
  // Code here
  NODE* chead = 0, *ctemp;
  int carry = 0;
  NODE* temp1 = first;
  NODE* temp2 = second;
  int length1 = getLength(first);
  int length2 = getLength(second);

  while(temp1 || temp2)
  {
      int sum;

      int firstdata, seconddata;

      if(temp1 != NULL)
        firstdata = temp1->data;
      else
        firstdata = 0;

    if(temp2 != NULL)
        seconddata = temp2->data;
    else
        seconddata = 0;


        sum = firstdata + seconddata + carry;
        carry = 0;

        if(sum > 9)
        {
            carry = 1;
            sum = sum - 10;
        }

        if(chead != 0)
        {
            ctemp -> next = createNODE(sum);
            ctemp = ctemp->next;
        }
        else
        {
            chead = ctemp = createNODE(sum);
        }

        if(temp1!=NULL)
            temp1 = temp1->next;
        if(temp2!=NULL)
            temp2 = temp2->next;

        if(temp1 == NULL && temp2 == NULL)
            break;

  }
  return chead;

}
int main()
{

    NODE* head1, *head2, *chead;

    head2 = createList();
    head1 = createlist2();

    printList(head2);
    printf("\n");
    printList(head1);
    printf("\n");


    int length1 = getLength(head1);
    int length2 = getLength(head2);

    if(length1 > length2)
    {
        chead = addTwoLists(head1, head2);
    }
    else
        chead = addTwoLists(head2, head1);

    printList(chead);

    return 0;
}
