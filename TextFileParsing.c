#include<stdio.h>
#include<string.h>
struct Word
{
    char s[100];
    int count;
};

int main()
{
    int unique_word_count=0,word_count=0,letter_count=0,sym_count=0;
    int letters[26]={0};
    struct Word *words[100];
    FILE *fp;

    fp = fopen("textfile.txt","r");
    parseFile(fp,&word_count,&unique_word_count,&letter_count,&sym_count,letters,words);
    printf("WORD COUNT: %d \nLETTER COUNT: %d  \nSYMBOLCOUNT: %d\n",word_count,letter_count,sym_count);
    printTopLetters(letters,&letter_count);
    printTopWords(words,unique_word_count);
    unusedLetters(letters);
    singleOccurances(words,unique_word_count);

}

void parseFile(FILE *fp,int* word_count,int *unique_word_count, int* letter_count,int* sym_count,int *letters, struct Word *words[])
{
    char c;
    char buffer[100];
    int i=0,j=0;

    while((c = tolower(fgetc(fp)))!= EOF)
    {
        if(c >= 'a' && c <= 'z')
        {
            buffer[i++] = c;
            letters[c - 'a']++;
            (*letter_count)++;

        }
        else
        {
            if(c == ' ' || c == '\n' || c == '\t')
            {
                if(i!=0)
                {
                    (*word_count)++;
                    buffer[i]='\0';
                    insert(buffer,words,unique_word_count);
                    i=0;
                }
            }
            else if(!(c >= '0' && c <= '9'))
            {
                if(i!=0)
                {
                    (*word_count)++;
                    buffer[i]='\0';
                    insert(buffer,words,unique_word_count);
                    i=0;
                }
                (*sym_count)++;
            }
        }
    }
    if(i != 0)
    {
        (*word_count)++;
        buffer[i]='\0';
        insert(buffer,words,unique_word_count);
    }
}


int insert(char *word, struct Word *words[],int *count)
{
    int i;
    for(i=0;i<*count;i++)
    {
        if(strcmp(word,words[i]->s) == 0)
        {
            words[i]->count++;
            break;
        }
    }
    if(i == *count)
    {
        struct Word *temp = (struct Word*) malloc(sizeof(struct Word));
        words[(*count)++] = temp;
        strcpy(words[i]->s,word);
        words[i]->count = 1;
    }
    return count;
}

void printTopLetters(int* letters,int count)
{
    int i,j,max,index;
    printf("\n\n----TOP 3 LETTERS---\n");
    if(count < 3)
    {
        printf("You have entered less than 3 letters!\n");
        return;
    }
    for(i=0;i<3;i++)
    {
        max=0;
        for(j=0;j<26;j++)
        {
            if(letters[j] > max)
            {
                index = j;
                max = letters[j];
            }
        }

        printf("%d. %c\n",i+1,index + 'a');
        letters[index] *= -1;

    }
    for(i=0;i<26;i++)
    {
        if(letters[i]<0)
        {
            letters[index] *= -1;
        }
    }
}

void printTopWords(struct Word *words[],int count)
{
int i,j,max,index;
    printf("\n\n----TOP 3 WORDS---\n");
    if(count < 3)
    {
        printf("You have entered less than 3 words!\n");
        return;
    }
    for(i=0;i<3;i++)
    {
        max=0;
        for(j=0;j<count;j++)
        {
            if(words[j]->count > max)
            {
                index = j;
                max = words[j]->count;
            }
        }

        printf("%d. %s\n",i+1,words[index]->s);
        words[index]->count *= -1;

    }

     for(j=0;j<count;j++)
        {
            if(words[j]->count < 0)
            {
                words[index]->count *= -1;
            }
        }
}

void unusedLetters(int letters[])
{
    int count =0,i;
    printf("\n\n----TOTAL UNUSED LETTERS---\n");
    for(i=0;i<26;i++)
    {
        if(letters[i] == 0)
        {
            printf("* %c\n",i+'a');
            count++;
        }
    }
    printf("total number of unused letters are %d",count);
}

void singleOccurances(struct Word* words[],int count)
{
    int c=0,i;
    printf("\n\n----SINGLE OCCURANCE WORDS----\n");
    for(i=0;i<count;i++)
    {
        if(words[i]->count == 1)
        {
            printf("* %s\n",words[i]->s);
            c++;
        }
    }
    printf("total number of words with a single occurance are %d",c);
}

