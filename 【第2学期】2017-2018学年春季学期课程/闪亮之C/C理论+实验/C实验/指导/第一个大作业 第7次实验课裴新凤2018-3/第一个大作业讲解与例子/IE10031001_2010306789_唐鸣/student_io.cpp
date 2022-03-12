#include "my.h"
#include<stdlib.h>
#include<stdio.h>

void add(struct student *p,int n)
{
	FILE *fp;int i,k;
	struct student *q;
	fp=fopen("data","ab+");
	if(fp==NULL)
	{
	    printf("fopen is error\n");
        exit(0);
	}
    for(q=p;q<p+n;q++)
        fwrite(q,sizeof(struct student),1,fp);
    fseek(fp,0L,0);
    fread(&count,sizeof(int),1,fp);
    count=count+n;
    fseek(fp,0L,0);
    fwrite(&count,sizeof(int),1,fp);
    fclose(fp);
    }

void write (struct student *p,int n)
{
	FILE *fp;
	struct student *q;
	fp=fopen("data","wb");
	if(fp!=NULL)
	{
        count=n;
        if(fwrite(&count,sizeof(int),1,fp)!=1)
        {
            printf("write error\n");
            exit(0);
        }
        for(q=p;q<p+n;q++)
            if(fwrite(q,sizeof(struct student),1,fp)!=1)
            {
                printf("write error\n");
                exit(0);
            }
            fclose(fp);
    }
}

void read(struct student *p)
{
    FILE *fp;
	struct student *q;
	fp=fopen("data","rb");
	if(fp!=NULL)
	{//文件的第一个数据为文件中存放学生记录的个数,其后数据为学生记录
        if(fread(&count,sizeof(int),1,fp)!=1)
        {
            printf("read error\n");
            exit(0);
            }
        for(q=p;q<p+count;q++)
            if(fread(q,sizeof(struct student),1,fp)!=1)
                {
                    printf("read error\n");
                    exit(0);
                    }
    fclose(fp);
    }
}

void input(struct student  stu[],int n)
{
    int i;
    printf("请按提示输入学生的数据:姓名  序号(0)  学号  性别(f/m)  语文 英语  数学  物理\n");
    for(i=0;i<n;i++)
    {
        scanf("%s %d %d %c %f %f %f %f",
	   stu[i].name,&stu[i].xuhao,&stu[i].xuehao,&stu[i].sex,&stu[i].mark[0],&stu[i].mark[1],&stu[i].mark[2],&stu[i].mark[3]);
        getchar();
        }
    for(i=0;i<n;i++)
        stu[i].mark[4]=0;
}

void output(struct student *p)
{
    struct student *q;
    printf("姓名    序号    学号    性别    语文   英语    数学    物理    平均\n");
    for(q=p;q<p+count;q++)
            printf("%-8s%-8d%-8d%-8c%-8.1f%-8.1f%-8.1f%-8.1f%-8.1f\n",
                q->name,q->xuhao,q->xuehao,q->sex,q->mark[0],q->mark[1],q->mark[2],q->mark[3],q->mark[4]);
}



