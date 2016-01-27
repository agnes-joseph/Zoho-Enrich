#include<stdio.h>

void toBase(int n,int b)
{
    int res,i=0;
    char  stack[10];

    while(n>0)
    {
        res = n%b;

        if(res>9)
        {
            stack[i++] = 'A' + (res-10);
        }
        else
        {
            stack[i++] = res + '0';
        }

        n = n/b;
    }

    for(i--;i>=0;i--)
    {
        printf("%c",stack[i]);
    }
}

int main()
{
    int num,base;
    printf("Enter number: ");
    scanf("%d",&num);
    printf("Enter base: ");
    scanf("%d",&base);

    printf("Result: ");
    toBase(num,base);
}
