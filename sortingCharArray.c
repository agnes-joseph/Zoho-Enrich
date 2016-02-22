#include<stdio.h>

struct Node
{
    char a[10];
    struct node *next;
}*buckets[11]; //buckets for empty space and digits 0-9

void display(struct Node* p)
{
    while(p!=NULL)
    {
        printf("%s->",p->a);
        p=p->next;
    }
    printf("NULL\n\n");
}

void displayBuckets() 
{
    int i;
    for(i=0;i<11;i++)
    {
        display(buckets[i]);
    }
}

struct Node* insert(char *a,struct Node *head) //insert at the back of the linklist
{
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    strcpy(p->a,a);
    if(head==NULL){
    p->next=NULL;
    return p;
    }
    else
    {
        struct Node *q=head;
        while(q->next!=NULL)
        {
            q=q->next;

        }
        q->next=p;
        p->next=NULL;
        return head;
    }
}

void copyBuckets(char a[10][10]) //empty the buckets into array 
{
    int i,j=0;
    for(i=0;i<11;i++)
    {
        struct Node *p=buckets[i];
        while(p!=NULL)
        {
            strcpy(a[j],p->a);
            j++;
            p=p->next;
        }
        buckets[i]=NULL;
    }
}

int main()
{
    int i,j,t1,n,max_digits=0,len;
    char a[10][10];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
        len=strlen(a[i]);
        if(len>max_digits)
        {
            max_digits=len;
        }
    }

    for(j=1;j<=max_digits;j++)
    {
        for(i=0;i<n;i++)
        {
            len = strlen(a[i]);
            t1=(len-j>=0)? (a[i][len-j]-'0'+1) : 0; //choosing which bucket to insert into. 0 if empty space
            buckets[t1]=insert(a[i],buckets[t1]);
        }
        //displayBuckets();
        copyBuckets(a);
    }

    //displayBuckets();
    copyBuckets(a);
    for(i=0;i<n;i++)
    {
        printf("%s\t",a[i]);
    }

}
