#include<stdio.h>
#include<string.h>

struct Hashmap
{
    int count;
    char name[10];
    int id[10];
};

int main()
{
    struct Hashmap *hash[10];
    char s[100],last[10],first[10];
    int id,size=0,i,j,n;
    printf("Enter number of names: ");
    scanf("%d",&n);

    while(n--)
    {
        scanf("%d",&id);
        gets(s);
        int flag=0;

        for(i=1,j=0;s[i]!=' ' && s[i]!='.';i++,j++)
        {
            first[j]=s[i];
        }
        first[j]='\0';

        if(s[i]=='.')
        {
            flag=1;
        }

        for(i++,j=0;s[i]!='\0';i++,j++)
        {
            last[j]=s[i];
        }
        last[j]='\0';

        if(flag)
        {
            if(strlen(first)>strlen(last))
            {
                strcpy(s,first);
            }
            else
            {
                strcpy(s,last);
            }
        }
        else
        {
            strcpy(s,first);
        }

        for(i=0;i<size;i++)
        {
            if(strcmp(hash[i]->name,s) == 0)
            {
                break;
            }
        }

        if(i < size)
        {
            hash[i]->id[hash[i]->count++]=id;
        }
        else
        {
            struct Hashmap *temp = (struct Hashmap*)malloc(sizeof(struct Hashmap));
            strcpy(temp->name,s);
            temp->id[0] = id;
            temp->count = 1;
            hash[i]=temp;
            size++;
        }

    }

        for(i=0;i<size;i++)
        {
            printf("%s %d ",hash[i]->name,hash[i]->count);
            printf(" [");
            for(j=0;j<hash[i]->count;j++)
            {
                printf("%d,",hash[i]->id[j]);
            }
            printf("\b]\n");
        }



}
