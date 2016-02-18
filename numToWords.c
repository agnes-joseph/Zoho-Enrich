#include<stdio.h>

void main()
{
    char ones[][10]={"one","two","three","four","five","six","seven","eight","nine"};
    char tens[][10]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    char teens[][10]={"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    int n,digit[3]={-1,-1,-1},i=0;

    printf("Enter n: ");
    scanf("%d",&n);

    while(n>0)
    {
        digit[i++]=n%10;
        n=n/10;
    }

    //hundreds place
    if(digit[2] != -1)
    {
        printf("%s hundred",ones[digit[2]-1]);
        if(digit[1] != 0 || digit [0] != 0)
        {
            printf(" and ");
        }
        else
        {
            return;
        }
    }

    //tens place
    if(digit[1] != -1 && digit[1] != 0)
    {

        if(digit[1] != 1)
        {
            printf("%s ",tens[digit[1]-2]);
            if(digit[0]!= 0)
            {
                printf("%s ",ones[digit[0]-1]);
            }
        }
        else
        {
            if(digit[0] == 0)
            {
                printf("ten ");
            }
            else
                printf("%s ",teens[digit[0]-1]);
        }
    }
    else
    if(digit[0]!=0) //ones place
    {
        if(digit[0]!= -1 )
        {
                printf("%s",ones[digit[0]-1]);
        }
        else
        {
            printf("%s","zero");
        }

    }
}
