#include<stdio.h>
#include<string.h>

int compare(char a[],char b[])
{
    int i;
    for(i=0;a[i]!='\0'&&a[i]==b[i];i++);
    if(a[i]>b[i])
        return 1;
    else
        return 0;
}
int main()
{
    char a[10][10]={"1","10","99","910","11"};
    int i=0,j,n;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strlen(a[i])>=strlen(a[j]))
            {
                if(strlen(a[i]) == strlen(a[j]))
                {
                    int flag = compare(a[i],a[j]);
                    if(flag == 0)
                    {
                        continue;
                    }
                }
                char temp[10];
                strcpy(temp,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],temp);

            }
        }
    }

    printf("Sorted array: \n");
    for(i=0;i<n;i++)
    {
        printf("%s\t",a[i]);
    }
}
