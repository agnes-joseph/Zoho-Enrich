#include<stdio.h>

int binCoeff(int i, int j)
{
    if(i==j)
        return 1;
    else
        if(i==0 || j==0)
            return 0;
        else
            return binCoeff(i-1,j)+binCoeff(i-1,j-1);
}

void floydTri(int n)
{
    int x=1,i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
            printf(" %d ",x++);
        }
        printf("\n");
    }
}

void oddEven(int n)
{
    int odd=1,even=2,i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if((i%2) != 0) //odd row
            {
                printf(" %d ",odd);
                odd+=2;
            }
            else  //even row
                {
                     printf(" %d ",even);
                     even+=2;
                }
        }
        printf("\n");
    }

}

void pascalTri(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            printf(" %d ",binCoeff(i,j+1));
        }
        printf("\n");
    }

}

int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d",&n);

    printf("\n Floyd's Triangle: \n ");
    floydTri(n);

    printf("\n OddEven Triangle: \n ");
    oddEven(n);

    printf("\n Pascal Triangle: \n ");
    pascalTri(n);
}
