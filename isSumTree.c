#include<stdio.h>

int sumTree(int i,int n,int *tree)
{
    if(i>=n)
    {
        return 0;
    }
    else
    {
        return tree[i] + sumTree(2*i+1,n,tree) + sumTree(2*i+2,n,tree);
    }
}

int isSumTree(int i,int n,int *tree)
{
    if(i>=n)
    {
        return 1;
    }
    if(sumTree(2*i+1,n,tree) + sumTree(2*i+2,n,tree) == tree[i])
    {
        return 1 * sumTree(2*i+1,n,tree) * sumTree(2*i+2,n,tree);
    }
    else
    {
        return 0;
    }
}

int main()
{
    int i,n;
    int tree[10];
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter the inorder traversal: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&tree[i]);
    }
    if(isSumTree(0,n,tree))
    {
        printf("The tree is a sum tree");
    }
    else
    {
        printf("The tree is not a sum tree");
    }

}
