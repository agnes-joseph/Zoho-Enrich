#include<stdio.h>

char* findSubstring(char s[],int n,char substring[])
{
    int start=0,end,maxlen=1,curlen=1,max_start=0,max_end=0;
    int past_index,i;
    int visited[26];

    for(i=0;i<26;i++)
        visited[i]=-1;

    visited[s[start]-'a'] = 0;

    for(end=1;end<n;end++)
    {
        past_index = visited[s[end] - 'a'];
        if( past_index == -1 || start > past_index)
        {
            curlen++;
        }
        else
        {
            if(curlen>maxlen)
            {
                maxlen=curlen;
                max_start = start;
                max_end = end;
            }
            curlen = end - past_index;
            start = past_index + 1;
        }

        visited[s[end] - 'a'] = end;
    }

    if(curlen>maxlen)
    {
        maxlen=curlen;
        max_start = start;
        max_end = end;
    }

    for(i=0;i<maxlen;i++)
    {
        substring[i] = s[max_start++];
    }

    substring[i] = '\0';

    return maxlen;

}

int main()
{
    char *s,*substring;
    int len,n;
    printf("Enter length of string: ");
    scanf("%d",&n);

    s = (char* )malloc(sizeof(char)*n);
    substring = (char*)malloc(sizeof(char)*n);

    printf("Enter string: ");
    scanf("%s",s);

    len = findSubstring(s,n,substring);
    printf("Longest substring is: %s with length: %d \n",substring,len);
}
