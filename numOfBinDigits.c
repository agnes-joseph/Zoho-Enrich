#include<stdio.h>

int main()
{
    int n,count=0;
    printf("Enter a number: ");
    scanf("%d",&n);

    do
    {
        n=n>>1;
        count++;
    }
    while(n>0);

    printf("The number of bits required is: %d",count);
}
