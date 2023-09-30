#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct Node // structure is having data and pointer of type structure 
// node only it is having a pointer of its own type so such a structure
// is called "Self-Referential Structure"
{
    int data;
    struct Node *next;
}*first=NULL, *second=NULL, *third=NULL; // this becomes a global pointer it can be directly acess or even I can pass it as paramter 

void create(int A[],int n) // in this function I will scan through this array and I will take one element at
// a time and I will create a node and form a linked list 
{
    int i;
    struct Node *t,*last; // t is a temperory pointer which will help us to create a new  node 
    // also take pointer named last that will be poinitng on last node this will help me to add a new node 
    // at the end of a linked list 
    first=(struct Node *) malloc(sizeof(struct Node)); // it will create a new node and first will be pointing on new node
    first->data=A[0];
    first->next=NULL; // because there is nothing beyond this 
    last=first; 
    // now 1st node is ready rest of the node i will create them using iterating through for loop
    for(i=1;i<n;i++)
    {
        t=(struct Node *) malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}

void create2(int A[],int n)
{
    int i;
    struct Node*t,*last;
    second=(struct Node *) malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++)
    {
        t=(struct Node *) malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}


void Display(struct Node *P)
{
    while(P!=NULL)
    {
        printf("%d ",P->data);
        P=P->next;
    }
}

int count(struct Node *P) // it is takinf Node pointer to the first Node it will count number of nodes in Linked List
{// The method is I should scan through the entire Linked List and count the NOdes until I reach the end of a Linked List 
    int c=0;
    while(P!=0)
    {
        P=P->next;// Move P to next Node 
        c++;
    }
    return c;
}

int Rcount(struct Node *p) // Recursive function for counting
{
 if(p!=NULL)
 return Rcount(p->next)+1;
 else
 return 0;
}

int Add(struct Node *P)
{
    int s=0;
    while (P!=0)
    {
        s=s+P->data;
        P=P->next;
    }

    return s;
    
}

int Rsum(struct Node *p) // Recursive function for finding sum of nodes in Linked List
{
 if(p==NULL)
 return 0;
 else
 return Rsum(p->next)+p->data;
}

int max(struct Node *P)
{
    int m=INT32_MIN;
    while(P)
    {
        if(P->data>m) m=P->data;
        P=P->next;
    }
    return m;
}

int RMax(struct Node *p) // Recursive Function to find Maximum in a Linked List 
{
 int x=0;

 if(p==0)
 return INT32_MIN;
 x=RMax(p->next);
 if(x>p->data)
 return x;
 else
 return p->data;
}

struct Node* LinearSearch(struct Node *p,int key)// Improved Linear Search 
{
    struct Node *q; // q is the tail pointer following pointer p 
    while (p!=NULL)
    {
        if(key==p->data)
        {
            q=p->next;
            p->next=first;
            first =p;
            return p;
        }

          q=p; // moving q to the p and then p to the next node 
          p=p->next;

    }

    return NULL;
  
}

void Insert(struct Node *p ,int index ,int x) // it is taking pointer and index and an element you wanna insert
{
    if(index<0 || index>count(p)) // if the given index is less than 0 or index less than number of element in a linked list 
    // then do nothing 
    {
        return;
    }

    struct Node *t;// creating node 
    t=(struct Node *)malloc((sizeof(struct Node)));
    t->data=x;// assinging data to this node 

    if(index==0) 
    {
        t->next=first;
        first=p;
    }

    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
    
}

void SortedInsert(struct Node *p,int x) //it will take p as a pointer to 1st node and an element we want to insert
{
    struct Node *t,*q=NULL; // q is a tailing pointer which is intially NULL
    t=(struct Node*) malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
     if(first == NULL)// if it is a first Node then pointer first will be NULL
    {
        first=t; // if it is very first NOde then I should make first point on t it is a first special case
    }  
    else // if it is not a first Nodewe have to insert it in a sorted position 
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        // again there is a special case the place where we stop is it a first Node then new node should be inserted in left hand size
        // I should insert a new node before first Node
        if(p==first)
        {
            t->next=first;
            first =t;

        } 

        else 
        {
            t->next=q->next;
            q->next=t;
        }
    }


}

int Delete(struct Node *p, int index) // taking pointer to the first node and an index you wanna delete 
{
    struct Node *q=NULL; // tailing pointer 
    int x=-1;
    // if index is less than 1 or greater than numbe ro elemnt in a linked list then its a invalid index
    if(index<1 || index>count(p)) return -1; // nort deleted index is invalid 
    else
    {
        if(index==1)
        {
            q=first;
            x=first->data;
            first=first->next;
            free (q);
            return x;
        }
        else
        {
            for(int i=0;i<index-1;i++)
            {
                q=p;
                p=p->next;

            }
            q->next=p->next;
            x=p->data;
            free(p);
            return x;
        }
    }
}

int isSorted(struct Node *p) // I have to traverse through this Linked List by using this pointer p
// and is any point the value is smaller than this previous value then I should stop 
{
    int x=-65536; // smallest 4bit number 

    while (p!=NULL)
    {
        if(p->data<x) 
        {
            return 0;
        }
        
            x=p->data;
            p=p->next;
    }

    return 1;
    
} 

void RemoveDuplicate(struct Node *p)
{
    struct Node *q=p->next; // in this function p is a tail pointer 
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }

        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

void Reverse1(struct Node *p)
{
    int *A,i;
    A=(int *) malloc(sizeof(int)*count(p));
    struct Node *q=p;
    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }// once all the elemnts copied on an Array 
    q=p; // then q should again start from 1st pointer p
    i--;

    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }

}

void Reverse2(struct Node *p) // using three pointers (sliding pointers)
{
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first =q;
}

void Reverse3(struct Node *q,struct Node *p) // reverse using Recursion
{
    if(p)
    {
        Reverse3(p,p->next);
        p->next=q;
    }
    else
        first=q;
}

void Merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;

        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;

        }
    }
        if(p)last->next=p;
        if(q)last->next=q;
}

int isLoop(struct Node *f) // check idf there is any loop in a linked list 
{
    struct Node *p,*q;
    p=q=f;

    do
    {
        p=p->next;
        q=q->next;// as q will take two steps 1st step is taken here 2nd step will be conditional
        q=q?q->next:q;// if q is not null then q wil move to next node otherwise it will remain there only

    } while (p && q && p!=q);

    if(p==q) return 1;
    else return 0;  

}


int main()
{
    int A[]={10,20,30,40,50}; // I want to create linked list using these elements 
    create(A,5);
    // I have created a Linked List now I will form loop in a linked list 
    // for that i will take two temperary pointer t1 and t2 two form a loop in a Linked list 
    struct Node *t1,*t2;
    t1=first->next->next; // t1 will be pointing on 30 
    t2=first->next->next->next->next; // t2 will be pointing on last node 
    t2->next=t1; // so it is having a loop
    printf("%d",isLoop(first));


   //cout<<"The maximum element in a Linked List is "<<max(first);

   //struct Node *temp;
   //temp=LinearSearch(first,12);
   //if(temp) cout<<"Key is found "<<temp->data;
   //else cout<<"Key is not found "<<endl;
   //Insert(first,4,499);
   //Display(first);
   //if(isSorted(first))
   //{
        //printf("Sorted");
  // }
   //else printf("Not Sorted");

    //return 0;
}