#include<stdio.h>

char* toBase(int n,int b)
{
    int res,i=0;
    char  *stack = (char*) malloc(sizeof(char));

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

    stack[i--] = '\0';

    //reversing the stack
    int j=0;
    char temp;

    while(j<i)
    {
        temp = stack[i];
        stack[i] = stack[j];
        stack[j] = temp;
        i--;
        j++;
    }
    return stack;
}

int main()
{
    int num,base;
    char *result;
    printf("Enter number: ");
    scanf("%d",&num);
    printf("Enter base: ");
    scanf("%d",&base);

    if(base>36 || base<2)
    {
        printf("The base must be between 2 and 36 \n");
        return;
    }

    result = toBase(num,base);
    printf("Result: %s",result);
}
