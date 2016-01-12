#include<stdio.h>
void subsets(int *arr,int n)
{
     int i,j;
     int count = 1 << n;
     for(i=0;i<count;i++)
     {
         int place=1;
         for(j=0;j<=place;j++)
         {
             if(place & i)
                {
                    printf(" %d ",arr[j]);
                }
             place = place<<1;
         }
         printf("\n");
     }
}

void main()
{
    int n,arr[10],i,j;
    int *a = arr;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    subsets(a,n);

}
