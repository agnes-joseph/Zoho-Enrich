#include<stdio.h>

struct Node
{
    int x;
    struct Node *next;
};


struct Node* insert(int x,struct Node *head)
{
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->x=x;
    p->next=head;
    return p;
}

struct Node* reverse(struct Node *q)
{
    struct Node *p,*temp;
    p=NULL;
    while(q!=NULL)
    {
        temp = q->next;
        q->next = p;
        p=q;
        q=temp;
    }
    return p;
}

struct Node* add(struct Node* p,struct Node* q)
{
    int carry=0,sum;
    struct Node* h3=NULL;

    while(p!=NULL && q!=NULL)
    {
        sum = p->x + q->x + carry;
        carry = (sum>9)?1:0;
        sum = sum%10;

        h3 = insert(sum,h3);
        p=p->next;
        q=q->next;
    }

    while(p!=NULL )
    {
        sum = p->x + carry;
        carry = (sum>9)?1:0;
        sum = sum%10;

        h3 = insert(sum,h3);
        p=p->next;
    }
    while(q!=NULL)
    {
        sum = q->x + carry;
        carry = (sum>9)?1:0;
        sum = sum%10;

        h3 = insert(sum,h3);
        q=q->next;
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
    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);
    h1=toLinklist(a,h1);
    h2=toLinklist(b,h2);

    printf("First num:\n");
    display(h1);
    printf("Second num:\n");
    display(h2);

    h1 = reverse(h1);
    h2 = reverse(h2);
    h3=add(h1,h2);

    printf("Sum:\n");
    display(h3);


}
