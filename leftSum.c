#include<stdio.h>

struct Node
{
    int value;
    struct Node* left,*right;
};

struct Node * insert(int x,struct Node* head)
{
    if(head == NULL)
    {
        struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
        temp->value = x;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else if(head->value > x)
    {
        head->left = insert(x,head->left);
    }
    else
    {
        head->right = insert(x,head->right);
    }
    return head;

}

void postorder(struct Node* head)
{
    if (head == NULL)
    {
        return;
    }

    postorder(head->left);
    postorder(head->right);
    printf("%d  ",head->value);
}

int leftSum(struct Node* head)
{
    if(head == NULL)
    {
        return 0;
    }
    else
    {
        return head->value + leftSum(head->left);
    }
}

int main()
{
    int x,n;
    struct Node *head=NULL;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter the nodes: ");
    while(n--)
    {
        scanf("%d",&x);
        head = insert(x,head);
    }
    //postorder(head);
    int sum = leftSum(head);
    printf("The sum is %d",sum);

}
