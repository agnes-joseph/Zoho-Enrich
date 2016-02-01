#include<stdio.h>

double sqrt(int n,int acc)
{
    double est_x = n,est_y=1,i;
    double precision = 1;

    for(i=0;i<acc;i++)
    {
        precision /=10;
    }

    while(est_x - est_y > precision)
    {
        est_x = (est_x + est_y)/2;
        est_y = n/est_x;
    }
    return est_x;
}

int main()
{
    int n=27, acc=10;
    double sqroot_n;

    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Enter the precision of square root:");
    scanf("%d",&acc);

    sqroot_n = sqrt(n,acc);
    printf("Ans: %.*f",acc,sqroot_n);

}
