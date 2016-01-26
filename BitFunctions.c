#include<stdio.h>
int printBin(int n);
int setBit(int n ,int bit);
int unsetBit(int n ,int bit);
int toggleBit(int n,int bit);
int toggleExcludeBit(int n,int bit);
int rotateLeft(int n);
int rotateRight(int n);

int main()
{
    int n,bit,result;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("Enter the bit index: ");
    scanf("%d",&bit);

    if(bit>7)
    {
        printf("Bit index cannot be greater than 7");
        return;
    }
    printf("\n\nGiven Number: %08d \t\tDecimal Equivalent: %d\n",printBin(n),n);

    result = setBit(n,bit);
    printf("Bit %d set to 1: %08d \tDecimal Equivalent: %d\n",bit,printBin(result),result);

    result = unsetBit(n,bit);
    printf("Bit %d set to 0: %08d \tDecimal Equivalent: %d\n",bit,printBin(result),result);

    result = toggleBit(n,bit);
    printf("Toggling Bit %d : %08d \tDecimal Equivalent: %d\n",bit,printBin(result),result);

    result = toggleExcludeBit(n,bit);
    printf("Toggling exceptBit%d: %08d \tDecimal Equivalent: %d\n",bit,printBin(result),result);

    result = rotateLeft(n);
    printf("Rotating Left: %08d \tDecimal Equivalent: %d\n",printBin(result),result);

    result = rotateRight(n);
    printf("Rotating Right: %08d \tDecimal Equivalent: %d\n",printBin(result),result);

    result = swapNibbles(n);
    printf("Swapping nibbles: %08d \tDecimal Equivalent: %d\n",printBin(result),result);

}

int printBin(int n)
{
   if(n<=0)
   {
       return 0;
   }
   else
   {
       return (n%2) + (printBin(n/2))*10;
   }
}

int setBit(int n,int bit)
{
    int mask = 1<<bit;
    n = n|mask;
    return n;
}

int unsetBit(int n,int bit)
{
    int mask = 1<<bit;
    n = n& (~mask);
    return n;
}

int toggleBit(int n,int bit)
{
    int mask = 1<<bit;
    n = n^mask;
    return n;
}

int toggleExcludeBit(int n,int bit)
{
    int inverse,mask=1<<bit;
    inverse = n^(255);
    return toggleBit(inverse,bit);
}

int rotateLeft(int n)
{
    n = n<<1;
    n = n | (n >> 7);
    return (n & 255);
}

int rotateRight(int n)
{
    n = n>>1;
    n = n | ((n&1)<<7);
    return n;
}

int swapNibbles(int n)
{
    return ( ((n>>4) | (n<<4)) & 255 );
}
