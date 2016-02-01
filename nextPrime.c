#include<stdio.h>
#include<math.h>

int findNextPrime(int n)
{
    int i=n,j;
    int flag=0,prime=0;
    int max_factor = sqrt(n)+1;

    while(!prime)
    {
        i++;
        for(j=2;j<=max_factor;j++)
        {
            if(i%j == 0)
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            prime = i;
        }
        else
        {
            flag=0;
        }
    }
    return prime;

}

int main()
{
    int n,next_prime;
    printf("Enter a number: ");
    scanf("%d",&n);

    next_prime=findNextPrime(n);
    printf("%d",next_prime);
}
