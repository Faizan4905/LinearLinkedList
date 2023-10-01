#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*Head;

void create(int A[],int n)
{
    int i;
    struct Node *t;
    Head=(struct Node*) malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;
    // so it is circular now and there is only single node 
    // rest of the node I will scan through this Array // and I will create nodes and go on linking them with this linked list 
    // for this I will take one more pointer last
    struct Node *last; // this will help me for inserting a new node always at the last 
    last = Head;
    for(i=1;i<n;i++)
    {
        t=(struct Node*) malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next; // because it is circular I can not use Null here 
        last->next=t;
        last=t;
    } 
      // so from this code linked list will be created and it will be a circular linked list
        // I made it circular by making Head pointing on itself  and every time i am trying to maintain same link with the help of last 
    
    
}

void Display(struct Node *h)
{
    do
    {
        printf("%d",h->data);
        h-h->next;
    } while (h!=Head);
    
}

void RDisplay(struct Node *h)
{
    static int flag=0;
    if(h!=Head || flag==0)
    {
        flag=1;
        printf("%d",h->data);
        RDisplay(h->next);
    }

    flag=0;

}

int Length(struct Node *p)
{
    int len=0;
    do
    {
        len++;
        p=p->next;
    } while (p!=Head);
    return len;
    
}

void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;
    if(index==0) // if a position is zero I have to insert a mew node before head node
    {
        t=(struct Node*) malloc(sizeof(struct Node));
        t->data=x;
        if(index<0 || index > Length(Head) )
        if(Head==NULL) // then it is a first NOde youre inserting
        {
            Head=t;
            Head->next=Head;
        }

        else
        {
            while(p->next!=Head) p=p->next;
            p->next=t;
            t->next=Head;
            Head=t;

        }

    }

    else
    {
        for(int i=0;i<index-1;i++) p=p->next;
        t=(struct Node *) malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        p->next=t;

    }

}

int Delete(struct Node *p,int index)
{
    struct Node*q;
    int i,x;

    if(index<0 || index>Length(Head))
        return -1;
    if(index==1)
    {
        while(p->next!=Head) p=p->next;
        x=Head->data;
        if(Head==p)
        {
            free(Head);
            Head=NULL;
        }
        else
        {
            p->next=Head->next;
            free(Head);
            Head=p->next;
        }
    }

    else
    {
        for(i=0;i<index-2;i++)
            p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[]={2,3,4,5,6};
    create(A,5);

    Insert(Head,0,10);
    Display(Head);
    return 0;
}