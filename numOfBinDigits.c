#include<stdio.h>

int numOfBinDigits(int n)
{
    int count =0;

    do
    {
        n=n>>1;
        count++;
    }
    while(n>0);

    return count;
}

int main()
{
    int n,count;
    printf("Enter a number: ");
    scanf("%d",&n);

    count = numOfBinDigits(n);

    printf("The number of bits required for %d is: %d",n,count);
}
