#include<stdio.h>
struct student{
	long num;
	char name[10];
	int age;
	double score[7];
	double sum;
	double ave;
}stu[10];

int main()
{
	int i,j,maxi=0;
    double s,max=0;
    for(i=0;i<10;i++)
    {
		scanf("%ld%s%d",&stu[i].num,stu[i].name,&stu[i].age);
		for(j=0;j<7;j++)scanf("%lf",&stu[i].score[j]);
	}

	for(i=0;i<10;i++)
	{
		s=0;
		for(j=0;j<7;j++)s=s+stu[i].score[j];
		stu[i].sum=s;
		stu[i].ave=s/7;
		if(s>max)
		{
			max=s;
			maxi=i;
        }
	}

	printf("%ld %s %d %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf\n",stu[maxi].num,stu[maxi].name,stu[maxi].age,stu[maxi].score[0],
		stu[maxi].score[1],stu[maxi].score[2],stu[maxi].score[3],stu[maxi].score[4],stu[maxi].score[5],stu[maxi].score[6]);
	return 0;
}
