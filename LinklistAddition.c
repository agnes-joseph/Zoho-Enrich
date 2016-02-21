#include<stdio.h>

struct Node
{
    int x;
    struct Node *next,*prev;
};


struct Node* insert(int x,struct Node *head)
{
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->x=x;
    p->prev=NULL;
    if(head!=NULL)
    {
        head->prev=p;
    }
    p->next=head;
    return p;
}

struct Node* lastNode(struct Node *p)
{
    while(p->next!=NULL )
    {
        p=p->next;
    }
    return p;
}

struct Node* add(struct Node* p,struct Node* q)
{
    int carry=0,sum;
    struct Node* h3=NULL;

    p=lastNode(p);
    q=lastNode(q);

    while(p!=NULL && q!=NULL)
    {
        sum = p->x + q->x + carry;
        carry = (sum>9)?1:0;
        sum = sum%10;

        h3 = insert(sum,h3);
        p=p->prev;
        q=q->prev;
    }

    while(p!=NULL )
    {
        sum = p->x + carry;
        carry = (sum>9)?1:0;
        sum = sum%10;

        h3 = insert(sum,h3);
        p=p->prev;
    }
    while(q!=NULL)
    {
        sum = q->x + carry;
        carry = (sum>9)?1:0;
        sum = sum%10;

        h3 = insert(sum,h3);
        q=q->prev;
    }
    if(carry)
    {
        h3=insert(1,h3);
    }
    return h3;
}


void display(struct Node* p)
{
    while(p!=NULL)
    {
        printf("%d->",p->x);
        p=p->next;
    }
    printf("NULL\n");
}

struct Node* toLinklist(int n,struct Node* head)
{
    while(n>0)
    {
        head = insert(n%10,head);
        n/=10;
    }
    return head;
}

int main()
{
    struct Node *h1=NULL,*h2=NULL,*h3=NULL;
    int a,b;
    printf("Enter two number");
    scanf("%d%d",&a,&b);
    h1=toLinklist(a,h1);
    h2=toLinklist(b,h2);
    h3=add(h1,h2);

    printf("First num:\n");
    display(h1);
    printf("Second num:\n");
    display(h2);
    printf("Sum:\n");
    display(h3);


}
