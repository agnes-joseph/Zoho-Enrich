#include<stdio.h>

struct Student
{
    char name[25];
	int s_no;
	int marks[5];

}*stud;

void calcHighest(int i,int high[])
{
    int j;
    for(j=0;j<5;j++)
    {
        if(stud[high[j]].marks[j] < stud[i].marks[j])
            high[j] = i;
    }
}

void calcAvg(int n,float avg[])
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<5;j++)
        {
            avg[j]+=stud[i].marks[j];
        }
    }

     for(j=0;j<5;j++)
        {
            avg[j]/=n;
        }
}

int main()
{
    int n=-1,i;
    char c,heading[7][25];
    int high[6]={0};
    float avg[6]={0};
    FILE *fp;

    fp = fopen("student.csv","r");

    if (fp == NULL) {
		printf("File not found...");
		return 0;
	}

	while( (c=fgetc(fp)) != EOF)
	{
	    if(c == '\n')
            n++;
	}
	rewind(fp);

	stud = (struct Student*) malloc(sizeof(struct Student)*n);

	for(i=0;i<7;i++)
    {
        fscanf(fp,"%[^,\n],",heading[i]);
    }


    for(i=0;i<n;i++)
    {
        fscanf(fp, "%d,%[^,],%d,%d,%d,%d,%d", &stud[i].s_no, stud[i].name,
			&stud[i].marks[0], &stud[i].marks[1], &stud[i].marks[2],
			&stud[i].marks[3], &stud[i].marks[4]);

        calcHighest(i,high);
    }
    calcAvg(n,avg);

    printf("***Average marks in each subject***\n\n");
    for(i=0;i<5;i++)
    {
        printf("%s: %.2f\n",heading[i+2],avg[i]);
    }


    printf("\n\n***Highest marks in each subject***\n\n");
    for(i=0;i<5;i++)
    {
        printf("%s: \n    %s: %d\n",heading[i+2],stud[high[i]].name,stud[high[i]].marks[i]);
    }
}
