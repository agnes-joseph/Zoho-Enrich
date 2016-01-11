#include<stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int c,i,j,n;
    int **a;

    printf("Enter order of matrix: ", &n);
    scanf("%d",&n);

    a = (int **)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        a[i] = (int *)malloc(n*sizeof(int));
    }

    printf("Enter elements matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
            swap(&a[i][j],&a[j][i]);

    }

    printf("Transpose matrix: \n");
    printArray(a,n);

}

void printArray(int** arr, int n)
{
     int i,j;
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf(" %d ",arr[i][j]);

        printf("\n");
    }
}
