#include<stdio.h>
#include<stdlib.h>
struct date
{
	int year;
	int month;
	int day;
};
struct student
{
	int num;
	char name[24];
	struct date birthday;
	char department[48];
	char major[32];
	double score[4];
	double sum;
	double average;
};
int main()
{
	FILE* fp = fopen("C:\\Users\\anmily\\Desktop\\tst.txt","r+");
	int num = 0,stu = 0;
	char temp = 0;
	fseek(fp,0,SEEK_SET);
	fscanf(fp,"stunum:%d",&num);
	scanf("%d",&stu);
	struct student* studata = malloc(sizeof(struct student)*stu);
	for (size_t j = 0; j < stu; j++)
	{
		studata[j].sum = 0;
		scanf("%d%c",&studata[j].num,&temp);
		scanf("%s",&studata[j].name[0]);
		scanf("%d-%d-%d",&studata[j].birthday.year,&studata[j].birthday.month,&studata[j].birthday.day);
		scanf("%s",&studata[j].department[0]);
		scanf("%c",&temp);
		scanf("%s",&studata[j].major[0]);
		for(int i=0;i<4;i++)
		{
			scanf("%lf",&studata[j].score[i]);
			studata[j].sum += studata[j].score[i];
		}
		studata[j].average = studata[j].sum / 4;
	}
	fseek(fp,0,SEEK_END);
	for (int i = 0; i < stu; i++)
	{
		fprintf(fp,"\n-------------------------------------------------\n",i+1+num);
		fprintf(fp,"numbur:%d\n",studata[i].num);
		fflush(fp);
		fprintf(fp,"name:%s\n",studata[i].name);
		fprintf(fp,"birthday:%d-%d-%d\n",studata[i].birthday.year,studata[i].birthday.month,studata[i].birthday.day);
		fprintf(fp,"deparment:%s\tmajor:%s\n",studata[i].department,studata[i].major);
		for (size_t j = 0; j < 4; j++)
		{
			fprintf(fp,"score%d:%.2lf\t",j+1,studata[i].score[j]);
		}
		fprintf(fp,"\naverage:%.2lf",studata[i].average);
	}
	fseek(fp,0,SEEK_SET);
	fprintf(fp,"stunum:%d\n",stu+num);
	fclose(fp);
}