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
    int a[10][10],c,i,j,n;

    printf("Enter order of matrix: ", &n);
    scanf("%d",&n);

    printf("Enter elements matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(c=0; c<n/2 ;c++) //looping until the middle element
    {
        j=c;
        for(i=c+1; i<n-c; i++)  //swapping elements of left column and top row
            swap(&a[i][j],&a[j][i]);

        i=n-c-1;
        for(j=c+1; j<n-c; j++) //swapping elements of bottom row and right column
            swap(&a[i][j],&a[j][i]);

    }

    printf("Transpose matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf(" %d ",a[i][j]);

        printf("\n");
    }
}
