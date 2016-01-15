#include<stdio.h>
#include<windows.h>

int main()
{
    char a[]="Happy Pongal!";
    int i;

    system("cls");
    for(i=0;a[i]!='\0';i++)
    {
        printf("%c",a[i]);
        Sleep(500);
    }
}
