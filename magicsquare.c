#include<stdio.h>
void printArray(int **a,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
          printf(" %d\t",a[i][j]);
        }

        printf("\n");
    }
}

void magicSquare(int **a,int  n)
{
    int i = 0;
    int j = n/2;
    int x = 1;
    while(x<=(n*n))
    {
        a[i][j] = x;
        x++;

        int temp_i = i-1; //shifting up
        int temp_j = (j+1)% n; //shifting right

        if(temp_i<0) //i is out of bounds
            {
                temp_i = n-1;
            }

        if(a[temp_i][temp_j] != 0) // element already inserted
        {
            temp_i = (i+1)%n;
            temp_j = j;
        }
        i = temp_i;
        j = temp_j;
    }

    printArray(a,n);
}


void main()
{
    int **a,i,j,n,x=1;
    printf("Enter n: ");
    scanf("%d",&n);

    if(n%2 == 0)
    {
        printf("Enter only odd values for n");
        return;
    }

    a = (int*)malloc(n*sizeof(int**));
    for(i=0;i<n;i++)
    {
        a[i] = (int**) malloc(n*sizeof(int));
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
           {
               a[i][j] = 0;
           }
    }
    magicSquare(a,n);

}
